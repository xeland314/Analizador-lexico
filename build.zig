const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{
        .default_target = .{
            .cpu_model = .native,
        },
    });

    const optimize = b.standardOptimizeOption(.{});

    // 1. Creamos un paso de compilación para el archivo Zig como un objeto
    const tokens_obj = b.addObject(.{
        .name = "tokens_logic",
        .root_module = b.createModule(.{
            .root_source_file = b.path("tokens.zig"),
            .target = target,
            .optimize = optimize,
        }),
    });
    tokens_obj.linkLibC();

    // 2. Creamos el ejecutable, pero sin un root_source_file de Zig
    const exe = b.addExecutable(.{
        .name = "calculadora",
        .root_module = b.createModule(.{
            .target = target,
            .optimize = optimize,
        }),
    });

    // Detectamos si el target es WASM para agregar flags específicos
    const t = target.result;
    const is_wasm = t.cpu.arch == .wasm32;

    // 3. Añadimos los archivos C y el objeto de Zig al ejecutable
    exe.addObject(tokens_obj);

    // Flags base de C
    const base_flags = &[_][]const u8{
        "-std=c99",
        "-Wno-everything",
        "-D_USE_MATH_DEFINES",
        "-DEINTR=4",
    };

    if (is_wasm) {
        // En WASM, bison genera setjmp.h que requiere la propuesta de Exception Handling.
        // Usamos nuestro stub en wasm_compat/ que se incluye antes que el musl header.
        exe.addIncludePath(b.path("wasm_compat"));
        exe.addCSourceFiles(.{
            .files = &.{
                "gramatica.tab.c",
                "lex.yy.c",
                "funciones.c",
                "math_2.c",
            },
            .flags = &.{
                "-std=c99",
                "-Wno-everything",
                "-D_USE_MATH_DEFINES",
                "-DEINTR=4",
            },
        });
        exe.rdynamic = true;
        exe.entry = .disabled;
    } else {
        exe.addCSourceFiles(.{
            .files = &.{
                "gramatica.tab.c",
                "lex.yy.c",
                "funciones.c",
                "math_2.c",
            },
            .flags = base_flags,
        });
    }

    exe.linkLibC();

    b.installArtifact(exe);

    // 4. Paso de tests
    const exe_tests = b.addTest(.{
        .root_module = b.createModule(.{
            .root_source_file = b.path("tests.zig"),
            .target = target,
            .optimize = optimize,
        }),
    });
    exe_tests.linkLibC();
    exe_tests.addObject(tokens_obj);

    const test_flags = &[_][]const u8{
        "-std=c99",
        "-Wno-everything",
        "-D_USE_MATH_DEFINES",
        "-DEINTR=4",
        "-Dmain=__nomain__",
    };

    if (is_wasm) {
        exe_tests.addIncludePath(b.path("wasm_compat"));
        exe_tests.addCSourceFiles(.{
            .files = &.{
                "gramatica.tab.c",
                "lex.yy.c",
                "funciones.c",
                "math_2.c",
            },
            .flags = test_flags,
        });
    } else {
        exe_tests.addCSourceFiles(.{
            .files = &.{
                "gramatica.tab.c",
                "lex.yy.c",
                "funciones.c",
                "math_2.c",
            },
            .flags = test_flags,
        });
    }

    const run_exe_tests = b.addRunArtifact(exe_tests);
    const test_step = b.step("test", "Run unit tests");
    test_step.dependOn(&run_exe_tests.step);
}
