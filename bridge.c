// bridge.c
#include <stdio.h>
#include "y.tab.h" // El header que genera Bison

// Declaración de funciones de Flex
typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(const char *str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

// Variable para capturar el resultado del parser
long double ultimo_resultado = 0;

// Esta función será la que llamaremos desde JS
__attribute__((visibility("default")))
long double calcular_desde_js(const char* input) {
    YY_BUFFER_STATE bp = yy_scan_string(input);
    yyparse();
    yy_delete_buffer(bp);
    return ultimo_resultado;
}
