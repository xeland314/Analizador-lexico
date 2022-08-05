#ifndef _FUNCIONES_H_INCLUDED_
#define _FUNCIONES_H_INCLUDED_

#include <stdbool.h>
#include <wchar.h>

#ifndef longitud
    #define longitud 256
#endif // !longitud

/*! Prototipo de funciones */
bool esUnaLetra(char letra);
int reemplazarLetraPorNumero(char letra);
char reemplazarNumeroPorLetra(int numero);
int asignarSigno(char expresion[longitud]);
long long int calcularParteEnteraNumerica(char parteEntera[longitud], int base);
long double calcularParteDecimalNumerica(char parteDecimal[longitud], int base);
long double representarNumericamente(char expresion[longitud], int signoDelNumero, int base);
void invertirSecuencia(char secuencia[longitud]);
void representarSimbolicamente(long double numero, int base);
void imprimirLetra(int indice);
void cambiarARomano(double numero);
void mostrarResultadoEnTodasLasBases(long double numero);
void toBin(long double numero);
void toTrn(long double numero);
void toCtn(long double numero);
void toPtl(long double numero);
void toSnr(long double numero);
void toHpt(long double numero);
void toOct(long double numero);
void toNnr(long double numero);
void toDec(long double numero);
void toHxd(long double numero);
void toRom(long double numero);

#endif 