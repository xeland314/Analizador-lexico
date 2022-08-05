#ifndef _CONTROLADORDETOKENS_H_
#define _CONTROLADORDETOKENS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colores.h"

#define LONGITUD 256
#define NUMERO_DE_TOKENS 256

void agregarTokenValor(char *token, long double valor);
int buscarLToken(char tokens[NUMERO_DE_TOKENS][LONGITUD], int filas, char *dato);
long double valorDelToken(char *token);

struct tokens {
    char listaDeTokens[NUMERO_DE_TOKENS][LONGITUD];
    long double valoresDeTokens[NUMERO_DE_TOKENS];
    int cantidadDeTokens;
};
struct tokens config;

void agregarTokenValor(char *token, long double valor)
{   
    // Buscar si ya se ha guardado en la memoria el token: 
    int posicionDeMemoria = buscarLToken(config.listaDeTokens, config.cantidadDeTokens, token);
    if(posicionDeMemoria == -1){
        // Si no está guardado: 
        int tokenActual = config.cantidadDeTokens;
        config.valoresDeTokens[tokenActual] = valor;
        strcpy(config.listaDeTokens[tokenActual], token);
        config.cantidadDeTokens++;
    } else {
        //Caso contrario: 
        config.valoresDeTokens[posicionDeMemoria] = valor;
    }
}

int buscarLToken(char tokens[NUMERO_DE_TOKENS][LONGITUD], int filas, char *dato)
{
    int i;
    int pos = -1;
    for (i = filas - 1; (i > -1) && (pos == -1); i--)
    {
        if(strcmp(tokens[i], dato) == 0)
            pos = i;
    }
    return pos;
}

long double valorDelToken(char *token)
{
    int posicionDelToken = buscarLToken(config.listaDeTokens, config.cantidadDeTokens, token);
    if(posicionDelToken == -1)
    {
        fprintf(stderr, "ERROR: Token no inicializado (%s)\n", token);
        exit(EXIT_FAILURE);
    }
    return config.valoresDeTokens[posicionDelToken];
}

void printTableValues()
{
    printf("%s======================================================%s\n", HVERDE, NORMAL);
    for (int i = 0; i < config.cantidadDeTokens; i++)
    {
        printf("  %s%d.%s  %s%s%s  :  %s%.10Lf%s\n", 
            NROJO, i, NORMAL,  
            NCELESTE, config.listaDeTokens[i], NORMAL,
            NAMARILLO, config.valoresDeTokens[i], NORMAL
        );
    }
    printf("%s======================================================%s\n", HVERDE, NORMAL);
}

#endif // !_CONTROLADORDETOKENS_H_