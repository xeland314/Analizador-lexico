#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include "funciones.h"
#define longitud 256
#define baseTerciaria 3

struct NumeroTerciario
{
    long double representacionNumerica;
    char representacionSimbolica[longitud];
};
struct NumeroTerciario terciario;

/*!
    Aquí se normaliza el string desde consola,
    es decir, se retiran los signos (-,+) además
    de las letras (t, T). 
*/
char *prepararEntradaT(char expresion[longitud])
{
    int j = 0;
    char *tempCadena = malloc(longitud);

    for (int i = 0; i < strlen(expresion); i++)
    {
        switch (expresion[i])
        {
        case '-': break;
        case '+': break;
        case 't': break;
        case 'T': break;
        default:
            tempCadena[j] = expresion[i];
            j++;
        }
    }
    tempCadena[j] = '\0';
    return tempCadena;
}

/*!
    Esta función transforma el string ingresado desde
    consola a un número en base 10 para poder realizar 
    operaciones con él. 
 */
void terToDecDouble(char expresion[longitud])
{
    int signoDelNumero;             //? Puede ser negativo o positivo

    signoDelNumero = asignarSigno(expresion);
    char* representacionSimbolica = prepararEntradaT(expresion);

    strcpy(terciario.representacionSimbolica, expresion);
    terciario.representacionNumerica = representarNumericamente(representacionSimbolica, signoDelNumero, baseTerciaria);

    mostrarResultadoEnTodasLasBases(terciario.representacionNumerica);
}