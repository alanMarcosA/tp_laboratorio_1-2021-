/*
 ============================================================================
 Name        : TP_1.c
 Author      : Aspi Alan Marcos
 Version     :
 Copyright   : 
 Description : TP_1 div E
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utnlib.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int numeroA;
	int numeroB;
	int resSuma;
	int resResta;
	float resDivsion;
	int resMultiplicacion;
	int resFactA;
	int resFactB;

	int flagA=-1;
	int flagB=-1;
	int flagMostrar=-1;
	do{
		printf("MENU\n");
		printf("1. Ingresar 1er operando (A=%d)\n", numeroA);
		printf("2. Ingresar 2do operando (B=%d)\n", numeroB);
		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultados \n");
		printf("5. Salir\n");
		printf("eleija una opcion:");
		ingresarNumero(&opcion);

		switch (opcion) {
			case 1:
					printf("ingrese el primer numero: ");
					ingresarNumero(&numeroA);
					flagA=1;
					flagMostrar=-1;
				break;
			case 2:
				    printf("ingrese el segundo numero: ");
					ingresarNumero(&numeroB);
					flagB=1;
					flagMostrar=-1;
				break;
			case 3:
					if(flagA==1 && flagB==1){
						realizarOperaciones(numeroA, numeroB, &resSuma, &resResta, &resDivsion, &resMultiplicacion, &resFactA, &resFactB);
						flagMostrar=1;
					}else{
						printf("primero ingresa los numeros a operar\n");
					}

				break;
			case 4:
					if(flagMostrar==1){
						mostrarResultados(numeroA, numeroB, resSuma, resResta, resDivsion, resMultiplicacion, resFactA, resFactB);
					}else{
						printf("primero debes calcular las operaciones\n");
					}
				break;
			case 5:
					printf("saliendo del programa\n");
				break;
			default:
					printf("la opcion ingreseda es incorrecta\n");
				break;
		}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}
