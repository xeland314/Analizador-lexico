#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#define longitud 256

int calcularParteEntera(char parteEntera[longitud], int baseNumerica);
double calcularParteFraccional(char parteFraccional[longitud], int baseNumerica);
int asignarSigno();
void mostrarInfo();

void binInfo()
{
    printf("NÚMEROS BINARIOS:\n");
    printf("\tLas expresiones deben empezar por las letras: (B,b)\n");
    printf("\tSolo admite secuencias de 0's y 1's.\n");
}

void terInfo()
{
    printf("NÚMEROS TERNARIOS:\n");
    printf("\tLas expresiones deben empezar por las letras: (t,T)\n");
    printf("\tSolo admite secuencias que contengan nùmeros del 0 al 2.\n");
}

void cuatInfo()
{
    printf("NÚMEROS CUATERNARIOS:\n");
    printf("\tLas expresiones deben empezar por las letras: (c,C)\n");
    printf("\tSolo admite secuencias que contengan nùmeros del 0 al 3.\n");
}

void quinInfo()
{
    printf("NÚMEROS QUINARIOS:\n");
    printf("\tLas expresiones deben empezar por las letras: (Q,q)\n");
    printf("\tSolo admite secuencias que contengan números del 0 al 4.\n");
}

void senInfo()
{
    printf("NÚMEROS SENARIOS:\n");
    printf("\tLas expresiones deben empezar por las letras: (X,x)\n");
    printf("\tSolo admite secuencias que contengan números del 0 al 5.\n");
}

void heptInfo()
{
    printf("NÚMEROS HEPTALES:\n");
    printf("\tLas expresiones deben empezar por las letras: (S,s)\n");
    printf("\tSolo admite secuencias que contengan números del 0 al 6.\n");
}

void octInfo()
{
    printf("NÚMEROS OCTALES:\n");
    printf("\tLas expresiones deben empezar por las letras: (O,o)\n");
    printf("\tSolo admite secuencias que contengan números del 0 al 7.\n");
}

void nonInfo()
{
    printf("NÚMEROS NONARIOS:\n");
    printf("\tLas expresiones deben empezar por las letras: (N,n)\n");
    printf("\tSolo admite secuencias que contengan números del 0 al 8.\n");
}


void hexInfo()
{
    printf("NÚMEROS HEXADECIMALES:\n");
    printf("\tLas expresiones deben empezar por las letras: (H,h)\n");
    printf("\tSolo admite secuencias que contengan números del 0 al 9\n");
    printf("\ty las letras: (A,B,C,D,E,F) tanto mayúsculas como minúsculas.\n");
}

void capacidadMaxima()
{
    printf("CAPACIDAD MÁXIMA\n");
    printf("Este programa es capaz de manejar números entre 2^32 y -2^32\n");
}


void printline()
{
    printf("----------------------------------------------------------------\n");
}

void mostrarInfo()
{
    printline();
    printf("FUNCIONALIDADES DE ESTA CALCULADORA:\n");
    printf("\tReconoce números en base 2, 3, 4, 5, 6, 7, 8, 9, 10, 16.\n");
    printf("\tReconoce números romanos. (Con minúsculas o mayúsculas)\n");
    printline(); binInfo();
    printline(); terInfo();
    printline(); cuatInfo();
    printline(); quinInfo();
    printline(); senInfo();
    printline(); heptInfo();
    printline(); octInfo();
    printline(); nonInfo();
    printline(); hexInfo();
    printline(); capacidadMaxima();
}

bool esUnaLetra(char letra)
{
    switch(letra)
    { 
        case 'A': return true;
	    case 'a': return true;
        case 'B': return true;
        case 'b': return true;
        case 'C': return true;
        case 'c': return true;
        case 'D': return true;
        case 'd': return true;
        case 'E': return true;
        case 'e': return true;
        case 'F': return true;
        case 'f': return true;
        default: return false;
    }
}


int reemplazarLetraPorNumero(char letra)
{
    switch(letra)
    {   
        case 'A': return 10;
        case 'a': return 10;
        case 'B': return 11;
        case 'b': return 11;
        case 'C': return 12;
        case 'c': return 12;
        case 'D': return 13;
        case 'd': return 13;
        case 'E': return 14;
        case 'e': return 14;
        case 'F': return 15;
        case 'f': return 15;
        default: return 0 ;
    }
}

