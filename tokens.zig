const std = @import("std");

// Usamos c_allocator directamente para evitar problemas de estado con el GPA
// y porque es más ligero para tu Core 2 Duo
const allocator = std.heap.c_allocator;

// Ya no la hacemos opcional, la inicializaremos mediante una función
var symbol_table: std.StringHashMap(f64) = undefined;
var initialized: bool = false;

fn getTable() *std.StringHashMap(f64) {
    if (!initialized) {
        symbol_table = std.StringHashMap(f64).init(allocator);
        initialized = true;
    }
    return &symbol_table;
}

export fn agregarTokenValor(token: [*c]const u8, valor: f64) callconv(.C) void {
    const table = getTable();
    const key = std.mem.span(token);
    
    // 1. Intentar obtener el puntero al valor existente para actualizarlo
    if (table.getPtr(key)) |v| {
        v.* = valor;
        return;
    }

    // 2. Si no existe, crear una copia persistente de la clave
    const owned_key = allocator.dupe(u8, key) catch return;
    table.put(owned_key, valor) catch {
        allocator.free(owned_key); // Evitar leak si falla el put
        return;
    };
}

export fn valorDelToken(token: [*c]const u8) callconv(.C) f64 {
    if (!initialized) return 0.0;
    const table = getTable();
    const key = std.mem.span(token);
    // Usamos get para buscar por contenido de string
    return table.get(key) orelse 0.0;
}

export fn printTableValues() callconv(.C) void {
    if (!initialized) {
        std.debug.print("Tabla vacía.\n", .{});
        return;
    }
    const table = getTable();
    var it = table.iterator();
    std.debug.print("\n--- Tabla de Símbolos (Zig) ---\n", .{});
    while (it.next()) |entry| {
        // Usamos {d} para decimales estándar o {d:.2} para solo 2 decimales
        std.debug.print("{s} = {d:.4}\n", .{ entry.key_ptr.*, entry.value_ptr.* });
    }
}
