#include <math.h>

double cbrtF(double x) { return cbrt(x); }
double sqrtF(double x) { return sqrt(x); }
double log2F(double x) { return log2(x); }
double acoshF(double x) { return acosh(x); }
double asenhF(double x) { return asinh(x); }
double atanhF(double x) { return atanh(x); }
double hypotF(double x, double y) { return hypot(x, y); }

// La función Gamma en C está en math.h como tgamma
double gammaF(double x) { return tgamma(x); }

// Factorial usando Gamma: x! = gamma(x + 1)
double factorial(double x) { 
    return tgamma(x + 1.0); 
}
