%code requires {
    typedef struct {
        double last_result;
        void* scanner;
        int is_sub_eval;
        int nlines;
    } ParserContext;

    typedef struct {
        double vals[10];
        char* names[10];
        int count;
    } CustomList;
}

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include "colores.h"
    #include "controladorDeTokens.h"
    #include "funciones.h"
    #include "math_2.h"
    #ifndef longitud
        #define longitud 256
    #endif
%}    

%glr-parser
%expect 38
%expect-rr 2
%pure-parser
%parse-param { ParserContext* ctx }
%parse-param { void* scanner }
%lex-param { void* scanner }

%union {
    double real;
    char* id;
    CustomList list;
}

%code {
    // Firma para pure-parser + lex-param: yylex(&yylval, scanner)
    int yylex(YYSTYPE* yylval, void* scanner);
    void yyerror(ParserContext* ctx, void* scanner, const char* s);
}

%token EXIT CONVERT_ALL TABLE PRINTL print ERROR HELP COMENTARIO
%token TKN_IF TKN_ELSE
%token <id> TKN_ID
%token <real> TKN_NUM
%token TKN_ARROW
%token <id> TKN_BODY
%token TKN_EQ TKN_NE TKN_LT TKN_LE TKN_GT TKN_GE
%token TKN_AND TKN_OR TKN_XOR TKN_NOR
%token TKN_SUM_ASSIGN TKN_RES_ASSIGN TKN_MUL_ASSIGN TKN_DIV_ASSIGN
%token DMAS DMENOS 
%token TKN_CBRT TKN_SQRT TKN_ABS
%token deg TKN_COS TKN_SEN TKN_TAN 
%token TKN_SEC TKN_CSC TKN_CTG 
%token TKN_ACOS TKN_ASEN TKN_ATAN TKN_ATAN2
%token TKN_COSH TKN_SENH TKN_TANH
%token TKN_LOG TKN_LOG10 TKN_EXP
%token BIN TRN CTN PTL SNR HPT OCT NNR HXD DEC ROM

%type <real> linea NumExpr Termino AsignacionDeVariable Bloque Sentencia
%type <list> ArgLista DefLista

%right  '=' TKN_SUM_ASSIGN TKN_RES_ASSIGN TKN_MUL_ASSIGN TKN_DIV_ASSIGN
%right  '?' ':'
%left   TKN_OR TKN_NOR
%left   TKN_XOR
%left   TKN_AND
%left   TKN_EQ TKN_NE
%left   TKN_LT TKN_LE TKN_GT TKN_GE
%left   '+' '-'
%left   '*' '/'
%left   '%' '!'
%right  '^' TKN_SQRT TKN_EXP TKN_LOG TKN_LOG10 TKN_LOG2 TKN_CBRT 
%left deg 
%right  TKN_ABS
%right  TKN_COS TKN_SEN TKN_TAN 
%right  TKN_COSH TKN_SENH TKN_TANH
%right  TKN_ACOSH TKN_ASENH TKN_ATANH
%right  TKN_ACOS TKN_ASEN TKN_ATAN TKN_ATAN2
%right  TKN_GAMMA TKN_HYPOT
%right  UNMINUS UNPLUS LNOT
%nonassoc '(' ')'
%nonassoc '[' ']'
%nonassoc '{' '}'
%right    '|' 

%%

linea
    :   linea AsignacionDeVariable '\n' { ctx->nlines++; }
    |   AsignacionDeVariable '\n'       { ctx->nlines++; }
    |   linea Comandos '\n'     { ctx->nlines++; }
    |   Comandos '\n'           { ctx->nlines++; }
    |   linea error '\n'                { ctx->nlines++; yyerrok; } 
    |   error '\n'                      { ctx->nlines++; yyerrok; }
    ;

