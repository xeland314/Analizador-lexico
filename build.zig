const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.resolveTargetQuery(.{
        .cpu_arch = .wasm32,
        .os_tag = .wasi, // Cambia .freestanding por .wasi
    });

    const optimize = b.standardOptimizeOption(.{});

    // Usamos addExecutable para evitar el error de dynamic linking
    const exe = b.addExecutable(.{
        .name = "calculadora",
        .target = target,
        .optimize = optimize,
    });

exe.addCSourceFiles(.{
        .files = &.{
            "y.tab.c",
            "lex.yy.c",
            "bridge.c",
            "funciones.c",
            "math_2.c",
        },
        .flags = &.{ 
            "-std=c99", 
            "-Wno-everything",
            "-D_USE_MATH_DEFINES", // Para activar M_PI y M_E
            "-DEINTR=4",           // Definimos EINTR con un valor cualquiera para satisfacer a Flex
        }, 
    });

    exe.linkLibC();
    
    // Esto es clave: le dice al linker que no elimine nuestras funciones 
    // aunque no se usen dentro de un "main" de C.
    exe.rdynamic = true;
    exe.entry = .disabled; // No tenemos un main() real

    b.installArtifact(exe);
}
