/* setjmp.h stub para compilación WASM
 * Bison GLR usa setjmp/longjmp para manejo de errores.
 * En WASM, la propuesta de Exception Handling todavía no es estándar,
 * así que usamos un stub vacío / alternativa segura.
 */
#ifndef WASM_SETJMP_H
#define WASM_SETJMP_H

#include <stdint.h>

/* Implementación mínima para WASM sin excepciones */
typedef struct {
    uint32_t _jmp_buf[32];
} jmp_buf[1];

/* En WASM sin excepciones, setjmp siempre retorna 0 (ruta normal)
 * y longjmp no puede ejecutarse realmente — pero para GLR de bison
 * el longjmp solo se llama en errores de memoria internos del parser
 * que son extremadamente raros.
 */
#define setjmp(env)  (0)
#define longjmp(env, val)  __builtin_unreachable()

#endif /* WASM_SETJMP_H */
