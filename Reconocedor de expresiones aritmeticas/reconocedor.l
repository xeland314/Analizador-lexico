%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "binario.h"
    #include "ternaria.h"
    #include "cuaternaria.h"
    #include "quinario.h"
    #include "senario.h"
    #include "heptal.h"
    #include "octal.h"
    #include "nonario.h"
    #include "decimal.h"
    #include "hexadecimal.h"
    #include "romanos.h"
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
SIGNOS      [\-]
/* Palabras resevadas */
KEYWORD1    ((I|i)(N|n)(F|f)(O|o))|((H|h)(E|e)(L|l)(P|p))
/* Números en sistema decimal */
ENTERO      {SIGNOS}?{DIGITO}+
FRACCION    {ENTERO}\.{DIGITO}+
REAL        ({ENTERO}|{FRACCION})[eE]{ENTERO}
DECIMAL     {DIGITO}|{ENTERO}|{FRACCION}|{REAL}
/* Números en sistema binario */
binBasico       [bB]{binChars}+
binarioInt      {SIGNOS}?{binBasico}
binarioFloat    {binarioInt}\.{binChars}+
BINARIO         {binBasico}|{binarioInt}|{binarioFloat}
/* Números en sistema ternario */
terBasico       [tT]{terChars}+
ternarioInt     {SIGNOS}?{terBasico}
ternarioFloat   {ternarioInt}\.{terChars}+
TERNARIO        {terBasico}|{ternarioInt}|{ternarioFloat}
/* Números en sistema cuaternario */
cuatBasico          [cC]{cuatChars}+
cuaternarioInt      {SIGNOS}?{cuatBasico}
cuaternarioFloat    {cuaternarioInt}\.{cuatChars}+
CUATERNARIO         {cuatBasico}|{cuaternarioInt}|{cuaternarioFloat}
/* Números en sistema quinario */
quinBasico          [qQ]{quinChars}+
quinarioInt         {SIGNOS}?{quinBasico}
quinarioFloat       {quinarioInt}\.{quinChars}+
QUINARIO            {quinBasico}|{quinarioInt}|{quinarioFloat}
/* Números en sistema senario */
senBasico           [xX]{senChars}+
senarioInt          {SIGNOS}?{senBasico}
senarioFloat        {senarioInt}\.{senChars}+
SENARIO             {senBasico}|{senarioInt}|{senarioFloat}
/* Números en sistema heptal*/
hepBasico           [sS]{hepChars}+
heptalInt           {SIGNOS}?{hepBasico}
heptalFloat         {heptalInt}\.{hepChars}+
HEPTAL              {hepBasico}|{heptalInt}|{heptalFloat}
/* Números en sistema octal */
octalBasico     [oO]{octChars}+
octalInt        {SIGNOS}?{octalBasico}
octalFloat      {octalInt}\.{octChars}+
OCTAL           {octalBasico}|{octalInt}|{octalFloat}
/* Números en sistema nonal */
nonBasico       [nN]{nonChars}+
nonarioInt      {SIGNOS}?{nonBasico}
nonarioFloat    {nonarioInt}\.{nonChars}+
NONARIO         {nonBasico}|{nonarioInt}|{nonarioFloat}
/* Números en sistema hexadecimal */
hexBasico       [hH]{hexChars}+
hexInt          {SIGNOS}?{hexBasico}
hexFloat        {hexInt}\.{hexChars}+
HEXADECIMAL     {hexBasico}|{hexInt}|{hexFloat}
/* Números en romano */
romI            (I|i)
romV            (V|v)
romX            (X|x)
romL            (L|l)
romC            (C|c)
romD            (D|d)
romM            (M|m)
/* Extensión de los números romanos */
romN            (N|n)
romO            (O|o)
romP            (P|p)
romQ            (Q|q)
romR            (R|r)
romS            (S|s)
romT            (T|t)
romU            (U|u)
romMillonDecena ({romU}{0,3})
romMillones     ({romS}{romU}|{romS}{romT}|{romT}?{romS}{0,3})
romMilCentenas  ({romQ}{romS}|{romQ}{romR}|{romR}?{romQ}{0,3})
romMilDecenas   ({romO}{romQ}|{romO}{romP}|{romP}?{romO}{0,3})
romMillares     ({romM}{romO}|{romM}{romN}|{romN}?{romM}{0,3}) 
romCentenas     ({romC}{romM}|{romC}{romD}|{romD}?{romC}{0,3}) 
romDecenas      ({romX}{romC}|{romX}{romL}|{romL}?{romX}{0,3}) 
romUnidades     ({romI}{romX}|{romI}{romV}|{romV}?{romI}{0,3}) 
ROMANO          {SIGNOS}?{romMillonDecena}{romMillones}{romMilCentenas}{romMilDecenas}{romMillares}{romCentenas}{romDecenas}{romUnidades}
/* Identificadores, etc. */
simbolos    [_.\-]|(\.)
label       {DIGITO}+{ALFABETO}+{DIGITO}*
chars       ({DIGITO}|{label}|{simbolos})
id          {ALFABETO}+({chars}|{ALFABETO})*
ERROR       {label}|{chars}|{id}
/* Signos */
ABRIR       ("["|"("|"{"|"<")
CERRAR      ("]"|")"|"}"|">")
OPERADOR    ("+"|"-"|"*"|"/"|"^"|"%")
%option noyywrap
%%
{KEYWORD1}          { printf("PALABRA RESERVADA: %s\nCargando información...\n", yytext); mostrarInfo(); }
{OPERADOR}          { printf("Operador: %s", yytext); reconocerOperador(yytext);  }
{ABRIR}             { printf("Signo de apertura: %s\n", yytext);       }
{CERRAR}            { printf("Signo de cierre: %s\n", yytext);         }
{DECIMAL}           { printf("Decimal: %s\n", yytext);    decToDec(yytext); }
{BINARIO}           { printf("Binario: %s\n", yytext);    binToDecDouble(yytext); }
{TERNARIO}          { printf("Ternario: %s\n", yytext);   terToDecDouble(yytext); }
{CUATERNARIO}       { printf("Cuaternario: %s\n", yytext);cuaToDecDouble(yytext); }
{QUINARIO}          { printf("Quinario: %s\n", yytext);   quinToDecDouble(yytext);}
{SENARIO}           { printf("Senario: %s\n", yytext);    senaToDecDouble(yytext);}
{HEPTAL}            { printf("Heptal: %s\n", yytext);     heptToDecDouble(yytext);}
{OCTAL}             { printf("Octal: %s\n", yytext);      octToDecDouble(yytext); }
{NONARIO}           { printf("Nonario: %s\n", yytext);    nonToDecDouble(yytext); }
{HEXADECIMAL}       { printf("Hexadecimal: %s\n", yytext);hexToDecDouble(yytext); }
{ROMANO}            { printf("Romano: %s\n", yytext);     romToDecDouble(yytext); }
{ERROR}             { printf("SECUENCIA NO VÁLIDA: %s\n", yytext);                }
[ \t\n]+            /* Ignora todos los tabuladores y espacios */
.                   { printf("CARACTER NO RECONOCIDO\n");              }
%%
int main(argc,argv)
int argc;
char **argv;
{
    ++argv, --argc;  
    if (argc>0)
        yyin = fopen(argv[0], "r");
    else
        yyin = stdin;
    printf("\t\tRECONOCEDOR DE EXPRESIONES DE ARITMÉTICA\n");
    yylex();
    return 0;
}