Comandos
    :   EXIT        { exit(EXIT_SUCCESS); }
    |   ERROR       { printf("%sError léxico detectado%s\n", PROJO, NORMAL); }
    |   TABLE       { printTableValues(); }
    |   NumExpr     { 
            ctx->last_result = $1;
            if (!ctx->is_sub_eval) printf("%s\t>>\t%s%.16f%s\n", NAMARILLO, CAZUL, $1, NORMAL); 
        }
    |   print '(' NumExpr ')'  { 
            ctx->last_result = $3;
            if (!ctx->is_sub_eval) printf("%s\t>>\t%s%.16f%s\n", NAMARILLO, CAZUL, $3, NORMAL); 
        }
    |   HELP        { mostrarInfo(); }
    |   Conversion  {;}
    |   COMENTARIO  {;}
    |   PRINTL '(' ')' { printf("%s-------------------------------%s\n", HCELESTE, NORMAL); }
    ;

AsignacionDeVariable
    :   TKN_ID '=' NumExpr                  {
            agregarTokenValor($1,$3);
            $$=$3; ctx->last_result = $3;
            free($1);
        }
    |   TKN_ID TKN_SUM_ASSIGN NumExpr       {
            double actual = valorDelToken($1);
            double nuevo = actual + $3;
            agregarTokenValor($1, nuevo);
            $$=nuevo; ctx->last_result = nuevo;
            free($1);
        }
    |   TKN_ID '(' DefLista ')' TKN_ARROW TKN_BODY %dprec 2 {
            char buf[256] = "";
            for(int i=0; i<$3.count; i++) {
                strcat(buf, $3.names[i]);
                if(i < $3.count-1) strcat(buf, ",");
                free($3.names[i]);
            }
            agregarFuncion($1, buf, $6);
            printf("%sFunción registrada:%s %s(%s) => %s\n", NVERDE, NORMAL, $1, buf, $6);
            $$ = 0;
            free($1); free($6);
        }
    |   TKN_ID TKN_RES_ASSIGN NumExpr       {
            double actual = valorDelToken($1);
            double nuevo = actual - $3;
            agregarTokenValor($1, nuevo);
            $$=nuevo; ctx->last_result = nuevo;
            free($1);
        }
    |   TKN_ID TKN_MUL_ASSIGN NumExpr       {
            double actual = valorDelToken($1);
            double nuevo = actual * $3;
            agregarTokenValor($1, nuevo);
            $$=nuevo; ctx->last_result = nuevo;
            free($1);
        }
    |   TKN_ID TKN_DIV_ASSIGN NumExpr       {
            double actual = valorDelToken($1);
            double nuevo = actual / $3;
            agregarTokenValor($1, nuevo);
            $$=nuevo; ctx->last_result = nuevo;
            free($1);
        }
    ;

DefLista
    :   TKN_ID { 
            $$.names[0] = $1; 
            $$.count = 1; 
        }
    |   DefLista ',' TKN_ID {
            $$ = $1;
            if ($$.count < 10) {
                $$.names[$$.count] = $3;
                $$.count++;
            }
        }
    ;

ArgLista
    :   NumExpr { 
            $$.vals[0] = $1; 
            $$.count = 1; 
        }
    |   ArgLista ',' NumExpr {
            $$ = $1;
            if ($$.count < 10) {
                $$.vals[$$.count] = $3;
                $$.count++;
            }
        }
    ;

Termino 
    :   TKN_NUM             { $$ = $1; }
    |   TKN_ID              {
            $$ = valorDelToken($1);
            free($1);
        }
    ;

Conversion
    :   BIN '(' NumExpr ')' { toBin($3); }
    |   TRN '(' NumExpr ')' { toTrn($3); }
    |   CTN '(' NumExpr ')' { toCtn($3); }
    |   PTL '(' NumExpr ')' { toPtl($3); }
    |   SNR '(' NumExpr ')' { toSnr($3); }
    |   HPT '(' NumExpr ')' { toHpt($3); }
    |   OCT '(' NumExpr ')' { toOct($3); }
    |   NNR '(' NumExpr ')' { toNnr($3); }
    |   HXD '(' NumExpr ')' { toHxd($3); }
    |   DEC '(' NumExpr ')' { toDec($3); }
    |   ROM '(' NumExpr ')' { toRom($3); }
    |   CONVERT_ALL '(' NumExpr ')' { mostrarResultadoEnTodasLasBases($3); }
    ;

