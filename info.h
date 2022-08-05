#ifndef _INFO_H_
#define _INFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colores.h"

void capacidadMaxima()
{
    printf("%sCapacidad máxima de conversión entre números de diferentes bases:%s\n", CCELESTE, NORMAL);
    printf("\tRANGO DE NÚMEROS %s[ 2^63 , -2^63 ]%s\n", NMORADO,NORMAL);
    printf("\tRANGO DE NÚMEROS %s[ 9223372036854775808 , -9223372036854775808 ]%s\n", NMORADO,NORMAL);
    printf("EXCEPCIÓN: Rango de números romanos %s[3999999999, -3999999999]%s\n",NMORADO,NORMAL);
}

void printline()
{
    printf("%s---------------------------------------------------------------------------%s\n", HCELESTE, NORMAL);
}

void sistemasNumericos()
{
    printf("%sSistemas numéricos de esta aplicación:%s\n",CCELESTE,NORMAL);
    printf("\t%sBIN%s\t-->\t%sb%s\"%s[0-1]+%s\"%s\n",NROJO,NORMAL,NAZUL,NAMARILLO,NVERDE,NAMARILLO,NORMAL);
    printf("\t%sTRN%s\t-->\t%st%s\"%s[0-2]+%s\"%s\n",NROJO,NORMAL,NAZUL,NAMARILLO,NVERDE,NAMARILLO,NORMAL);
    printf("\t%sCTN%s\t-->\t%sc%s\"%s[0-3]+%s\"%s\n",NROJO,NORMAL,NAZUL,NAMARILLO,NVERDE,NAMARILLO,NORMAL);
    printf("\t%sQUI%s\t-->\t%sq%s\"%s[0-4]+%s\"%s\n",NROJO,NORMAL,NAZUL,NAMARILLO,NVERDE,NAMARILLO,NORMAL);
    printf("\t%sSNR%s\t-->\t%sx%s\"%s[0-5]+%s\"%s\n",NROJO,NORMAL,NAZUL,NAMARILLO,NVERDE,NAMARILLO,NORMAL);
    printf("\t%sHEP%s\t-->\t%ss%s\"%s[0-6]+%s\"%s\n",NROJO,NORMAL,NAZUL,NAMARILLO,NVERDE,NAMARILLO,NORMAL);
    printf("\t%sOCT%s\t-->\t%so%s\"%s[0-7]+%s\"%s\n",NROJO,NORMAL,NAZUL,NAMARILLO,NVERDE,NAMARILLO,NORMAL);
    printf("\t%sNON%s\t-->\t%sn%s\"%s[0-8]+%s\"%s\n",NROJO,NORMAL,NAZUL,NAMARILLO,NVERDE,NAMARILLO,NORMAL);
    printf("\t%sDEC%s\t-->\t%s[0-9]+%s\n",NROJO,NORMAL,NVERDE,NORMAL);
    printf("\t%sHEX%s\t-->\t%sh%s\"%s[0-9a-fA-F]+%s\"%s\n",NROJO,NORMAL,NAZUL,NAMARILLO,NVERDE,NAMARILLO,NORMAL);
    printf("\t%sROM%s\t-->\t%sr%s\"%s[Ii]|[Ll]|[c-dC-Dm-yM-Y]+%s\"%s\n",NROJO,NORMAL,NAZUL,NAMARILLO,NVERDE,NAMARILLO,NORMAL);
    printf("\tSe puede admitir tanto mayúsculas como minúsculas: b\"111\" = B\"111\"\n");
}

void mostrarInfo()
{
    printline();
    printf("%sFUNCIONALIDADES DE ESTA CALCULADORA:%s\n",CCELESTE,NORMAL);
    printf("\t- Reconoce números en base 2, 3, 4, 5, 6, 7, 8, 9, 10, 16.\n");
    printf("\t- Reconoce números romanos. (Con minúsculas o mayúsculas)\n");
    printf("\t- Puedes guardar ese valor en una variable: resultado = 10 \n");
    printline(); capacidadMaxima();
    printline(); sistemasNumericos();
    printline();
}

#endif 