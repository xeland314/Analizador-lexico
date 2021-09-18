exec = math_app 
SOURCES = $(wildcard *.c)
LEXFILE = $(wildcard *.l)
YACCFILE = $(wildcard *.y)
AFILES = $(wildcard gofuncs/*.a)

flags = -pthread -lfl -lm
yaccflags = -d -v 

$(exec): $(SOURCES)
	lex $(LEXFILE)
	yacc $(yaccflags) $(YACCFILE)
	gcc $(SOURCES) $(AFILES) $(flags) -o $(exec)