char reemplazarNumeroPorLetra(int numero)
{
    switch(numero)
    {
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
        default: return '0';
    }
}

/*!
    Retorna el signo del número, si no tiene signo,
    se asume que el número es positivo. 
*/
int asignarSigno(char expresion[longitud])
{
    return (expresion[0] == '-') ? -1 : 1;
}

long long int calcularParteEnteraNumerica(char parteEntera[longitud], int base)
{
    int posicionesPorRecorrer = strlen(parteEntera);
    long long int cantidad = 0;
    int i;
    for (i = 0; i < posicionesPorRecorrer; i++)
    {
        char caracter = parteEntera[i];
        int valorDelCaracter = (esUnaLetra(caracter)) ? reemplazarLetraPorNumero(caracter) : caracter - '0';
        double potencia = pow((double)base, (double)(posicionesPorRecorrer - i - 1));
        cantidad += valorDelCaracter * potencia;
    }
    return cantidad;
}

long double calcularParteDecimalNumerica(char parteDecimal[longitud], int base)
{
    int posicionesPorRecorrer = strlen(parteDecimal);
    long double cantidad = 0;
    int i;
    for (i = 0; i < posicionesPorRecorrer; i++)
    {
        char caracter = parteDecimal[i];
        int valorDelCaracter = (esUnaLetra(caracter)) ? reemplazarLetraPorNumero(caracter) : caracter - '0';
        long double potencia = pow((double)base, (double)((i+1)*(-1)));
        cantidad += valorDelCaracter * potencia;
    }
    return cantidad;
}

/*!
    Esta función transforma el string ingresado desde
    consola a un número en base 10 para poder realizar 
    operaciones con él. 
 */
long double representarNumericamente(char expresion[longitud], int signoDelNumero,int base)
{
    //* Inicialización de variables: 
    long double cantidad = 0;            //? La cantidad que representa el string
    char* parteEntera;              //? Caracteres de la parte entera
    char* parteFraccional;          //? Caracteres de la parte decimal
    long long int parteEnteraNumerica;        //? Parte Entera de la cantidad representada
    long double parteDecimalNumerica;    //? Parte Decimal de la cantidad representada

    //! Separa la parte entera de la decimal del string
    parteFraccional = strtok(expresion, ".");
    parteFraccional = strtok(NULL, ".");
    parteFraccional = (parteFraccional == NULL) ? "0\0" : parteFraccional;
    parteEntera = strtok(expresion, ".");

    //* Operaciones numéricas:
    parteEnteraNumerica = calcularParteEnteraNumerica(parteEntera, base);
    parteDecimalNumerica = calcularParteDecimalNumerica(parteFraccional, base);
    cantidad = signoDelNumero * (parteEnteraNumerica + parteDecimalNumerica);

    return cantidad;
}

void invertirSecuencia(char secuencia[longitud])
{
    int izquierda = 0;
    int derecha = strlen(secuencia) - 1;

    for (izquierda = 0; izquierda < derecha; izquierda++, derecha--)
    {
        char temp = secuencia[izquierda];
        secuencia[izquierda] = secuencia[derecha];
        secuencia[derecha] = temp;
    }
    printf("0%s", secuencia);
}

void representarSimbolicamente(long double numero, int base)
{
    if(numero < 0)
        printf("-");
    //* Inicialización de variables:
    char parteEnteraSimbolica[longitud];
    char parteFraccionalSimbolica[longitud];
    int precision = 16;
    unsigned long long int parteEntera = 0;
    long double parteFraccional = 0;
    int i = 0; 
    int j = 0;

    //? Hallar la parte entera y  fraccional: 
    parteEntera = (numero < 0) ? (long int)(numero * -1) : (long int)(numero);
    parteFraccional = (numero < 0) ? (- parteEntera - numero) : (numero - parteEntera);

    //? Obtener la representación de la parte entera:
    while(parteEntera > 0)
    {
        int residuo = parteEntera % base;
        parteEnteraSimbolica[i] = (residuo > 9) ? reemplazarNumeroPorLetra(residuo) : (char)(residuo + '0');
        parteEntera /= base;
        i++;
    } 
    parteEnteraSimbolica[i] = '\0';
    invertirSecuencia(parteEnteraSimbolica);
    printf(".");

    //? Obtener la representación de la parte fraccional: 
    while(precision-- > 0)
    {
        parteFraccional *= base;
        int bitFraccional = (int) parteFraccional;
        parteFraccional -= bitFraccional;
        parteFraccionalSimbolica[j] = (bitFraccional > 9) ? reemplazarNumeroPorLetra(bitFraccional) : (char) (bitFraccional + '0');
        j++;
    }
    parteFraccionalSimbolica[j] = '\0';
    printf("%s\n", parteFraccionalSimbolica);
}

