/*
 * ArrayEmployees.c
 *
 *  Created on: 11 oct 2021
 *      Author: alan
 */

#include "ArrayEmployees.h"
#define EMPTY 1
#define FULL 0
static int searchFreeSpace(Employee* list, int len);
static void sortEmployeesAsc(Employee* list, int len);
static void sortEmployeesDesc(Employee* list, int len);
static void swap(Employee* list, int i, int j);

int initEmployees(Employee* list, int len)
{
	int stateInit;
	stateInit=-1;
	if(list != NULL && len > 0){
		for(int i=0 ; i<len; i++){
			list[i].isEmpty=EMPTY;
		}
		stateInit=0;
	}
	return stateInit;
}

static int searchFreeSpace(Employee* list, int len){
	int index;
	index=-1;
	for(int i=0; i < len; i++){
		if(list[i].isEmpty == EMPTY){
			index= i;
			break;
		}
	}
	return index;
}

int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector){
	int stateAdd;
	int index;
	stateAdd=-1;
	if(list != NULL && len > 0){
		index= searchFreeSpace(list, len);
		if(index != -1){
			list[index].id=id;
			strcpy(list[index].name,name);
			strcpy(list[index].lastName, lastName);
			list[index].salary=salary;
			list[index].sector=sector;
			list[index].isEmpty=FULL;
			stateAdd=0;
		}
	}
	return stateAdd;
}

int findEmployeeById(Employee* list, int len,int id){
	int index;
	index=-1;
	if(list != NULL && len > 0){
		for(int i=0; i < len; i++){
			if(list[i].id == id && list[i].isEmpty==FULL){
				index= i;
				break;
			}
		}
	}
	return index;
}

int removeEmployee(Employee* list, int len, int id){
	int stateRemove;
	int index;
	stateRemove=-1;
	if(list != NULL && len > 0){
		index=findEmployeeById(list, len, id);
		if(index!=-1){
			list[index].isEmpty=EMPTY;
			stateRemove=0;
		}
	}
	return stateRemove;
}

int sortEmployees(Employee* list, int len, int order){
	int stateSort;
	stateSort=-1;
	if(list != NULL && len > 0){
		stateSort=0;
		if(order == 0){
			sortEmployeesAsc(list, len);
		}else{
			sortEmployeesDesc(list, len);
		}
	}
	return stateSort;
}
static void sortEmployeesAsc(Employee* list, int len){
	int cmp;
	for (int i = 0;  i < len -1; ++ i) {
		for(int j=i+1; j<len ; j++){
			if(list[i].isEmpty==FULL && list[j].isEmpty==FULL){
				cmp=strcmp(list[i].lastName,list[j].lastName);
				if(cmp>0){
					swap(list, i, j);
				}else{
					if(cmp==0 && list[i].sector > list[j].sector){
						swap(list, i, j);
					}
				}
			}
		}
	}
}

static void sortEmployeesDesc(Employee* list, int len){
	int cmp;
	for (int i = 0;  i < len -1; ++ i) {
		for(int j=i+1; j<len ; j++){
			if(list[i].isEmpty==FULL && list[j].isEmpty==FULL){
				cmp=strcmp(list[i].lastName,list[j].lastName);
				if(cmp<0){
					swap(list, i, j);
				}else{
					if(cmp==0 && list[i].sector < list[j].sector){
						swap(list, i, j);
					}
				}
			}
		}
	}
}

static void swap(Employee* list, int i, int j){
	Employee auxEmployee;
	auxEmployee=list[i];
	list[i]=list[j];
	list[j]=auxEmployee;
}

int printEmployees(Employee* list, int length){
	int statePrint;
	statePrint=-1;
	if(list != NULL && length > 0){
		statePrint=0;
		printf("Id - Name - LastName - Salary - Sector \n");
		for(int i=0; i<length;i++){
			if(list[i].isEmpty==FULL){
				printf("%d \t %s \t %s \t %f \t %d \n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
	}
	return statePrint;
}

int getId(void)
{
	static int contador = 0;
	contador++;

	return contador;
}

int cantEmployees(Employee* list, int len){
	int stateCant;
	stateCant=-1;
	if(list != NULL && len > 0){
		stateCant=0;
		for(int i=0; i<len;i++){
			if(list[i].isEmpty==FULL){
				stateCant++;
			}
		}
	}
	return stateCant;
}
int getTotalSalary(Employee* list, int len,float* totalSalary){
	int stateTotal;
	*totalSalary=0.0;
	stateTotal=-1;
	if(list != NULL && len > 0){
		stateTotal=0;
		for(int i=0; i<len;i++){
			if(list[i].isEmpty==FULL){
				*totalSalary=*totalSalary + list[i].salary;
			}
		}
	}
	return stateTotal;
}

int cantEmployeesUpProm(Employee* list, int len,float promedio){
	int stateCant;
	stateCant=-1;
	if(list != NULL && len > 0){
		stateCant=0;
		for(int i=0;i<len;i++){
			if(list[i].isEmpty==FULL && list[i].salary>promedio){
				stateCant++;
			}
		}
	}
	return stateCant;
}
