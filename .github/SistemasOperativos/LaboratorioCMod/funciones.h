// Created by mrmiau on 8/29/24.
//
/*
 *Fecha: 29 - 08 - 24
 *Autor: Sergio Lopez Ayala
 *Correccion de errore
 *Modularizacion del codigo
 *Creacion de ficheros
 *
 *
 *--------------------------------------------------------------------------------------
 *              INTERFAZ DE LIBRERIA DE FUNCIONES: MENU DE FUNCIONES
 *--------------------------------------------------------------------------------------
 */

#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_
#define CAPACIDAD_INICIAL 4

/*Creación Estructura de Datos para el Vector*/
typedef struct vectorDinamico{
 int capacidad;
 int totalElementos;
 void **elementos;
} vectorDinamico;


void vectorInicio(vectorDinamico *V);
int totalVector(vectorDinamico *V);
static void resizeVector(vectorDinamico *V, int capacidad);
void addVector(vectorDinamico *V, void *elemento);
void freeVector(vectorDinamico *V);
void *getVector(vectorDinamico *V, int indice);
void setVector(vectorDinamico *V, int indice, void *elemento);
void borrarVector(vectorDinamico *V, int indice);


#endif // _FUNCIONES_H_

