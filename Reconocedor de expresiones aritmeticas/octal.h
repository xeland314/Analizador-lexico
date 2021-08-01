#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include "funciones.h"
#define longitud 256
#define baseOctal 8

struct NumeroOctal 
{
    long double representacionNumerica;
    char representacionSimbolica[longitud];
};

struct NumeroOctal octal;

/*!
    Aquí se normaliza el string desde consola,
    es decir, se retiran los signos (-,+) además
    de las letras (o, O). 
*/
char *prepararEntradaO(char expresion[longitud])
{
    int j = 0;
    char *tempCadena = malloc(longitud);

    for (int i = 0; i < strlen(expresion); i++)
    {
        switch (expresion[i])
        {
        case '-': break;
        case '+': break;
        case 'o': break;
        case 'O': break;
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
void octToDecDouble(char expresion[longitud])
{
    int signoDelNumero;             //? Puede ser negativo o positivo

    signoDelNumero = asignarSigno(expresion);
    char* representacionSimbolica = prepararEntradaO(expresion);

    strcpy(octal.representacionSimbolica, expresion);
    octal.representacionNumerica = representarNumericamente(representacionSimbolica, signoDelNumero, baseOctal);

    mostrarResultadoEnTodasLasBases(octal.representacionNumerica);

}