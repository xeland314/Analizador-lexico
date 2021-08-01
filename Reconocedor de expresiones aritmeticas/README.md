# Reconocedor de expresiones aritméticas

## Introducción

El analizador léxico es el encargado de reconocer y recuperarse de errores en las distintas etapas de compilación, además de ser la primera etapa en el proceso llevado a cabo dentro de un compilador. En el presente informe se explica con profundidad el desarrollo de un reconocedor de sistemas numéricos, destacando la importancia del uso de expresiones regulares para especificar patrones que pertenecen a un conjunto de cadenas.

## Objetivo

Construir un reconocedor léxico óptimo que tenga las siguientes capacidades:

- Reconocer valor numérico de distintos sistemas de numeración mediante expresiones regulares.
- Realizar las respectivas conversiones de sistemas numéricos.
- Distinguir operadores aritméticos. Ejemplos: signo de suma '+', resta '-', multiplicación '*', etc.
- Distinguir signos de apertura y cierre.

## Descripción del problema / requerimientos

El usuario podrá ingresar uno o más números, tales que pueden pertenecer a los diferentes sistemas numéricos.

Se requiere que el programa reconozca los distintos sistemas numéricos y responda con su correspondiente equivalencia distintas bases. Además, el programa debe distinguir operadores aritméticos y signos de apertura y cierre (paréntesis, corchetes, llaves, mayor y menor). Por lo tanto, se plantea el uso de expresiones regulares óptimas para limitar el ingreso de datos, así facilitando el proceso de identificación. Incluso, utilizando dichas expresiones regulares como estructuras de control.

## Números que reconoce

| Sistema Numérico | Letra reconocida | Secuencias válidas | Ejemplos |
|-----------------:|:----------------:|:------------------:|:--------:|
|          Binario |      (b\|B)      |        [0-1]       |   b1111  |
|         Ternario |      (t\|T)      |        [0-2]       |    T12   |
|      Cuaternario |      (c\|C)      |        [0-3]       |    c22   |
|         Quinario |      (q\|Q)      |        [0-4]       |   -q11   |
|          Senario |      (x\|X)      |        [0-5]       |   x100   |
|           Heptal |      (s\|S)      |        [0-6]       |    s21   |
|            Octal |      (o\|O)      |        [0-7]       |    o7    |
|          Nonario |      (n\|N)      |        [0-8]       |    N81   |
|          Decimal |                  |        [0-9]       |    100   |
|      Hexadecimal |      (h\|H)      |     [0-9a-fA-F]    |    HF    |
|           Romano |                  |                    | MMMCCXIV |

El programa tiene la capacidad de reconocer números en todas los sistemas numéricos descritos en la tabla superior.
Además, cabe añadir, es capaz de reconocer números en esas bases con decimales. Por ejemplo: ```b111.11``` que corresponde al número ```7.75```.
Incluso si son positivos o negativos; aunque para esto solo añade el signo. Y en el caso de los números binarios, no están en complemento a 2.

### Extensión de los números romanos

Los números romanos se representand con las siguientes letras:

|  Letra | Valor  |
|:------:|:------:|
| (i\|I) |    1   |
| (v\|V) |    5   |
| (x\|X) |   10   |
| (l\|L) |   50   |
| (c\|C) |   100  |
| (d\|D) |   500  |
| (m\|M) |  1 000 |

Pero esto solo nos permite representar hasta la cantidad 3 999. La siguiente extensión nos permite trabajar con el límite de 33 999 999:
|  Letra |  Valor     |
|:------:|:----------:|
| (n\|N) |   5 000    |
| (o\|O) |   10 000   |
| (p\|P) |   50 000   |
| (q\|Q) |  100 000   |
| (r\|R) |  500 000   |
| (s\|S) |  1 000 000 |
| (t\|T) |  5 000 000 |
| (u\|U) | 10 000 000 |

Esto hace posible ingresar valores por consola, en lugar de usar las letras V, X, L, C, D, M con [guión alto](https://es.wikipedia.org/wiki/Numeraci%C3%B3n_romana).

## Ejecución del programa

En la terminal de Ubuntu, se puede ejecutar los siguientes comandos:

- ```lex reconocedor.l```: permite usar lex para generar el archivo ```lex.yy.c```.
- ```gcc -o reconocedor lex.yy.c -lfl -lm```: permite compilar el código ```lex.yy.c```.
- ```./reconocedor```: ejecuta el programa.

Es importante a destacar ```-o reconocedor```, con esto logramos cambiar el nombre final del ejecutable en lugar de que el resultado final sea un ```a.out```.
Además, ```-lm``` permite incluir la librería ```<math.h>```.
