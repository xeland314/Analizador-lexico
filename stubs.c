// stubs.c - Implementaciones mínimas para engañar al linker
#include <stddef.h>

void* malloc(size_t size) { return NULL; } // O usa un allocator simple
void free(void* ptr) {}
int printf(const char* format, ...) { return 0; }
int fprintf(void* stream, const char* format, ...) { return 0; }
void exit(int status) {}

// Si usas strings, añade estas o usa las de Zig
size_t strlen(const char* s) {
    size_t i = 0;
    while(s[i]) i++;
    return i;
}
