/*
 * utnlib.h
 *
 *  Created on: 24 sept 2021
 *      Author: alan
 */

#ifndef UTNLIB_H_
#define UTNLIB_H_
#include <stdio.h>
#include <stdlib.h>

/**
*\ brief leè el numero ingresado por elo usuario y lo almacena en una variable
*\ param num (donde se guarda el numero ingresado por es usuario)
*/
void ingresarNumero(int* num);

/**
*\ brief realiza las operaciones correspondientes y las guarda en las variables correspondientes
*\ param numUno (ingresa el primer numero a operar)
*\ param numDos (ingresa el segundo numero a operar)
*\ param result*** (ingresa donde se guardaran los resultados de las operaciones)
*/
void realizarOperaciones(int numUno, int numDos,int* resultSuma, int* resultResta, float* resultDivision, int* resultMultiplicacion, int* resultFactA, int* resultFactB);

/**
*\ brief realiza la suma de 2 numeros
*\ param numUno (ingresa el primer numero a operar)
*\ param numDos (ingresa el segundo numero a operar)
*\ return retorna el resultado de la suma
*/
int sumar(int numUno, int numDos);

/**
*\ brief realiza la resta de 2 numeros
*\ param numUno (ingresa el primer numero a operar)
*\ param numDos (ingresa el segundo numero a operar)
*\ return retorna el resultado de la resta
*/
int resta(int numUno, int numDos);

/**
*\ brief realiza la multiplicacion de 2 numeros
*\ param numUno (ingresa el primer numero a operar)
*\ param numDos (ingresa el segundo numero a operar)
*\ return retorna el resultado de la multiplicacion
*/
int multiplicar(int numUno, int numDos);

/**
*\ brief realiza la la division de 2 numeros
*\ param numUno (ingresa el primer numero a operar)
*\ param numDos (ingresa el segundo numero a operar)
*\ return retorna el resultado de la division
*/
float division(int numUno, int numDos);

/**
*\ brief realiza el factorial de 1 numero
*\ param num (ingresa el numero a operar)
*\ return retorna el resultado del factorial de num
*/
int factorial(int num);

/**
*\ brief muestra el resultado de las operaciones, dependiendo de las validaciones correspondientes como dividir por 0 y obtener el factorial de un numero negativo
*\ param numUno (ingresa el primer numero, para validar el factorial)
*\ param numDos (ingresa el segundo numero a operar, para validar el factorial y la division por cero)
*\ param result*** (ingresa los resultados de las operaciones a mostrar)
*/
void mostrarResultados(int numUno, int numDos,int resultSuma, int resultResta, float resultDivision, int resultMultiplicacion, int resultFactA, int resultFactB);
#endif /* UTNLIB_H_ */
