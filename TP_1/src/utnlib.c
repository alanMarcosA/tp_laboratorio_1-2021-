/*
 * utnlib.c
 *
 *  Created on: 24 sept 2021
 *      Author: alan
 */
#include "utnlib.h"
void ingresarNumero(int* num){
	scanf("%d",num);
}
void realizarOperaciones(int numUno, int numDos,int* resultSuma, int* resultResta, float* resultDivision, int* resultMultiplicacion, int* resultFactA, int* resultFactB){
	*resultSuma = sumar(numUno, numDos);
	*resultResta = resta(numUno, numDos);
	*resultMultiplicacion = multiplicar(numUno, numDos);
	if(numDos!=0){
		*resultDivision = division(numUno, numDos);
	}
	if(numUno>=0){
		*resultFactA = factorial(numUno);
	}
	if(numDos>=0){
		*resultFactB = factorial(numDos);
	}
}
int sumar(int numUno, int numDos){
	int result;
	result = numUno + numDos;
	return result;
}
int resta(int numUno, int numDos){
	int result;
	result = numUno - numDos;
	return result;
}
int multiplicar(int numUno, int numDos){
	int result;
	result = numUno * numDos;
	return result;
}
float division(int numUno, int numDos){
	float result;
	result = (float)numUno / numDos;
	return result;
}
int factorial(int num){
	int result;
	if(num==0){
		result= 1;
	}else{
		if(num==1){
			result= 1;
		}else{
			result=num* factorial(num-1);
		}
	}

	return (result);
}
void mostrarResultados(int numUno, int numDos,int resultSuma, int resultResta, float resultDivision, int resultMultiplicacion, int resultFactA, int resultFactB){

	printf("El resultado de A+B es: %d\n",resultSuma);
	printf("El resultado de A-B es: %d\n", resultResta);
	if(numDos!=0){
		printf("El resultado de A/B es: %f\n", resultDivision);
	}else{
		printf("No es posible dividir por cero\n");
	}
	printf("El resultado de A*B es: %d\n", resultMultiplicacion);
	if(numUno>= 0 && numDos >= 0){
		printf("El factorial de A es: %d y El factorial de B es: %d\n", resultFactA, resultFactB);
	}else{
		if(numUno >= 0 && numDos < 0){
			printf("El factorial de A es: %d y El factorial de B no se puede calcular\n", resultFactA);
		}else{
			if(numUno < 0 && numDos >= 0){
				printf("El factorial de A no se puede calcular y El factorial de B es: %d  \n", resultFactB);
			}else{
				printf("el factorial de A y el el factorial de B no se pueden calcular\n");
			}
		}
	}
}
