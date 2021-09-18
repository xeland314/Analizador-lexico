# Reconocedor de expresiones matemáticas

## Introducción

El analizador léxico es el encargado de reconocer y recuperarse de errores en las distintas etapas de compilación, además de ser la primera etapa en el proceso llevado a cabo dentro de un compilador. En el presente informe se explica con profundidad el desarrollo de un reconocedor de sistemas numéricos, destacando la importancia del uso de expresiones regulares para cumplir con los objetivos.

## Objetivos

Construir un reconocedor léxico óptimo que tenga las siguientes capacidades:

- Reconocer valor numérico de distintos sistemas de numeración mediante expresiones regulares.
- Realizar las respectivas conversiones de sistemas numéricos.
- Distinguir operadores aritméticos.
- Distinguir signos de apertura y cierre.
- Reconocer funciones matemáticas.

Implementar una gramática ambigua capaz de emular las operaciones que realiza una calculadora:

- Resolución y traducción de operaciones básicas.
- Utilizar operaciones con símbolos unarios: ```-1```, ```---1```, ```--+-1```, etc.
- Manejar funciones trigonométricas e hiperbólicas.
- Manejar operaciones con signos de agrupación: ```()[]{}```

Implementar un sistema para guardar los valores ingresados por consola para volver a utilizarlos, como si se tratará de un lenguaje de programación.

## Descripción del problema / requerimientos

El usuario podrá ingresar uno o más números, tales que pueden pertenecer a los diferentes sistemas numéricos.

Se requiere que el programa reconozca los distintos sistemas numéricos y responda con su correspondiente equivalencia distintas bases. Además, el programa debe distinguir operadores aritméticos y signos de apertura y cierre (paréntesis, corchetes, llaves). Por lo tanto, se plantea el uso de expresiones regulares óptimas para limitar el ingreso de datos, así facilitando el proceso de identificación. Incluso, utilizando dichas expresiones regulares como estructuras de control.

## Números que reconoce

| Sistema Numérico | Letra reconocida | Secuencias válidas | Ejemplos |
|------------:|:------:|:-----------:|:--------:|
|     Binario | (b\|B) | [0-1]       |   b"1111"  |
|    Ternario | (t\|T) | [0-2]       |    T"12"   |
| Cuaternario | (c\|C) | [0-3]       |    c"22"   |
|    Quinario | (q\|Q) | [0-4]       |   -q"11"   |
|     Senario | (x\|X) | [0-5]       |   x"100"   |
|      Heptal | (s\|S) | [0-6]       |    s"21"   |
|       Octal | (o\|O) | [0-7]       |    o"7"    |
|     Nonario | (n\|N) | [0-8]       |    N"81"   |
|     Decimal |        | [0-9]       |    100     |
| Hexadecimal | (h\|H) | [0-9a-fA-F] |    H"F"    |
|      Romano | (r\|R) |             | r"mmmCCXIV"|

El programa tiene la capacidad de reconocer números en todas los sistemas numéricos descritos en la tabla superior. **No olvide acotar los números entre comillas**.

Además, cabe añadir, es capaz de reconocer números en esas bases con decimales. Por ejemplo: ```b"111.11"``` que corresponde al número ```7.75```.
En el caso de los números binarios, no están en complemento a 2.

### Extensión de los números romanos

Los números romanos se representand con las siguientes letras:

|  Letra | Valor  |
|:------:|-------:|
| (i\|I) |    1   |
| (v\|V) |    5   |
| (x\|X) |   10   |
| (l\|L) |   50   |
| (c\|C) |   100  |
| (d\|D) |   500  |
| (m\|M) |  1 000 |

Pero esto solo nos permite representar hasta la cantidad 3 999. La siguiente extensión nos permite trabajar con el límite de 3 999 999 999, aunque por consola solo se pueda ingresar hasta el 399 999 999:
|  Letra |  Valor     |Impresión|
|:------:|-----------:|:-------:|
| (n\|N) |   5 000    |  ṽ  |
| (o\|O) |   10 000   |  Ẋ  |
| (p\|P) |   50 000   |  Ḻ  |
| (q\|Q) |  100 000   |  ĉ  |
| (r\|R) |  500 000   |  ↁ  |
| (s\|S) |  1 000 000 |  ṁ  |
| (t\|T) |  5 000 000 |  Ṽ  |
| (u\|U) | 10 000 000 |  Ẍ  |
| (w\|W) | 50 000 000 |  Ḹ  |
| (y\|Y) |100 000 000 |  ḉ  |
|        |500 000 000 |  ↇ  |
|      |1 000 000 000 |  Ṁ  |

