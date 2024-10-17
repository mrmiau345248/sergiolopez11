#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

/*
 *Fecha: 29 - 08 - 24
 *Autor: Sergio Lopez Ayala
 *Correccion de errore
 *Modularizacion del codigo
 *Creacion de ficheros
 *
 *
 *------------------------------------------------
 *              PROGRAMA PRINCIPAL
 *------------------------------------------------
 */


int main(){
    int i;
    vectorDinamico editor;
    vectorInicio(&editor);

    addVector(&editor, "Hola");
    addVector(&editor, "Profesional");
    addVector(&editor, "en");
    addVector(&editor, "Formacion");
    addVector(&editor, "de");
    addVector(&editor, "Ingenieria");




    for (i = 0; i < totalVector(&editor); i++)
        printf("%s ", (char *) getVector(&editor, i));

int a =5;
    while(a>1){
    borrarVector(&editor, a);
	a--;
}
    setVector(&editor, 1, "Buenos");
    addVector(&editor, "Dias");
    for (i = 0; i < totalVector(&editor); i++)
        printf("%s ", (char *) getVector(&editor, i));


    freeVector(&editor);
    return 0;
}

