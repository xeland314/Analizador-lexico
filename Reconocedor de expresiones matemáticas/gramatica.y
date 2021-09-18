%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include "colores.h"
    #include "controladorDeTokens.h"
    #include "funciones.h"
    #ifndef longitud
        #define longitud 256
    #endif // !longitud
    #include "gofuncs/math_2.h"
%}    
%{
    void yyerror(char* s);
    int yylex(void);
    extern char *yytext;
    extern FILE *yyin;
    extern int nlines; 
%}
%union {
    long double real;
    char id[256];
}
/* ESTADO INICIAL DE LA CALCULADORA */
%start linea
%type <real> linea NumExpr Termino 
%type <id>   AsignacionDeVariable
%token EXIT
%token CONVERT_ALL
%token TABLE PRINTL print
%token ERROR HELP COMENTARIO
/* TOKENS NUMERICOS */
%token <id> TKN_ID  
%token <real> TKN_NUM
/* Asignación de variables */
%token TKN_SUM_ASSIGN TKN_RES_ASSIGN TKN_MUL_ASSIGN TKN_DIV_ASSIGN
/* OPERACIONES BASICAS */
%token DMAS DMENOS 
%token TKN_CBRT TKN_SQRT TKN_ABS
/* FUNCIONES TRIGONOMETRICAS */
%token deg TKN_COS TKN_SEN TKN_TAN 
%token TKN_SEC TKN_CSC TKN_CTG 
%token TKN_ACOS TKN_ASEN TKN_ATAN TKN_ATAN2
/* FUNCIONES HIPERBOLICAS */
%token TKN_COSH TKN_SENH TKN_TANH
/* FUNCIONES EXPONENCIALES Y LOGARITMICAS */
%token TKN_LOG TKN_LOG10 TKN_EXP
/* CONVERSIONES */
%token BIN TRN CTN PTL SNR HPT OCT NNR HXD DEC ROM 
/*PRECEDENCIA DE LOS SIMBOLOS MATEMATICOS */
%right  '=' TKN_SUM_ASSIGN TKN_RES_ASSIGN TKN_MUL_ASSIGN TKN_DIV_ASSIGN
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
%right  UNMINUS UNPLUS
%nonassoc '(' ')'
%nonassoc '[' ']'
%nonassoc '{' '}'
%right    '|' 
%%
linea
    :   linea AsignacionDeVariable '\n' {;}
    |   AsignacionDeVariable '\n'       {;}
    |   linea Comandos '\n'     {;}
    |   Comandos '\n'           {;}
    ;
Comandos
    :   EXIT        { exit(EXIT_SUCCESS); }
    |   ERROR       { printf("%sError léxico detectado%s\n", PROJO, NORMAL); }
    |   TABLE       { printTableValues(); }
    |   NumExpr     { printf("%s\t>>\t%s%.16Lf%s\n", NAMARILLO, CAZUL, $1, NORMAL); }
    |   print '(' NumExpr ')'  { printf("%s\t>>\t%s%.16Lf%s\n", NAMARILLO, CAZUL, $3, NORMAL); }
    |   HELP        {;}
    |   Conversion  {;}
    |   COMENTARIO  {;}
    |   PRINTL '(' ')' { printf("%s-------------------------------%s\n", HCELESTE, NORMAL); }
    ;
AsignacionDeVariable
    :   TKN_ID '=' NumExpr                  { agregarTokenValor($1,$3); }
    |   TKN_ID TKN_SUM_ASSIGN NumExpr       { agregarTokenValor($1,valorDelToken($1)+$3); }
    |   TKN_ID TKN_RES_ASSIGN NumExpr       { agregarTokenValor($1,valorDelToken($1)-$3); }
    |   TKN_ID TKN_MUL_ASSIGN NumExpr       { agregarTokenValor($1,valorDelToken($1)*$3); }
    |   TKN_ID TKN_DIV_ASSIGN NumExpr       { agregarTokenValor($1,valorDelToken($1)/$3); }
    |   TKN_ID DMAS                         { agregarTokenValor($1,valorDelToken($1)+1);  }
    |   TKN_ID DMENOS                       { agregarTokenValor($1,valorDelToken($1)-1);  }
    ;
Termino 
    :   TKN_NUM             { $$ = $1; }
    |   TKN_ID              { $$ = valorDelToken($1); }
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
    |   DMENOS NumExpr %prec UNPLUS     { $$ = $2;      }
    |   DMAS NumExpr %prec UNMINUS      { $$ = $2;      }
    |   NumExpr '+' NumExpr             { $$ = $1 + $3; }
    |   NumExpr '-' NumExpr             { $$ = $1 - $3; }
    |   NumExpr '*' NumExpr             { $$ = $1 * $3; }
    |   NumExpr '/' NumExpr             { $$ = $1 / $3; }
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
    |   TKN_COS     '(' NumExpr deg ')' { $$ = cos($3*M_PI/180); }
    |   TKN_SEN     '(' NumExpr deg ')' { $$ = sin($3*M_PI/180); }
    |   TKN_TAN     '(' NumExpr deg ')' { $$ = tan($3*M_PI/180); }
    |   TKN_SEC     '(' NumExpr deg ')' { $$ = 1/cos($3*M_PI/180); }
    |   TKN_CSC     '(' NumExpr deg ')' { $$ = 1/sin($3*M_PI/180); }
    |   TKN_CTG     '(' NumExpr deg ')' { $$ = 1/tan($3*M_PI/180); }
    |   deg TKN_ACOS    '(' NumExpr ')' { $$ = acos($4)*180/M_PI; }
    |   deg TKN_ASEN    '(' NumExpr ')' { $$ = asin($4)*180/M_PI; }
    |   deg TKN_ATAN    '(' NumExpr ')' { $$ = atan($4)*180/M_PI; }
    |   deg TKN_ATAN2   '(' NumExpr ',' NumExpr ')'   { $$ = atan2($4,$6)*180/M_PI; }
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
    |   NumExpr     '|' NumExpr '|'     { $$ = $1 * fabs($3); }
    |   NumExpr     '(' NumExpr ')'     { $$ = $1 * $3; }
    |   NumExpr     '[' NumExpr ']'     { $$ = $1 * $3; }
    |   NumExpr     '{' NumExpr '}'     { $$ = $1 * $3; }
    ;
%%
void yyerror(char *s) { fprintf(stderr, "%s%s%s\n", PROJO, s, NORMAL); }
int main()
{
    config.cantidadDeTokens = 0;
    printf("\t\t%sRECONOCEDOR DE EXPRESIONES MATEMÁTICAS%s\n", SCELESTE, NORMAL);
    yyparse();
    printf("Se han analizado %s%d%s líneas.\n", NVERDE, nlines, NORMAL);
    return 0;
}