#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h>
#include "funciones.h"
#define longitud 256
#define baseSenario 6

struct NumeroSenario
{
    long double representacionNumerica;
    char representacionSimbolica[longitud];
};
struct NumeroSenario senario;

/*!
    Aquí se normaliza el string desde consola,
    es decir, se retiran los signos (-,+) además
    de las letras (S, s). 
*/
char *prepararEntradaSN(char expresion[longitud])
{
    int j = 0;
    char *tempCadena = malloc(longitud);

    for (int i = 0; i < strlen(expresion); i++)
    {
        switch (expresion[i])
        {
        case '-': break;
        case '+': break;
        case 'x': break;
        case 'X': break;
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
void senaToDecDouble(char expresion[longitud])
{
    int signoDelNumero;             //? Puede ser negativo o positivo

    signoDelNumero = asignarSigno(expresion);
    char* representacionSimbolica = prepararEntradaSN(expresion);

    strcpy(senario.representacionSimbolica, expresion);
    senario.representacionNumerica = representarNumericamente(representacionSimbolica, signoDelNumero, baseSenario);

    mostrarResultadoEnTodasLasBases(senario.representacionNumerica);
}