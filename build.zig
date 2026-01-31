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
        .root_source_file = b.path("tokens.zig"),
        .target = target,
        .optimize = optimize,
    });
    tokens_obj.linkLibC();

    // 2. Creamos el ejecutable, pero sin un root_source_file de Zig
    const exe = b.addExecutable(.{
        .name = "calculadora",
        .target = target,
        .optimize = optimize,
    });

    // 3. Añadimos los archivos C y el objeto de Zig al ejecutable
    exe.addObject(tokens_obj);
    
    exe.addCSourceFiles(.{
        .files = &.{
            "y.tab.c",
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

    exe.linkLibC();
    
    // Configuraciones WASM si es necesario
    const t = target.result;
    if (t.cpu.arch == .wasm32) {
        exe.rdynamic = true;
        exe.entry = .disabled;
    }

    b.installArtifact(exe);
}
