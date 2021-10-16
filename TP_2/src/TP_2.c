/*
 ============================================================================
 Name        : TP_2.c
 Author      : Aspi Alan Marcos
 Version     :
 Copyright   : 
 Description : TP_2 div E
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "InputUtn.h"
#include <string.h>
#include "Informes.h"

#define EMPTY 1
#define FULL 0
#define TAM 1000
#define REINTENTOS 3
int main(void) {
	int res;
	int opcion;
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	Employee empleados[TAM];
	initEmployees(empleados, TAM);
    setbuf(stdout, NULL);
    do{
		printf("1. Alta de Empleado\n");
		printf("2. Modificar datos del Empleado\n");
		printf("3. Baja de Empleado\n");
		printf("4. Informar\n");
		printf("5. Salir\n");
		res = utn_getInt(&opcion, "Elija una opcion del Menu\n", "ingrese la opcion de nuevo", 0, 6, 3);
		if(res!=-1){
			switch (opcion) {
				case 1:
					if(utn_getEmployees(name, lastName, &salary, &sector)==0){
						id= getId();
						if(addEmployee(empleados, TAM, id, name, lastName, salary, sector)==0){
							printf("Empleado cargado correctamente");
						}else{
							printf("Nose pudo cargar el empleado al sitema.");
						}
					}else{
						printf("ocurrio un error al ingresar los datos");
					}
					break;
				case 2:
					if(cantEmployees(empleados, TAM)>0){
						//codigo para modificar Empleado
					}else{
						printf("debe ingresar previeamente algun Empleado");
					}
					break;
				case 3:
					if(cantEmployees(empleados, TAM)>0){
						printEmployees(empleados, TAM);
						if(utn_getInt(&id, "ingrese el ID a eliminar", "Error", 0, 10000000, REINTENTOS)==0){
							if(removeEmployee(empleados, TAM, id)==0){
								printf("se ha eliminado correctamente el Empleado");
							}else{
								printf("no se pudo eliminar el empleado");
							}
						}else{
							printf("ocurrio un error al ingresar el id");
						}
					}else{
						printf("debe ingresar previeamente algun Empleado");
					}
					break;
				case 4:
					if(cantEmployees(empleados, TAM)>0){
						if(printEmployeesSorted(empleados, TAM)==-1){
							printf("ocurrio un error");
						}else{
							if(printInformesSalary(empleados, TAM)==-1){
								printf("ocurrio un error");
							}
						}
					}else{
						printf("debe ingresar previeamente algun Empleado");
					}
					break;
				case 5:
					printf("saliendo...");
					break;

				default:
					break;
			}

		}
    }while(opcion!=5);
	return EXIT_SUCCESS;
}

