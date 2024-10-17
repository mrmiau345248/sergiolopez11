/*
 *Fecha: 29 - 08 - 24
 *Autor: Sergio Lopez Ayala
 *Correccion de errore
 *Modularizacion del codigo
 *Creacion de ficheros
 *
 *
 *------------------------------------------------
 *              Codigo Fuente
 *------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


// Inicializar los valores de la estructura
void vectorInicio(vectorDinamico *V){
        V->capacidad = CAPACIDAD_INICIAL;
        V->totalElementos = 0;
        V->elementos = malloc(sizeof(void *) * V->capacidad); 
}
//Retorna la cantidad de valores del vector
int totalVector(vectorDinamico *V){
        return V->totalElementos;
}

//Reasigna el tamaño del vector dependiendo del valor de entrada
static void resizeVector(vectorDinamico *V, int capacidad){
        printf("Redimensión: %d a %d \n", V->capacidad, capacidad);

        void **elementos = realloc(V->elementos, sizeof(void *) * capacidad);

        if(elementos){
                V->elementos = elementos;
                V->capacidad = capacidad;
        }
}
//Agrega elementos al vector
void addVector(vectorDinamico *V, void *elemento){
        if(V->capacidad == V->totalElementos)
                resizeVector(V, V->capacidad*2);
        V->elementos[V->totalElementos++] = elemento;
}

// Liberacion de memoria dinamica
void freeVector(vectorDinamico *V){
        free(V->elementos);
}
//Obtencion de elemento segun indice
void *getVector(vectorDinamico *V, int indice){
        if(indice >= 0 && indice < V->totalElementos)
                return V->elementos[indice];
        return NULL;
}
//Asignar valor a un indice i
void setVector(vectorDinamico *V, int indice, void *elemento){
        if(indice >= 0 && indice < V->totalElementos)
                V->elementos[indice]=elemento;
}

//Borrar elemento segun indice, redimension
void borrarVector(vectorDinamico *V, int indice){
        if(indice < 0 || indice >= V->totalElementos)
                return; 

        V->elementos[indice] = NULL;

        for(int i=indice; i<V->totalElementos-1; i++){
                V->elementos[i] = V->elementos[i+1];
                V->elementos[i+1] = NULL; 
        }
        V->totalElementos--;
        if(V->totalElementos>0 && V->totalElementos == V->capacidad/4)
                resizeVector(V, V->capacidad/2);
}
