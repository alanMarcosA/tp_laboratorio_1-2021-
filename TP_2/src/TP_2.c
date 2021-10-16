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
	int opcionDos;
	int index;
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
							printf("Empleado cargado correctamente\n");
						}else{
							printf("Nose pudo cargar el empleado al sitema.\n");
						}
					}else{
						printf("ocurrio un error al ingresar los datos\n");
					}
					break;
				case 2:
					if(cantEmployees(empleados, TAM)>0){
						printEmployees(empleados, TAM);
						if(utn_getInt(&id, "ingrese el ID del usario a modificar", "Error", 0, 10000000, REINTENTOS)==0){
							index=findEmployeeById(empleados, TAM, id);
							if(index!=-1){
								strcpy(name, empleados[index].name);
								strcpy(lastName, empleados[index].lastName);
								salary=empleados[index].salary;
								sector=empleados[index].sector;
								if(utn_getInt(&opcionDos, "ingrese la opcion a modificar \n 1.nombre \n 2.apellido \n 3.salario \n 4.sector \n", "error",0, 4, REINTENTOS)==0){
									switch (opcionDos) {
										case 1:
											if(utn_getText(name, 51, "ingrese el nombre", "error.", REINTENTOS)==0){
												if(modifyEmployee(empleados, id, TAM, name, lastName, salary, sector)==0){
													printf("se modifico correctamente el empleado\n");
												}else{
													printf("ocurrio un error al modificar el empleado.\n");
												}
											}else{
												printf("ocurrio un error al ingresar el dato\n");
											}
											break;
										case 2:
											if(utn_getText(lastName, 51, "ingrese el apellido", "error.", REINTENTOS)==0){
												if(modifyEmployee(empleados, id, TAM, name, lastName, salary, sector)==0){
													printf("se modifico correctamente el empleado\n");
												}else{
													printf("ocurrio un error al modificar el empleado.\n");
												}
											}else{
												printf("ocurrio un error al ingresar el dato\n");
											}
											break;
										case 3:
											if(utn_getFloat(&salary, "ingrese el salario", "Error.", 0, 10000000, REINTENTOS)==0){
												if(modifyEmployee(empleados, id, TAM, name, lastName, salary, sector)==0){
													printf("se modifico correctamente el empleado\n");
												}else{
													printf("ocurrio un error al modificar el empleado.\n");
												}
											}else{
												printf("ocurrio un error al ingresar el dato\n");
											}
											break;
										case 4:
											if(utn_getInt(&sector, "ingrese elo sector", "Error.", 0, 100000, REINTENTOS)==0){
												if(modifyEmployee(empleados, id, TAM, name, lastName, salary, sector)==0){
													printf("se modifico correctamente el empleado\n");
												}else{
													printf("ocurrio un error al modificar el empleado.\n");
												}
											}else{
												printf("ocurrio un error al ingresar el dato\n");
											}
											break;
										default:
											break;
									}
								}else{
									printf("ocurrio un error con la opcion seleccionada");
								}
							}else{
								printf("No se encontro empleado con el id ingresado\n");
							}
						}else{
							printf("ocurrio un problema al ingresar el id\n");
						}
					}else{
						printf("debe ingresar previeamente algun Empleado\n");
					}
					break;
				case 3:
					if(cantEmployees(empleados, TAM)>0){
						printEmployees(empleados, TAM);
						if(utn_getInt(&id, "ingrese el ID a eliminar", "Error", 0, 10000000, REINTENTOS)==0){
							if(removeEmployee(empleados, TAM, id)==0){
								printf("se ha eliminado correctamente el Empleado\n");
							}else{
								printf("no se pudo eliminar el empleado\n");
							}
						}else{
							printf("ocurrio un error al ingresar el id\n");
						}
					}else{
						printf("debe ingresar previeamente algun Empleado\n");
					}
					break;
				case 4:
					if(cantEmployees(empleados, TAM)>0){
						if(printEmployeesSorted(empleados, TAM)==-1){
							printf("ocurrio un error\n");
						}else{
							if(printInformesSalary(empleados, TAM)==-1){
								printf("ocurrio un error\n");
							}
						}
					}else{
						printf("debe ingresar previeamente algun Empleado\n");
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

