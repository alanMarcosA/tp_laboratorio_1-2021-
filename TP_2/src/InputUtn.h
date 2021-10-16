/*
 * InputUtn.h
 *
 *  Created on: 15 oct 2021
 *      Author: alan
 */
#include <string.h>
#ifndef INPUTUTN_H_
#define INPUTUTN_H_

int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos);
int esTexto(char cadena[]);

int utn_getEmployees(char name[],char lastName[],float* salary,int* sector);

#endif /* INPUTUTN_H_ */
