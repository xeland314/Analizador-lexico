#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include "colores.h"
#define longitud 256


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
    return (expresion[0] == '-' || expresion[2] == '-' || expresion[4] == '-') ? -1 : 1;
}

long long int calcularParteEnteraNumerica(char parteEntera[longitud], int base)
{
    int posicionesPorRecorrer = strlen(parteEntera);
    long long int cantidad = 0;
    for (int i = 0; i < posicionesPorRecorrer; i++)
    {
        char caracter = parteEntera[i];
        int valorDelCaracter = (esUnaLetra(caracter)) ? reemplazarLetraPorNumero(caracter) : caracter - '0';
        double potencia = pow((double)base, (double)(posicionesPorRecorrer - i - 1));
        cantidad += valorDelCaracter * potencia;
    }
    return cantidad;
}

double calcularParteDecimalNumerica(char parteDecimal[longitud], int base)
{
    int posicionesPorRecorrer = strlen(parteDecimal);
    double cantidad = 0;
    int i;
    for (i = 0; i < posicionesPorRecorrer; i++)
    {
        char caracter = parteDecimal[i];
        int valorDelCaracter = (esUnaLetra(caracter)) ? reemplazarLetraPorNumero(caracter) : caracter - '0';
        double potencia = pow((double)base, (double)((i+1)*(-1)));
        cantidad += valorDelCaracter * potencia;
    }
    return cantidad;
}

/*!
    Esta función transforma el string ingresado desde
    consola a un número en base 10 para poder realizar 
    operaciones con él. 
 */
double representarNumericamente(char expresion[longitud], int signoDelNumero, int base)
{
    //* Inicialización de variables: 
    double cantidad = 0;            //? La cantidad que representa el string
    char* parteEntera;              //? Caracteres de la parte entera
    char* parteFraccional;          //? Caracteres de la parte decimal
    long long int parteEnteraNumerica;        //? Parte Entera de la cantidad representada
    double parteDecimalNumerica;    //? Parte Decimal de la cantidad representada

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
    printf("%s", secuencia);
}

void representarSimbolicamente(double numero, int base)
{
    if(numero < 0)
        printf("-");
    //* Inicialización de variables:
    char parteEnteraSimbolica[longitud];
    char parteFraccionalSimbolica[longitud];
    int precision = 16;
    unsigned long long int parteEntera = 0;
    double intPart;
    double parteFraccional = 0;
    int i = 0; 
    int j = 0;

    //? Hallar la parte entera y  fraccional: 
    //parteEntera = (numero < 0) ? (unsigned long long int)(numero * -1) : (unsigned long long int)(numero);
    //parteFraccional = (numero < 0) ? ((numero * -1) - parteEntera) : (numero - parteEntera);
    parteFraccional = (numero < 0) ?  modf(numero * -1, &intPart): modf(numero, &intPart);
    parteEntera = intPart;
    //? Obtener la representación de la parte entera:
    while(parteEntera > 0)
    {
        int residuo = fmod(parteEntera, base);
        parteEnteraSimbolica[i] = (residuo > 9) ? reemplazarNumeroPorLetra(residuo) : (char)(residuo + '0');
        parteEntera /= base;
        i++;
    } 
    parteEnteraSimbolica[i] = '\0';
    invertirSecuencia(parteEnteraSimbolica);
    
    if(parteFraccional == 0)
    {
        printf("\n");
        return;
    }

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
    setlocale(LC_CTYPE, "");
    /* 3 999 - 3'999 999*/
    wchar_t vHatChar = L'ṽ';
    wchar_t xHatChar = L'Ẋ';
    wchar_t lHatChar = L'Ḻ';
    wchar_t cHatChar = L'ĉ';
    wchar_t dHatChar = L'ↁ';
    wchar_t mHatChar = L'ṁ';
    /* 399 999 - 3 999'999 999 */
    wchar_t v2HatChar = L'Ṽ';
    wchar_t x2HatChar = L'Ẍ';
    wchar_t l2HatChar = L'Ḹ';
    wchar_t c2HatChar = L'ḉ';
    wchar_t d2HatChar = L'ↇ';
    wchar_t m2HatChar = L'Ṁ';

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
        case 13: printf("M%lc", vHatChar); break; 
        case 14: printf("%lc", vHatChar); break;
        case 15: printf("M%lc", xHatChar); break;

        case 16: printf("%lc", xHatChar); break;
        case 17: printf("%lc%lc", xHatChar, lHatChar); break;
        case 18: printf("%lc", lHatChar); break;
        case 19: printf("%lc%lc", xHatChar, cHatChar); break;

        case 20: printf("%lc", cHatChar); break;
        case 21: printf("%lc%lc", cHatChar, dHatChar); break;
        case 22: printf("%lc", dHatChar); break;
        case 23: printf("%lc%lc", cHatChar, mHatChar); break;

        case 24: printf("%lc", mHatChar); break;
        case 25: printf("%lc%lc", mHatChar, v2HatChar); break;
        case 26: printf("%lc", v2HatChar); break;
        case 27: printf("%lc%lc", mHatChar, x2HatChar); break;

        case 28: printf("%lc", x2HatChar); break;
        case 29: printf("%lc%lc", x2HatChar, l2HatChar); break;
        case 30: printf("%lc", l2HatChar); break;
        case 31: printf("%lc%lc", x2HatChar, c2HatChar); break;

        case 32: printf("%lc", c2HatChar); break;
    }
}

