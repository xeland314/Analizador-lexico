#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include "funciones.h"
#define longitud 256
#define baseQuinario 5

struct NumeroQuinario 
{
    long double representacionNumerica;
    char representacionSimbolica[longitud];
};

struct NumeroQuinario quinario;

/*!
    Aquí se normaliza el string desde consola,
    es decir, se retiran los signos (-,+) además
    de las letras (q, Q). 
*/
char *prepararEntradaQ(char expresion[longitud])
{
    int j = 0;
    char *tempCadena = malloc(longitud);

    for (int i = 0; i < strlen(expresion); i++)
    {
        switch (expresion[i])
        {
        case '-': break;
        case '+': break;
        case 'q': break;
        case 'Q': break;
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
void quinToDecDouble(char expresion[longitud])
{
    int signoDelNumero;             //? Puede ser negativo o positivo

    signoDelNumero = asignarSigno(expresion);
    char* representacionSimbolica = prepararEntradaQ(expresion);

    strcpy(quinario.representacionSimbolica, expresion);
    quinario.representacionNumerica = representarNumericamente(representacionSimbolica, signoDelNumero, baseQuinario);

    mostrarResultadoEnTodasLasBases(quinario.representacionNumerica);
}