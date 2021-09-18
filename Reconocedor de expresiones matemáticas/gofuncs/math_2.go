package main

import (
	"C"
	"math"
)

//export cbrtF
func cbrtF(x float64) float64 {
	return math.Cbrt(x)
}

//export factorial
func factorial(x float64) float64 {
	return x * math.Gamma(x)
}

//export sqrtF
func sqrtF(x float64) float64 {
	return math.Sqrt(x)
}

//export gammaF
func gammaF(x float64) float64 {
	return math.Gamma(x)
}

//export log2F
func log2F(x float64) float64 {
	return math.Log2(x)
}

//export acoshF
func acoshF(x float64) float64 {
	return math.Acosh(x)
}

//export asenhF
func asenhF(x float64) float64 {
	return math.Asinh(x)
}

//export atanhF
func atanhF(x float64) float64 {
	return math.Atanh(x)
}

//export hypotF
func hypotF(x, y float64) float64 {
	return math.Hypot(x, y)
}

func main() {}
