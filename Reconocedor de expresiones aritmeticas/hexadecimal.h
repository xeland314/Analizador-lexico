#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "funciones.h"
#define longitud 256
#define baseHexadecimal 16

struct NumeroHexadecimal
{
    long double representacionNumerica;
    char representacionSimbolica[longitud];
};

struct NumeroHexadecimal hexadecimal;

/*!
    Aquí se normaliza el string desde consola,
    es decir, se retiran los signos (-,+) además
    de las letras (h, H). 
*/
char *prepararEntradaHEX(char expresion[longitud])
{
    int j = 0;
    char *tempCadena = malloc(longitud);

    for (int i = 0; i < strlen(expresion); i++)
    {
        switch (expresion[i])
        {
        case '-': break;
        case '+': break;
        case 'h': break;
        case 'H': break;
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
void hexToDecDouble(char expresion[longitud])
{
    int signoDelNumero;             //? Puede ser negativo o positivo

    signoDelNumero = asignarSigno(expresion);
    char* representacionSimbolica = prepararEntradaHEX(expresion);

    strcpy(hexadecimal.representacionSimbolica, expresion);
    hexadecimal.representacionNumerica = representarNumericamente(representacionSimbolica, signoDelNumero, baseHexadecimal);

    mostrarResultadoEnTodasLasBases(hexadecimal.representacionNumerica);

}

