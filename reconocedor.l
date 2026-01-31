%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
    #include "info.h"
    #include "numeros.h"
    #include "colores.h"
    int nlines; 
%}
/* Inicialización de expresiones regulares */
ALFABETO    [a-zA-Z]
binChars    [0-1]
terChars    [0-2]
cuatChars   [0-3]
quinChars   [0-4]
senChars    [0-5]
hepChars    [0-6]
octChars    [0-7]
nonChars    [0-8]
hexChars    [0-9a-fA-F]
DIGITO      [0-9]
SIGNOS      [\-\+]
COMILLA     [\"]
/* Palabras resevadas */
PRINT       [Pp][Rr][Ii][Nn][Tt]
PRINTLINE   {PRINT}[Ll][Ii][Nn][Ee]
INFO        ([Ii][Nn][Ff][Oo])|([Hh][Ee][Ll][Pp])
convert     "convertir"|"convert"|"cambio_de_base"
tableValues "tabla_de_valores"|"registro_de_valores"
exit        ([eE][xX][iI][tT])|([Cc][Ll][Oo][Ss][Ee])|([Ee][Nn][Dd])
bin         [Bb][Ii][Nn]
trn         [Tt][Rr][Nn]
ctn         [Cc][Tt][Nn]
ptl         ([Pp][Tt][Ll]|[Qq][Uu][Ii][Nn]?)
snr         ([Ss][Nn][Rr])
hpt         ([Hh][Pp][Tt]|[Hh][Ee][Pp])      
oct         [Oo][Cc][Tt]
nnr         [Nn][Nn]([Rr]|[Ll])
hxd         ([Hh][Xx]([Ll]|[Dd])|[Hh][Ee][Xx])
dec         [Dd][Ee][Cc]
rom         [Rr][Oo][Mm]
/* Números en sistema decimal */
ENTERO      {DIGITO}+
FRACCION    {ENTERO}\.{DIGITO}+
REAL        ({ENTERO}|{FRACCION})[eE]{SIGNOS}?{ENTERO}
DECIMAL     {DIGITO}|{ENTERO}|{FRACCION}|{REAL}
/* Números en sistema binario */
binBasico           {binChars}+
binarioInt          {binBasico}
binarioFloat        {binarioInt}\.{binChars}+
binarios            {binBasico}|{binarioInt}|{binarioFloat}
BINARIO             [Bb]{COMILLA}{binarios}{COMILLA}
/* Números en sistema ternario */
terBasico           {terChars}+
ternarioInt         {terBasico}
ternarioFloat       {ternarioInt}\.{terChars}+
ternarios           {terBasico}|{ternarioInt}|{ternarioFloat}
TERNARIO            [Tt]{COMILLA}{ternarios}{COMILLA}
/* Números en sistema cuaternario */
cuatBasico          {cuatChars}+
cuaternarioInt      {cuatBasico}
cuaternarioFloat    {cuaternarioInt}\.{cuatChars}+
cuaternarios        {cuatBasico}|{cuaternarioInt}|{cuaternarioFloat}
CUATERNARIO         [Cc]{COMILLA}{cuaternarios}{COMILLA}
/* Números en sistema quinario */
quinBasico          {quinChars}+
quinarioInt         {quinBasico}
quinarioFloat       {quinarioInt}\.{quinChars}+
quinarios           {quinBasico}|{quinarioInt}|{quinarioFloat}
QUINARIO            ([Qq]|[Pp]){COMILLA}{quinarios}{COMILLA}
/* Números en sistema senario */
senBasico           {senChars}+
senarioInt          {senBasico}
senarioFloat        {senarioInt}\.{senChars}+
senarios            {senBasico}|{senarioInt}|{senarioFloat}
SENARIO             [Xx]{COMILLA}{senarios}{COMILLA}
/* Números en sistema heptal*/
hepBasico           {hepChars}+
heptalInt           {hepBasico}
heptalFloat         {heptalInt}\.{hepChars}+
heptales            {hepBasico}|{heptalInt}|{heptalFloat}
HEPTAL              [Ss]{COMILLA}{heptales}{COMILLA}
/* Números en sistema octal */
octalBasico         {octChars}+
octalInt            {octalBasico}
octalFloat          {octalInt}\.{octChars}+
octales             {octalBasico}|{octalInt}|{octalFloat}
OCTAL               [Oo]{COMILLA}{octales}{COMILLA}
/* Números en sistema nonal */
nonBasico           {nonChars}+
nonarioInt          {nonBasico}
nonarioFloat        {nonarioInt}\.{nonChars}+
nonarios            {nonBasico}|{nonarioInt}|{nonarioFloat}
NONARIO             [Nn]{COMILLA}{nonarios}{COMILLA}
/* Números en sistema hexadecimal */
hexBasico           {hexChars}+
hexInt              {hexBasico}
hexFloat            {hexInt}\.{hexChars}+
hexadecimales       {hexBasico}|{hexInt}|{hexFloat}
HEXADECIMAL         [Hh]{COMILLA}{hexadecimales}{COMILLA}
/* Números en romano */
romI    (I|i)
romV    (V|v)
romX    (X|x)
romL    (L|l)
romC    (C|c)
romD    (D|d)
romM    (M|m)
/* Extensión de los números romanos */
romN    (N|n)
romO    (O|o)
romP    (P|p)
romQ    (Q|q)
romR    (R|r)
romS    (S|s)
romT    (T|t)
romU    (U|u)
romW    (W|w)
romY    (Y|y)
/* Posiciones numéricas */
romCienMillones ({romY}{0,3})
romMillonDecena ({romU}{romY}|{romU}{romW}|{romW}?{romU}{0,3})
romMillones     ({romS}{romU}|{romS}{romT}|{romT}?{romS}{0,3})
romMilCentenas  ({romQ}{romS}|{romQ}{romR}|{romR}?{romQ}{0,3})
romMilDecenas   ({romO}{romQ}|{romO}{romP}|{romP}?{romO}{0,3})
romMillares     ({romM}{romO}|{romM}{romN}|{romN}?{romM}{0,3}) 
romCentenas     ({romC}{romM}|{romC}{romD}|{romD}?{romC}{0,3}) 
romDecenas      ({romX}{romC}|{romX}{romL}|{romL}?{romX}{0,3}) 
romUnidades     ({romI}{romX}|{romI}{romV}|{romV}?{romI}{0,3}) 
romMillon       {romCienMillones}{romMillonDecena}{romMillones}
romMil          {romMilCentenas}{romMilDecenas}{romMillares}
romano          {romCentenas}{romDecenas}{romUnidades}
ROMANO          (r|R){COMILLA}{romMillon}{romMil}{romano}{COMILLA}
/* Identificadores, etc. */
simbolos        "_"|"."
label           {DIGITO}+{ALFABETO}+{DIGITO}*
IDENTIFICADOR   {ALFABETO}+[a-zA-Z0-9_]*
ERROR           {label}|{simbolos}
/* FUNCIONES MATEMATICAS */
PI          [Pp][Ii]
EULER       [Ee][Uu][Ll][Ee][Rr]
ABS         [Aa][Bb][Ss]
SQRT        [Ss][Qq][Rr][Tt]
CBRT        [Cc][Bb][Rr][Tt]
COS         [Cc][Oo][Ss]
SEN         [Ss]([Ee]|[Ii])[Nn]
TAN         [Tt]([Aa][Nn]|[Gg])
SEC         [Ss][Ee][Cc]
CSC         [Cc][Oo]?[Ss][Ee]?[Cc]
CTG         [Cc][Oo]?[Tt][Aa]?([Gg]|[Nn])
ACOS        [Aa]([Rr][Cc])?{COS}
ASEN        [Aa]([Rr][Cc])?{SEN}
ATAN        [Aa]([Rr][Cc])?{TAN}
ATAN2       {ATAN}(2)
COSH        {COS}[Hh]
SENH        {SEN}[Hh]
TANH        {TAN}[Hh]
ACOSH       [Aa]([Rr][Cc])?{COS}[Hh]
ASENH       [Aa]([Rr][Cc])?{SEN}[Hh]
ATANH       [Aa]([Rr][Cc])?{TAN}[Hh]
HYPOT       [Hh]([Yy]|[Ii])[Pp][Oo][Tt]
LN          [Ll][Nn]
LOG10       [Ll][Oo][Gg](10)?
LOG2        [Ll][Oo][Gg](2)
EXP         [Ee][Xx][Pp]
GAMMA       [Gg][Aa][Mm]{1,2}[Aa]
/* Signos */
OPERADOR    (=|\+|\-|\*|\/|\^|%|"!"|",")
SUMAIGUAL   "+="
RESTAIGUAL  "-="
MULTIGUAL   "*="
DIVIGUAL    "/="
MASMAS      "++"
MENOSMENOS  "--"
AGRUPACION  "("|")"|"["|"]"|"{"|"}"|"|"
GRADOS      "º"|[Dd][Ee][Gg]
%option noyywrap
%option always-interactive
%%
"#"[^#\n]*"#"       { return COMENTARIO; } /* Esto descarta los comentarios */

    /* 1. OPERADORES COMPUESTOS PRIMERO */

{SUMAIGUAL}         { return TKN_SUM_ASSIGN;}
{RESTAIGUAL}        { return TKN_RES_ASSIGN;}
{MULTIGUAL}         { return TKN_MUL_ASSIGN;}
{DIVIGUAL}          { return TKN_DIV_ASSIGN;}
{MASMAS}            { return DMAS; }
{MENOSMENOS}        { return DMENOS; }

    /* 2. PALABRAS RESERVADAS */

{PRINT}             { return print; }
{PRINTLINE}         { return PRINTL; }
{convert}           { return CONVERT_ALL; }
{tableValues}       { return TABLE; }
{exit}              { return EXIT; }
{bin}               { return BIN; }
{trn}               { return TRN; }
{ctn}               { return CTN; }
{ptl}               { return PTL; }
{snr}               { return SNR; }
{hpt}               { return HPT; }
{oct}               { return OCT; }
{nnr}               { return NNR; }
{hxd}               { return HXD; }
{dec}               { return DEC; }
{rom}               { return ROM; }

    /* 3. NÚMEROS Y CONSTANTES */

{PI}                { yylval.real = M_PI; return TKN_NUM; }
{EULER}             { yylval.real = M_E; return TKN_NUM; }
{ABS}               { return TKN_ABS; }
{COS}               { return TKN_COS; }
{SEN}               { return TKN_SEN; }
{TAN}               { return TKN_TAN; }
{SEC}               { return TKN_SEC; }
{CSC}               { return TKN_CSC; }
{CTG}               { return TKN_CTG; }
{COSH}              { return TKN_COSH; }
{SENH}              { return TKN_SENH; }
{TANH}              { return TKN_TANH; }
{ACOSH}             { return TKN_ACOSH; }
{ASENH}             { return TKN_ASENH; }
{ATANH}             { return TKN_ATANH; }
{HYPOT}             { return TKN_HYPOT; }
{ACOS}              { return TKN_ACOS; }
{ASEN}              { return TKN_ASEN; }
{ATAN}              { return TKN_ATAN; }
{ATAN2}             { return TKN_ATAN2; }
{EXP}               { return TKN_EXP; }
{LOG10}             { return TKN_LOG10; }
{LOG2}              { return TKN_LOG2; }
{LN}                { return TKN_LOG; }
{SQRT}              { return TKN_SQRT; }
{CBRT}              { return TKN_CBRT; }
{GAMMA}             { return TKN_GAMMA; }
{INFO}              { mostrarInfo(); return HELP; }
{DECIMAL}           { decToDec(yytext); yylval.real = decimal.representacionNumerica; return TKN_NUM; }
{BINARIO}           { binToDec(yytext); yylval.real = binario.representacionNumerica; return TKN_NUM;}
{TERNARIO}          { trnToDec(yytext); yylval.real = ternario.representacionNumerica; return TKN_NUM; }
{CUATERNARIO}       { ctnToDec(yytext); yylval.real = cuaternario.representacionNumerica; return TKN_NUM;}
{QUINARIO}          { ptlToDec(yytext); yylval.real = quinario.representacionNumerica; return TKN_NUM;}
{SENARIO}           { snrToDec(yytext); yylval.real = senario.representacionNumerica; return TKN_NUM;}
{HEPTAL}            { hptToDec(yytext); yylval.real = heptal.representacionNumerica; return TKN_NUM;}
{OCTAL}             { octToDec(yytext); yylval.real = octal.representacionNumerica; return TKN_NUM; }
{NONARIO}           { nnrToDec(yytext); yylval.real = nonario.representacionNumerica; return TKN_NUM; }
{HEXADECIMAL}       { hexToDec(yytext); yylval.real = hexadecimal.representacionNumerica; return TKN_NUM;}
{ROMANO}            { romToDec(yytext); yylval.real = romano.representacionNumerica; return TKN_NUM;}

    /* 4. IDENTIFICADORES */

{IDENTIFICADOR}     { strcpy(yylval.id, yytext); return TKN_ID; }

    /* 5. CARACTERES SIMPLES */

{OPERADOR}          { return *yytext; }
{AGRUPACION}        { return *yytext; }
{GRADOS}            { return deg; }

    /* 6. MANEJO DE ERRORES Y ESPACIOS */

{ERROR}             { printf("Secuencia no válida: %s\n", yytext); return ERROR; }
[ \t\r]+            /* Ignora todos los tabuladores y espacios */
[\n]                { nlines++; return *yytext; }
.                   { printf("Cáracter no reconocido: %s\n", yytext); return ERROR; }
%%
