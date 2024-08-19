//
// Created by sl397 on 19/08/2024.
//
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

void imprimirMatriz(int **matriz, int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void liberarMatriz(int **matriz, int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
