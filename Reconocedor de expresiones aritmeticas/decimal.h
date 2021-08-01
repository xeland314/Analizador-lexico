#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funciones.h"
#define longitud 256

struct NumeroDecimal
{
    long double representacionNumerica;
    char representacionSimbolica[longitud];
};
struct NumeroDecimal decimal;

void decToDec(char expresion[longitud])
{
    decimal.representacionNumerica = atof(expresion);
    strcpy(decimal.representacionSimbolica, expresion);

    mostrarResultadoEnTodasLasBases(decimal.representacionNumerica);

}