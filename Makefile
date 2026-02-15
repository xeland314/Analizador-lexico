# Configuración de binarios y rutas
ZIG = /home/xeland314/mybin/zig-linux-x86_64-0.13.0/zig
EXEC = zig-out/bin/calculadora
SOURCES = lex.yy.c y.tab.c tokens.zig
LEXFILE = $(wildcard *.l)
YACC = bison
YACCFILE = $(wildcard *.y)

# Flags para Zig actuando como compilador de C
# Nota: -lc vincula la librería estándar de C
FLAGS = -pthread -lc -lm
YACCFLAGS = -d -v 

# Regla por defecto: Compilación nativa usando Zig
all: $(EXEC)

$(EXEC): $(LEXFILE) $(YACCFILE)
	lex $(LEXFILE)
	$(YACC) $(YACCFLAGS) $(YACCFILE)
	@mkdir -p zig-out/bin
	$(ZIG) build

# --- REGLAS ESPECIALES ---

# 1. Compilación con Zig Build System (Recomendado para WASM)
# Esto utiliza tu archivo build.zig para una gestión más compleja
wasm:
	lex $(LEXFILE)
	yacc $(YACCFLAGS) $(YACCFILE)
	$(ZIG) build -Doptimize=ReleaseSmall -Dtarget=wasm32-wasi

# 2. Instalación en /usr/local/bin 
# (Es una mejor práctica que /bin para software de usuario)
install: $(EXEC)
	sudo cp $(EXEC) /usr/local/bin/calculadora
	@echo "Instalado como 'calculadora' en /usr/local/bin"

# Limpieza profunda
clean:
	rm -rf zig-out/ .zig-cache/ lex.yy.c y.tab.c y.tab.h y.output