void cambiarARomano(double numero)
{
    if (numero > 399999999 || numero < -399999999)
    { 
        printf("Sin representación.\n"); 
        return; 
    }

    int num2 = (numero < 0) ? (int)(numero * -1) : (int) numero;
    num2 += 1;

    if (numero < 0)
        printf("-");
    
    //! VALORES NUMERICOS EN ROMANOS: 
    int valores[] ={1, 4, 5, 9,
                    10, 40, 50, 90,
                    100, 400, 500, 900,
                    1000, 4000, 5000, 9000, 
                    10000, 40000, 50000, 90000,
                    100000, 400000, 500000, 900000,
                    1000000, 4000000, 5000000, 9000000,
                    10000000, 40000000, 50000000, 90000000,
                    100000000};
    //* ==============================================
    for (int i = 32; i > -1; i--)
    {
        while(num2 > valores[i])
        {
            num2 -= valores[i];
            imprimirLetra(i);
        }
    }
    printf("\n");    
}

void mostrarResultadoEnTodasLasBases(double numero)
{
    printf("%s\tBIN:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,2);
    printf("%s\tTER:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,3);
    printf("%s\tCUA:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,4);
    printf("%s\tQUI:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,5);
    printf("%s\tSEN:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,6);
    printf("%s\tHEP:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,7);
    printf("%s\tOCT:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,8);
    printf("%s\tNON:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,9);
    printf("%s\tDEC:\t%s%f\n", NROJO, NORMAL, numero);
    printf("%s\tHEX:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,16);
    printf("%s\tROM:\t%s", NROJO, NORMAL);
    cambiarARomano(numero);
}

void toBin(double numero)
{
    printf("%s\tBIN:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,2);
}
void toTrn(double numero)
{
    printf("%s\tTER:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,3);
}
void toCtn(double numero)
{
    printf("%s\tCUA:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,4);
}
void toPtl(double numero)
{
    printf("%s\tQUI:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,5);
}
void toSnr(double numero)
{
    printf("%s\tSEN:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,6);
}
void toHpt(double numero)
{
    printf("%s\tHEP:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,7);
}
void toOct(double numero)
{
    printf("%s\tOCT:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,8);    
}
void toNnr(double numero)
{
    printf("%s\tNON:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,9);    
}
void toDec(double numero)
{
    printf("%s\tDEC:\t%s%f\n", NROJO, NORMAL, numero);
}
void toHxd(double numero)
{
    printf("%s\tHEX:\t%s", NROJO, NORMAL);
    representarSimbolicamente(numero,16);    
}
void toRom(double numero)
{
    printf("%s\tROM:\t%s", NROJO, NORMAL);
    cambiarARomano(numero);    
}


/* Implementación de la evaluación recursiva con múltiples parámetros */
#include "gramatica.tab.h"

// Declaraciones de Flex para re-entrancia
typedef struct yy_buffer_state *YY_BUFFER_STATE;
extern int yylex_init(void** scanner);
extern int yylex_destroy(void* scanner);
extern YY_BUFFER_STATE yy_scan_string(const char *str, void* scanner);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer, void* scanner);

extern int yyparse(ParserContext* ctx, void* scanner);
extern double valorDelToken(const char* token);
extern void agregarTokenValor(const char* token, double valor);

double evaluarCuerpoMultiparams(const char* nombre_func, double* args, int num_args) {
    const char* full_def = obtenerCuerpoFuncion(nombre_func);
    if (!full_def) return 0;

    // Clonar para no romper el original
    char* def_copy = strdup(full_def);
    char* params_str = strtok(def_copy, "|");
    char* body = strtok(NULL, "|");

    if (!params_str || !body) {
        free(def_copy);
        return 0;
    }

    // 1. Asignar parámetros a la tabla de símbolos
    char* param_name = strtok(params_str, ",");
    int i = 0;
    while (param_name && i < num_args) {
        agregarTokenValor(param_name, args[i]);
        param_name = strtok(NULL, ",");
        i++;
    }

    // 2. Preparar cuerpo
    char buffer_cuerpo[512];
    snprintf(buffer_cuerpo, sizeof(buffer_cuerpo), "%s\n", body);

    // 3. Evaluar
    void* sub_scanner;
    yylex_init(&sub_scanner);
    YY_BUFFER_STATE bp = yy_scan_string(buffer_cuerpo, sub_scanner);

    ParserContext sub_ctx;
    sub_ctx.scanner = sub_scanner;
    sub_ctx.last_result = 0;
    sub_ctx.is_sub_eval = 1;

    yyparse(&sub_ctx, sub_scanner);

    yy_delete_buffer(bp, sub_scanner);
    yylex_destroy(sub_scanner);
    
    free(def_copy);
    return sub_ctx.last_result;
}
