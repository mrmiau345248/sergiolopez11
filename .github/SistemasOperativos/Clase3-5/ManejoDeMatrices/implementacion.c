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

void multiplicarMatrices(int **matriz1, int **matriz2, int **resultado, int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < tamaño; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
}