Esto hace posible ingresar valores por consola, en lugar de usar las letras V, X, L, C, D, M con [guión alto](https://es.wikipedia.org/wiki/Numeraci%C3%B3n_romana).

**Nota:** solo es capaz de representar números romanos enteros. En caso de querer transformar un número con decimales, el programa solo representará la parte entera.

## C & Go

_Go_ o _Golang_ es un lenguaje de programación emergente desarrollado por Google, inspirado en C.

Para extender las funciones matemáticas en esta aplicación, se recurre a exportar las definiciones de algunas funciones matemáticas de Go. Por ejemplo, para implementar la función raíz cúbica, inexistente en C.

Lo primero que se debe hacer, es tener un archivo como el siguiente llamado ```math_2.go```:

```Go
package main

import (
    "C"
    "math"
)

//export cbrtF
func cbrtF(x float64) float64 {
    return math.Cbrt(x)
}

func main() {}
```

Cosas importantes a tomar en cuenta de este programa:

- El paquete debe llamarse ```main```.
- Se debe definir la función a usar con la sintaxis de Go.
- Necesita importar el paquete ```C```.
- Necesita importar el paquete ```math```.
- Necesita el comentario especial ```//export``` más el nombre de la función que puede llamar nuestro programa en C.

Este archivo se puede compilar como una librería estática ```.a``` de C con el siguiente comando:

```Go
go build -buildmode=c-archive math_2.go
```

Esto genera dos archivos:

- ```math_2.h```:
Este archivo se incluye en la cabecera de nuestro proyecto. Aquí se encuentra la definición de la función que definimos en Go.

```C
#ifdef __cplusplus
extern "C" {
#endif

extern GoFloat64 cbrtF(GoFloat64 p0);

#ifdef __cplusplus
}
#endif
```

- ```math_2.a```:
Este archivo añadimos al momento de compilar nuestro proyecto con ```gcc```. Añadiendo ```-pthread``` debido a que Go al momento de compilar hace uso de hilos.

Este proceso se realiza para definir otras funciones matemáticas inexistentes en C y algo complicado de definirlas.

Funciones que se implementaron así:

- Acosh(x)
- Asenh(x)
- Atanh(x)
- Hypot(x,y)
- Cbrt(x)
- Gamma(x)
- Factorial: n!

Fuente: [StackOverflow: using-go-code-in-an-existing-c-project](https://stackoverflow.com/questions/32215509/using-go-code-in-an-existing-c-project).

## Ejecución del programa

En la terminal de Ubuntu, se puede ejecutar los siguientes comandos:

- ```yacc -d -v  proyecto.y``` genera los archivos:
  - ```y.tab.c``` para compilar el programa;
  - ```y.tab.h``` las etiquetas de los tokens para implementar en el archivo ```.l```. Y, al final,
  - ```y.output``` un archivo que muestra la resolución de conflictos de la gramática, además de sus estados.
- ```lex reconocedor.l```: permite usar lex para generar el archivo ```lex.yy.c```.
- ```gcc y.tab.c funciones.c lex.yy.c gofuncs/math_2.a -pthread -lfl -lm -o math_app```: permite compilar el código ```lex.yy.c```.
- ```./math_app```: ejecuta el programa.

Es importante a destacar ```-o math_app```, con esto logramos cambiar el nombre final del ejecutable en lugar de que el resultado final sea un ```a.out```.
```-lm``` permite incluir la librería ```<math.h>```.

Todo esto se realiza fácilmente escribiendo ```make``` en la terminal. En el archivo ```Makefile``` figura todo este proceso de compilación.

```Makefile
exec = math_app 
SOURCES = $(wildcard *.c)
LEXFILE = $(wildcard *.l)
YACCFILE = $(wildcard *.y)
AFILES = $(wildcard gofuncs/*.a)

flags = -pthread -lfl -lm
yaccflags = -d -v 

$(exec): $(SOURCES)
    lex $(LEXFILE)
    yacc $(yaccflags) $(YACCFILE)
    gcc $(SOURCES) $(AFILES) $(flags) -o $(exec)
```

## Ejemplos de ejecución

Se prepara algunas operaciones a realizar:

[img1]: https://github.dev/xeland314/Analizador-lexico/tree/main/Reconocedor%20de%20expresiones%20matem%C3%A1ticas/imgs/Captura1.png "entrada.txt"

Se ejecuta en la consola: ```./math_app < entrada.txt > salidad.txt```

Resultado:

[img2]: https://github.dev/xeland314/Analizador-lexico/tree/main/Reconocedor%20de%20expresiones%20matem%C3%A1ticas/imgs/Captura2.png "salida.txt"
