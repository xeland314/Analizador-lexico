#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "funciones.h"
#include <ctype.h>
#define longitud 256

struct NumeroRomano
{
    long double representacionNumerica;
    char representacionSimbolica[longitud];
};

struct NumeroRomano romano;

void romToDecDouble(char expresion[longitud]);
void romToDecChar(double cantidad);
char *prepararEntradaR(char expresion[longitud]); 

/*!
    Aquí se normaliza el string desde consola,
    es decir, se retiran los signos (-,+) además
    de las letras (b, B). 
*/
char *prepararEntradaR(char expresion[longitud])
{
    int j = 0;
    char *tempCadena = malloc(longitud);

    for (int i = 0; i < strlen(expresion); i++)
    {
        switch (expresion[i])
        {
        case '-': break;
        case '+': break;
        default:
            tempCadena[j] = expresion[i];
            j++;
        }
    }
    tempCadena[j] = '\0';
    for(int i = 0; i < strlen(tempCadena); i++)
    {
        tempCadena[i] = toupper(tempCadena[i]);
    }
        

    return tempCadena;
}

int buscar(char* arreglo, char valor)
{
    for (int i = 0; i < strlen(arreglo); i++)
    {
        if (valor == arreglo[i])
        {
            return i;
        }
    }
    return -1;
    
}

/*!
    Esta función transforma el string ingresado desde
    consola a un número en base 10 para poder realizar 
    operaciones con él. 
 */
void romToDecDouble(char expresion[longitud])
{
    //* Inicialización de variables: 
    int signoDelNumero;             //? Puede ser negativo o positivo
    double cantidad = 0;            //? La cantidad que representa el string
    int valores[] = {10000000, 5000000, 1000000, 500000, 100000, 50000, 10000, 5000, 1000, 500, 100, 50, 10, 5, 1};
    char* simbolos = "UTSRQPONMDCLXVI";
    char letra;
    int posicionLetra = 0;
    int posicionValor = 0;
    int ultimoValor = 0;

    signoDelNumero = asignarSigno(expresion);
    char* representacionSimbolica = prepararEntradaR(expresion);

    while(posicionLetra < strlen(representacionSimbolica))
    {
        letra = representacionSimbolica[posicionLetra];
        posicionValor = buscar(simbolos, letra);
        if (posicionValor >= 0)
        {
            cantidad += valores[posicionValor];
            if (valores[posicionValor] > ultimoValor)
            {
                cantidad -= 2 * ultimoValor;
            }
            ultimoValor = valores[posicionValor];
        }
        posicionLetra++;
    }

    strcpy(romano.representacionSimbolica, expresion);
    romano.representacionNumerica = signoDelNumero * cantidad;

    mostrarResultadoEnTodasLasBases(romano.representacionNumerica);
}
