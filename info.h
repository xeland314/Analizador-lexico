#ifndef _INFO_H_
#define _INFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colores.h"

void printline()
{
    printf("%s---------------------------------------------------------------------------%s\n", HCELESTE, NORMAL);
}

void capacidadMaxima()
{
    printf("%sCapacidad máxima de la calculadora:%s\n", CCELESTE, NORMAL);
    printf("\tRANGO NUMÉRICO: %s[ 2^63 , -2^63 ]%s\n", NMORADO, NORMAL);
    printf("\tRANGO ROMANO: %s[ 3 999 999 999 , -3 999 999 999 ]%s\n", NMORADO, NORMAL);
    printf("\t(Límite de entrada por consola para romanos: %s399 999 999%s)\n", NAMARILLO, NORMAL);
}

void sistemasNumericos()
{
    printf("%sSistemas numéricos soportados (Acotar entre comillas):%s\n", CCELESTE, NORMAL);
    printf("\t%sBIN%s: b\"[0-1]\"   | %sTRN%s: t\"[0-2]\"   | %sCTN%s: c\"[0-3]\"\n", NROJO, NORMAL, NROJO, NORMAL, NROJO, NORMAL);
    printf("\t%sQUI%s: q\"[0-4]\"   | %sSNR%s: x\"[0-5]\"   | %sHEP%s: s\"[0-6]\"\n", NROJO, NORMAL, NROJO, NORMAL, NROJO, NORMAL);
    printf("\t%sOCT%s: o\"[0-7]\"   | %sNNR%s: n\"[0-8]\"   | %sDEC%s: [0-9]\n", NROJO, NORMAL, NROJO, NORMAL, NROJO, NORMAL);
    printf("\t%sHEX%s: h\"[0-9a-f]\"| %sROM%s: r\"[i-y]\"\n", NROJO, NORMAL, NROJO, NORMAL);
    printf("\t%sEjemplo:%s b\"111.11\", H\"FF\", r\"mmmCCXIV\"\n", NAMARILLO, NORMAL);
}

void funcionesMatematicas()
{
    printf("%sFunciones Matemáticas:%s\n", CCELESTE, NORMAL);
    printf("\t%sTrigonométricas:%s sen, cos, tan, sec, csc, ctg (usar 'deg' para grados)\n", NVERDE, NORMAL);
    printf("\t%sInversas:%s asen, acos, atan, atan2\n", NVERDE, NORMAL);
    printf("\t%sHiperbólicas:%s senh, cosh, tanh, asenh, acosh, atanh\n", NVERDE, NORMAL);
    printf("\t%sLog/Exp:%s log, log10, log2, exp\n", NVERDE, NORMAL);
    printf("\t%sOtras:%s sqrt, cbrt, abs, gamma, hypot, !\n", NVERDE, NORMAL);
}

void operadoresYAsignaciones()
{
    printf("%sOperadores y Variables:%s\n", CCELESTE, NORMAL);
    printf("\t%sBásicos:%s +, -, *, /, %%, ^, !, |, (), ? :\n", NAZUL, NORMAL);
    printf("\t%sComparación:%s ==, !=, <, <=, >, >=\n", NAZUL, NORMAL);
    printf("\t%sLógicos:%s &&, ||, !, XOR, NOR\n", NAZUL, NORMAL);
    printf("\t%sAsignación:%s = , += , -= , *= , /=\n", NAZUL, NORMAL);
    printf("\t%sInc/Dec:%s ++var, --var, var++, var--\n", NAZUL, NORMAL);
    printf("\t%sVariables:%s x = 10, y = b\"1010\"\n", NAZUL, NORMAL);
}

void comandosEspeciales()
{
    printf("%sComandos y Conversiones:%s\n", CCELESTE, NORMAL);
    printf("\t%sexit%s: Salir | %stable%s: Ver variables | %sprintl%s: Línea divisoria\n", NAMARILLO, NORMAL, NAMARILLO, NORMAL, NAMARILLO, NORMAL);
    printf("\t%sCONVERT_ALL(n)%s: Muestra 'n' en todas las bases.\n", NAMARILLO, NORMAL);
    printf("\t%sBIN(n), HEX(n), ROM(n), ...%s: Convierte 'n' a la base indicada.\n", NAMARILLO, NORMAL);
}

void mostrarInfo()
{
    printline();
    printf("\t\t%sAYUDA - RECONOCEDOR DE EXPRESIONES%s\n", SCELESTE, NORMAL);
    printline();
    capacidadMaxima();
    printline();
    sistemasNumericos();
    printline();
    funcionesMatematicas();
    printline();
    operadoresYAsignaciones();
    printline();
    comandosEspeciales();
    printline();
}

#endif
