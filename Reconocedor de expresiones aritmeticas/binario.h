#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include "funciones.h"
#define longitud 256
#define baseBinaria 2

struct NumeroBinario 
{
    long double representacionNumerica;
    char representacionSimbolica[longitud];
};

struct NumeroBinario binario;

/*!
    Aquí se normaliza el string desde consola,
    es decir, se retiran los signos (-,+) además
    de las letras (b, B). 
*/
char *prepararEntrada(char expresion[longitud])
{
    int j = 0;
    char *tempCadena = malloc(longitud);

    for (int i = 0; i < strlen(expresion); i++)
    {
        switch (expresion[i])
        {
        case '-': break;
        case '+': break;
        case 'b': break;
        case 'B': break;
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
void binToDecDouble(char expresion[longitud])
{
    int signoDelNumero;             //? Puede ser negativo o positivo

    signoDelNumero = asignarSigno(expresion);
    char* representacionSimbolica = prepararEntrada(expresion);

    strcpy(binario.representacionSimbolica, expresion);
    binario.representacionNumerica = representarNumericamente(representacionSimbolica, signoDelNumero, baseBinaria);

    mostrarResultadoEnTodasLasBases(binario.representacionNumerica);
}
