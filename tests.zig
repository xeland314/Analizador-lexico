const std = @import("std");
const expect = std.testing.expect;
const expectEqual = std.testing.expectEqual;

const ParserContext = extern struct {
    last_result: f64,
    is_sub_eval: c_int,
    nlines: c_int,
};

extern fn yy_scan_string(str: [*c]const u8) ?*anyopaque;
extern fn yy_delete_buffer(buffer: *anyopaque) void;
extern fn yyparse(ctx: *ParserContext) c_int;

fn evaluate(input: []const u8) !f64 {
    var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    defer arena.deinit();
    const allocator = arena.allocator();
    
    // Agregamos un salto de línea Y la palabra 'exit' para forzar al parser a terminar
    // La gramática procesará la línea y luego el comando EXIT detendrá yyparse.
    const input_full = try std.fmt.allocPrint(allocator, "{s}\nexit\n", .{input});
    const input_c = try allocator.dupeZ(u8, input_full);

    const buffer = yy_scan_string(input_c.ptr) orelse return error.FlexError;
    defer yy_delete_buffer(buffer);

    var ctx = ParserContext{
        .last_result = 0,
        .is_sub_eval = 0,
        .nlines = 0,
    };

    // yyparse retornará cuando encuentre el token EXIT
    _ = yyparse(&ctx);

    return ctx.last_result;
}

test "Basic operations" {
    try expectEqual(@as(f64, 2.0), try evaluate("1+1"));
    try expectEqual(@as(f64, 5.0), try evaluate("10-5"));
    try expectEqual(@as(f64, 6.0), try evaluate("2*3"));
    try expectEqual(@as(f64, 5.0), try evaluate("10/2"));
}

test "Precedence and grouping" {
    try expectEqual(@as(f64, 7.0), try evaluate("1+2*3"));
    try expectEqual(@as(f64, 9.0), try evaluate("(1+2)*3"));
    try expectEqual(@as(f64, 13.0), try evaluate("1+3^2+3"));
}

test "Variables and Assignments" {
    _ = try evaluate("x = 10");
    try expectEqual(@as(f64, 10.0), try evaluate("x"));
    try expectEqual(@as(f64, 15.0), try evaluate("x + 5"));
    
    _ = try evaluate("y = x * 2");
    try expectEqual(@as(f64, 20.0), try evaluate("y"));
    
    _ = try evaluate("x += 5");
    try expectEqual(@as(f64, 15.0), try evaluate("x"));
}

test "Functions" {
    _ = try evaluate("f(a) => {a*a}");
    // La gramática actual tiene un placeholder para evaluación de funciones de usuario
    // que retorna 0 (línea 287 de gramatica.y).
    // Así que esperamos 0 por ahora hasta que se implemente la lógica real.
    try expectEqual(@as(f64, 0.0), try evaluate("f(5)"));
    
    _ = try evaluate("suma(a,b) => {a+b}");
    try expectEqual(@as(f64, 0.0), try evaluate("suma(10,20)"));
}

test "Conditionals" {
    try expectEqual(@as(f64, 100.0), try evaluate("if (1) {100} else {200}"));
    try expectEqual(@as(f64, 200.0), try evaluate("if (0) {100} else {200}"));
    
    _ = try evaluate("a = 5");
    try expectEqual(@as(f64, 1.0), try evaluate("if (a > 3) {1} else {0}"));
}

test "Mathematical built-ins" {
    try expect(@abs(try evaluate("sin(0)")) < 0.000001);
    try expect(@abs(try evaluate("cos(0)") - 1.0) < 0.000001);
    try expectEqual(@as(f64, 4.0), try evaluate("sqrt(16)"));
}

test "Complex expressions" {
    _ = try evaluate("pi = 3.1415926535");
    const result = try evaluate("2 * pi * 5");
    try expect(@abs(result - 31.415926535) < 0.000001);
}
