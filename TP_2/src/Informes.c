/*
 * Informes.c
 *
 *  Created on: 15 oct 2021
 *      Author: alan
 */
#include "Informes.h"

int printEmployeesSorted(Employee* list, int len){
	int statePrint;
	statePrint=-1;
	if(list != NULL && len > 0){
		if(sortEmployees(list, len, 1)==0){
			if(printEmployees(list, len)==0){
				statePrint=0;
			}
		}
	}
	return statePrint;
}
int printInformesSalary(Employee* list, int len){
	int statePrint;
	int cantEmployeesAux;
	float totalSalary;
	float promedio;
	statePrint=-1;
	if(list != NULL && len > 0){
		if(getTotalSalary(list, len, &totalSalary)==0){
			cantEmployeesAux=cantEmployees(list, len);
			if(cantEmployeesAux>0){
				promedio=totalSalary/cantEmployeesAux;
				cantEmployeesAux=cantEmployeesUpProm(list, len, promedio);
				if(cantEmployeesAux>=0){
					statePrint=0;
					printf("el total de salrios es %f, el promedio es %f \n y el total de emlpeados que superan el promedio es %d", totalSalary, promedio, cantEmployeesAux);
				}
			}
		}
	}
	return statePrint;
}


