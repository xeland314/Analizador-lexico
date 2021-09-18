#ifndef _NUMEROS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <ctype.h>
#include "funciones.h"

#define baseBinaria 2
#define baseTernaria 3
#define baseCuaternaria 4
#define baseQuinaria 5
#define baseSenaria 6
#define baseHeptal 7
#define baseOctal 8
#define baseNonal 9
#define baseHexadecimal 16 

#ifndef longitud
    #define longitud 256
#endif // !longitud

typedef struct Numeros
{
    long double representacionNumerica;
    char representacionSimbolica[longitud];
} Numero;

Numero binario;
Numero ternario;
Numero cuaternario;
Numero quinario;
Numero senario;
Numero heptal;
Numero octal;
Numero nonario;
Numero decimal;
Numero hexadecimal;
Numero romano;

char *prepararEntrada(char expresion[longitud])
{
    /*!
    Aquí se normaliza el string desde consola,
    es decir, se retiran los signos (-,+) además
    de las letras. 
     */
    int j = 0;
    char *tempCadena = malloc(longitud);

    for (int i = 0; i < strlen(expresion); i++)
    {
        switch (expresion[i])
        {
        case '-': break; case '+': break;
        case 'b': break; case 'B': break;
        case 't': break; case 'T': break;
        case 'c': break; case 'C': break;
        case 'p': break; case 'P': break;
        case 'q': break; case 'Q': break;
        case 'x': break; case 'X': break;
        case 's': break; case 'S': break;
        case 'o': break; case 'O': break;
        case 'n': break; case 'N': break;
        case '"': break;
        default: 
            tempCadena[j] = expresion[i]; j++;
        }
    }
    tempCadena[j] = '\0';
    return tempCadena;
}
char *prepararEntradaRH(char expresion[longitud])
{
    int j = 0;
    char *tempCadena = malloc(longitud);

    for (int i = 1; i < strlen(expresion); i++)
    {
        switch (expresion[i])
        {
        case '-': break;
        case '+': break;
        case '"': break;
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
/*!
    Estas funciones transforman el string ingresado desde
    consola a un número en base 10 para poder realizar 
    operaciones con él. Lo guardan en un struct Numero. 
 */
void transformarALaBase(Numero *numero, char expresion[longitud], int base)
{
    int signoDelNumero;       //? Puede ser negativo o positivo
    signoDelNumero = asignarSigno(expresion);
    char representacionSimbolica[longitud];
    strcpy(representacionSimbolica, prepararEntrada(expresion));
    strcpy(numero -> representacionSimbolica, expresion);
    numero -> representacionNumerica = representarNumericamente(representacionSimbolica, signoDelNumero, base);
}
void binToDec(char expresion[longitud]) { transformarALaBase(&binario, expresion, baseBinaria); }
void trnToDec(char expresion[longitud]) { transformarALaBase(&ternario, expresion, baseTernaria); }
void ctnToDec(char expresion[longitud]) { transformarALaBase(&cuaternario, expresion, baseCuaternaria); }
void ptlToDec(char expresion[longitud]) { transformarALaBase(&quinario, expresion, baseQuinaria); }
void snrToDec(char expresion[longitud]) { transformarALaBase(&senario, expresion, baseSenaria); }
void hptToDec(char expresion[longitud]) { transformarALaBase(&heptal, expresion, baseHeptal); }
void octToDec(char expresion[longitud]) { transformarALaBase(&octal, expresion, baseOctal); }
void nnrToDec(char expresion[longitud]) { transformarALaBase(&nonario, expresion, baseNonal); }
void hexToDec(char expresion[longitud])
{
    int signoDelNumero;       //? Puede ser negativo o positivo
    asignarSigno(expresion);
    char* representacionSimbolica = prepararEntradaRH(expresion);
    strcpy(hexadecimal.representacionSimbolica, expresion);
    hexadecimal.representacionNumerica = representarNumericamente(representacionSimbolica, signoDelNumero, baseHexadecimal);
}
void decToDec(char expresion[longitud])
{
    decimal.representacionNumerica = atof(expresion);
    strcpy(decimal.representacionSimbolica, expresion);
}
int buscar(char* arreglo, char valor)
{
    for (int i = 0; i < strlen(arreglo); i++){if (valor == arreglo[i]){return i;}}
    return -1;
}
void romToDec(char expresion[longitud])
{
    // Inicialización de variables: 
    int signoDelNumero;             //? Puede ser negativo o positivo
    double cantidad = 0;            //? La cantidad que representa el string
    int valores[] = {
        100000000, 50000000,
        10000000, 5000000, 1000000, 500000,
        100000, 50000, 10000, 5000,
        1000, 500, 100, 50,
        10, 5, 1
    };
    char* simbolos = "YWUTSRQPONMDCLXVI";
    char letra;
    int posicionLetra = 0;
    int posicionValor = 0;
    int ultimoValor = 0;

    signoDelNumero = asignarSigno(expresion);
    char* representacionSimbolica = prepararEntradaRH(expresion);

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
}
#endif // !_NUMEROS_H_