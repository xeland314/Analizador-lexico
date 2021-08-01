#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include "funciones.h"
#define longitud 256
#define baseNonario 9

struct NumeroNonario 
{
    long double representacionNumerica;
    char representacionSimbolica[longitud];
};

struct NumeroNonario nonario;

/*!
    Aquí se normaliza el string desde consola,
    es decir, se retiran los signos (-,+) además
    de las letras (n, N). 
*/
char *prepararEntradaN(char expresion[longitud])
{
    int j = 0;
    char *tempCadena = malloc(longitud);

    for (int i = 0; i < strlen(expresion); i++)
    {
        switch (expresion[i])
        {
        case '-': break;
        case '+': break;
        case 'n': break;
        case 'N': break;
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
void nonToDecDouble(char expresion[longitud])
{
    int signoDelNumero;             //? Puede ser negativo o positivo

    signoDelNumero = asignarSigno(expresion);
    char* representacionSimbolica = prepararEntradaN(expresion);

    strcpy(nonario.representacionSimbolica, expresion);
    nonario.representacionNumerica = representarNumericamente(representacionSimbolica, signoDelNumero, baseNonario);

    mostrarResultadoEnTodasLasBases(nonario.representacionNumerica);
}
