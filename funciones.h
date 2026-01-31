#ifndef _FUNCIONES_H_INCLUDED_
#define _FUNCIONES_H_INCLUDED_

#include <stdbool.h>
#include <wchar.h>

#ifndef longitud
    #define longitud 256
#endif // !longitud

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

#ifndef M_E
    #define M_E 2.71828182845904523536
#endif

#ifndef EINTR
    #define EINTR 4
#endif

/*! Prototipo de funciones */
bool esUnaLetra(char letra);
int reemplazarLetraPorNumero(char letra);
char reemplazarNumeroPorLetra(int numero);
int asignarSigno(char expresion[longitud]);
long long int calcularParteEnteraNumerica(char parteEntera[longitud], int base);
double calcularParteDecimalNumerica(char parteDecimal[longitud], int base);
double representarNumericamente(char expresion[longitud], int signoDelNumero, int base);
void invertirSecuencia(char secuencia[longitud]);
void representarSimbolicamente(double numero, int base);
void imprimirLetra(int indice);
void cambiarARomano(double numero);
void mostrarResultadoEnTodasLasBases(double numero);
void toBin(double numero);
void toTrn(double numero);
void toCtn(double numero);
void toPtl(double numero);
void toSnr(double numero);
void toHpt(double numero);
void toOct(double numero);
void toNnr(double numero);
void toDec(double numero);
void toHxd(double numero);
void toRom(double numero);

#endif 