NumExpr   
    :   Termino                         { $$ = $1;      }
    |   '+' NumExpr %prec UNPLUS        { $$ = $2;      }
    |   '-' NumExpr %prec UNMINUS       { $$ = (-1)*$2; }
    |   Bloque                          { $$ = $1;      }
    |   TKN_IF '(' NumExpr ')' Bloque TKN_ELSE Bloque {
            $$ = ($3 != 0) ? $5 : $7;
        }
    |   TKN_IF '(' NumExpr ')' Bloque %dprec 1 {
            $$ = ($3 != 0) ? $5 : 0;
        }
    |   TKN_ID DMAS {
            double val = valorDelToken($1);
            agregarTokenValor($1, val + 1);
            $$ = val;
            free($1);
        }
    |   TKN_ID DMENOS {
            double val = valorDelToken($1);
            agregarTokenValor($1, val - 1);
            $$ = val;
            free($1);
        }
    |   DMAS TKN_ID %prec UNPLUS {
            double nuevoVal = valorDelToken($2) + 1;
            agregarTokenValor($2, nuevoVal);
            $$ = nuevoVal;
            free($2);
        }
    |   DMENOS TKN_ID %prec UNMINUS {
            double nuevoVal = valorDelToken($2) - 1;
            agregarTokenValor($2, nuevoVal);
            $$ = nuevoVal;
            free($2);
        }
    |   NumExpr '+' NumExpr             { $$ = $1 + $3; }
    |   NumExpr '-' NumExpr             { $$ = $1 - $3; }
    |   NumExpr '*' NumExpr             { $$ = $1 * $3; }
    |   NumExpr '/' NumExpr             { $$ = $1 / $3; }
    |   NumExpr TKN_EQ NumExpr          { $$ = ($1 == $3); }
    |   NumExpr TKN_NE NumExpr          { $$ = ($1 != $3); }
    |   NumExpr TKN_LT NumExpr          { $$ = ($1 < $3);  }
    |   NumExpr TKN_LE NumExpr          { $$ = ($1 <= $3); }
    |   NumExpr TKN_GT NumExpr          { $$ = ($1 > $3);  }
    |   NumExpr TKN_GE NumExpr          { $$ = ($1 >= $3); }
    |   NumExpr '?' NumExpr ':' NumExpr { $$ = ($1 != 0) ? $3 : $5; }
    |   NumExpr TKN_AND NumExpr         { $$ = (double)((int)$1 && (int)$3); }
    |   NumExpr TKN_OR  NumExpr         { $$ = (double)((int)$1 || (int)$3); }
    |   NumExpr TKN_XOR NumExpr         { $$ = (double)((int)$1 ^ (int)$3);  }
    |   NumExpr TKN_NOR NumExpr         { $$ = (double)!((int)$1 || (int)$3); }
    |   '!' NumExpr %prec LNOT          { $$ = (double)!((int)$2); }
    |   NumExpr '%' NumExpr             { $$ = fmod($1,$3);     }
    |   NumExpr '!'                     { $$ = factorial($1);   }
    |   NumExpr '^' NumExpr             { $$ = pow($1,$3);     }
    |   TKN_ABS '(' NumExpr ')'         { $$ = fabs($3); }
    |   '|' NumExpr '|'                 { $$ = fabs($2); }
    |   '(' NumExpr ')'                 { $$ = $2;  }
    |   '[' NumExpr ']'                 { $$ = $2;  }
    |   '{' NumExpr '}'                 { $$ = $2;  }
    |   TKN_COS     '(' NumExpr ')'     { $$ = cos($3);     }
    |   TKN_SEN     '(' NumExpr ')'     { $$ = sin($3);     }
    |   TKN_TAN     '(' NumExpr ')'     { $$ = tan($3);     }
    |   TKN_SEC     '(' NumExpr ')'     { $$ = 1/cos($3);   }
    |   TKN_CSC     '(' NumExpr ')'     { $$ = 1/sin($3);   }
    |   TKN_CTG     '(' NumExpr ')'     { $$ = 1/tan($3);   }
    |   TKN_ACOS    '(' NumExpr ')'     { $$ = acos($3);    }
    |   TKN_ASEN    '(' NumExpr ')'     { $$ = asin($3);    }
    |   TKN_ATAN    '(' NumExpr ')'     { $$ = atan($3);    }
    |   TKN_ATAN2   '(' NumExpr ',' NumExpr ')'   { $$ = atan2($3,$5); }
    |   TKN_COSH    '(' NumExpr ')'     { $$ = cosh($3); }
    |   TKN_SENH    '(' NumExpr ')'     { $$ = sinh($3); }
    |   TKN_TANH    '(' NumExpr ')'     { $$ = tanh($3); }
    |   TKN_ACOSH   '(' NumExpr ')'     { $$ = acoshF($3); }
    |   TKN_ASENH   '(' NumExpr ')'     { $$ = asenhF($3); }
    |   TKN_ATANH   '(' NumExpr ')'     { $$ = atanhF($3); }
    |   TKN_SQRT    '(' NumExpr ')'     { $$ = sqrtF($3); }
    |   TKN_CBRT    '(' NumExpr ')'     { $$ = cbrtF($3); }
    |   TKN_EXP     '(' NumExpr ')'     { $$ = exp($3); }
    |   TKN_LOG     '(' NumExpr ')'     { $$ = log($3); }
    |   TKN_LOG10   '(' NumExpr ')'     { $$ = log10($3); }
    |   TKN_LOG2    '(' NumExpr ')'     { $$ = log2F($3); }
    |   TKN_GAMMA   '(' NumExpr ')'     { $$ = gammaF($3); }
    |   TKN_HYPOT   '(' NumExpr ',' NumExpr ')' { $$ = hypotF($3,$5);}
    |   TKN_ID '(' ArgLista ')' %dprec 1 {
            const char* full_def = obtenerCuerpoFuncion($1);
            if (full_def) {
                $$ = evaluarCuerpoMultiparams($1, $3.vals, $3.count);
            } else {
                $$ = valorDelToken($1) * $3.vals[0];
            }
            free($1);
        }
    |   NumExpr     '|' NumExpr '|'     { $$ = $1 * fabs($3); }
    |   NumExpr     '(' NumExpr ')'     { $$ = $1 * $3; }
    |   NumExpr     '[' NumExpr ']'     { $$ = $1 * $3; }
    |   NumExpr     '{' NumExpr '}'     { $$ = $1 * $3; }
    ;

