exec = math_app
SOURCES = $(wildcard *.c)
LEXFILE = $(wildcard *.l)
YACCFILE = $(wildcard *.y)
ZIG_FILES = stubs.c bridge.c

# Filtramos stubs.c para la compilación nativa (Linux)
SOURCES_NATIVE = $(filter-out $(ZIG_FILES), $(SOURCES))

flags = -pthread -lfl -lm
yaccflags = -d -v 

# Regla por defecto (Compilación nativa)
all: $(exec)

$(exec): $(SOURCES)
	lex $(LEXFILE)
	yacc $(yaccflags) $(YACCFILE)
	gcc $(SOURCES_NATIVE) $(flags) -o $(exec)

# --- NUEVAS REGLAS ---

# 1. Compilación con Zig (WASM)
# Nota: Esta regla asume que tienes un archivo build.zig configurado
wasm:
	lex $(LEXFILE)
	yacc $(yaccflags) $(YACCFILE)
	/home/xeland314/mybin/zig-linux-x86_64-0.13.0/zig build -Doptimize=ReleaseSmall -Dtarget=wasm32-wasi

# 2. Instalación en /bin
# Se usa sudo porque usualmente /bin requiere permisos de superusuario
install: $(exec)
	sudo cp $(exec) /bin/$(exec)
	@echo "Instalado en /bin/$(exec)"

# Limpieza de archivos generados
clean:
	rm -rf $(exec) lex.yy.c y.tab.c y.tab.h y.output .zig-cache/