void imprimirLetra(int indice)
{
    switch(indice)
    {
        case 0: printf("I"); break;
        case 1: printf("IV"); break;
        case 2: printf("V"); break;
        case 3: printf("IX"); break;

        case 4: printf("X"); break;
        case 5: printf("XL"); break;
        case 6: printf("L"); break;
        case 7: printf("XC"); break;

        case 8: printf("C"); break;
        case 9: printf("CD"); break;
        case 10: printf("D"); break;
        case 11: printf("CM"); break;

        case 12: printf("M"); break;
        case 13: printf("MN "); break;
        case 14: printf("N"); break;
        case 15: printf("MO"); break;

        case 16: printf("O"); break;
        case 17: printf("OP"); break;
        case 18: printf("P"); break;
        case 19: printf("OQ"); break;

        case 20: printf("Q"); break;
        case 21: printf("QR"); break;
        case 22: printf("R"); break;
        case 23: printf("QS"); break;

        case 24: printf("S"); break;
        case 25: printf("ST"); break;
        case 26: printf("T"); break;
        case 27: printf("SU"); break;

        case 28: printf("U"); break;
    }
}

void cambiarARomano(double numero)
{
    int num2 = (numero < 0) ? (int)(numero * -1) : (int) numero;
    num2 += 1;
    if (num2 > 33999999)
    {
       printf("Sin representación.\n");
       return;
    }
    if (num2 < 0)
        printf("-");
    
    //! VALORES NUMERICOS EN ROMANOS: 
    int valores[] ={1, 4, 5, 9,
                    10, 40, 50, 90,
                    100, 400, 500, 900,
                    1000, 4000, 5000, 9000, 
                    10000, 40000, 50000, 90000,
                    100000, 400000, 500000, 900000,
                    1000000, 4000000, 5000000, 9000000,
                    10000000};
    //! ==============================================
    for (int i = 28; i > -1; i--)
    {
        while(num2 > valores[i])
        {
            num2 -= valores[i];
            imprimirLetra(i);
        }
    }
    printf("\n");    
}

void mostrarResultadoEnTodasLasBases(long double numero)
{
    printf("\tBIN:\t");
    representarSimbolicamente(numero,2);
    printf("\tTER:\t");
    representarSimbolicamente(numero,3);
    printf("\tCUA:\t");
    representarSimbolicamente(numero,4);
    printf("\tQUI:\t");
    representarSimbolicamente(numero,5);
    printf("\tSEN:\t");
    representarSimbolicamente(numero,6);
    printf("\tHEP:\t");
    representarSimbolicamente(numero,7);
    printf("\tOCT:\t");
    representarSimbolicamente(numero,8);
    printf("\tNON:\t");
    representarSimbolicamente(numero,9);
    printf("\tDEC:\t%g\n", (double)numero);
    printf("\tHEX:\t");
    representarSimbolicamente(numero,16);
    printf("\tROM:\t");
    cambiarARomano(numero);
}

void reconocerOperador(char operador[longitud])
{
    switch(operador[0])
    {
        case 37: printf("\n\tSigno de Porcentaje\n");    break;
        case 43: printf("\n\tSigno Positivo\n");         break;
		case 45: printf("\n\tSigno Negativo\n");         break;
		case 42: printf("\n\tSigno de Multiplicación\n");break;
		case 47: printf("\n\tSigno de División\n");      break;
		case 94: printf("\n\tSigno de Potenciación\n");  break;
    }
}

#endif 