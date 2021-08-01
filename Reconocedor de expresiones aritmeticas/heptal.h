#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  
#include "funciones.h"
#define longitud 256
#define baseHeptal 7

struct NumeroHeptal 
{
    long double representacionNumerica;
    char representacionSimbolica[longitud];
};

struct NumeroHeptal heptal;

/*!
    Aquí se normaliza el string desde consola,
    es decir, se retiran los signos (-,+) además
    de las letras (s, S). 
*/
char *prepararEntradaH(char expresion[longitud])
{
    int j = 0;
    char *tempCadena = malloc(longitud);

    for (int i = 0; i < strlen(expresion); i++)
    {
        switch (expresion[i])
        {
        case '-': break;
        case '+': break;
        case 's': break;
        case 'S': break;
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
void heptToDecDouble(char expresion[longitud])
{
    int signoDelNumero;             //? Puede ser negativo o positivo

    signoDelNumero = asignarSigno(expresion);
    char* representacionSimbolica = prepararEntradaH(expresion);

    strcpy(heptal.representacionSimbolica, expresion);
    heptal.representacionNumerica = representarNumericamente(representacionSimbolica, signoDelNumero, baseHeptal);

    mostrarResultadoEnTodasLasBases(heptal.representacionNumerica);
}