Bloque
    :   '{' ListaSentencias '}' { $$ = ctx->last_result; }
    ;

ListaSentencias
    :   Sentencia
    |   ListaSentencias ';' Sentencia
    |   ListaSentencias Sentencia
    ;

Sentencia
    :   AsignacionDeVariable { ctx->last_result = $1; $$ = $1; }
    |   NumExpr { ctx->last_result = $1; $$ = $1; }
    |   '\n' { ; }
    ;

%%

void yyerror(ParserContext* ctx, void* scanner, char const *s) { 
    fprintf(stderr, "%s>> Error de sintaxis: %s%s\n", PROJO, s, NORMAL); 
}

int main()
{
    setbuf(stdout, NULL);
    printf("\t\t%sRECONOCEDOR DE EXPRESIONES MATEMÁTICAS%s\n", SCELESTE, NORMAL);
    
    void* scanner;
    yylex_init(&scanner);
    yyset_in(stdin, scanner);
    
    ParserContext ctx;
    ctx.scanner = scanner;
    ctx.last_result = 0;
    ctx.is_sub_eval = 0;
    ctx.nlines = 0;

    yyparse(&ctx, scanner);
    
    printf("Se han analizado %s%d%s líneas.\n", NVERDE, ctx.nlines, NORMAL);
    yylex_destroy(scanner);
    return 0;
}
