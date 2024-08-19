#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"



int main(int argc, char *argv[]) {
    if (argc != 2) { // Debe haber un argumento para el tamaño de la matriz
        fprintf(stderr, "Uso: %s <Tamaño>\n", argv[0]);
        return 1;
    }

    int tamaño = atoi(argv[1]);

    if (tamaño >= 6) {
        fprintf(stderr, "El tamaño de la matriz debe ser menor a 6.\n");
        return 1;
    }

    // Crear y llenar las matrices
    for (int k = 1; k <= 3; k++) {
        // Asignar memoria para la matriz
        int **matriz = (int **)malloc(tamaño * sizeof(int *));
        for (int i = 0; i < tamaño; i++) {
            matriz[i] = (int *)malloc(tamaño * sizeof(int));
        }

        // Llenar la matriz con el mismo valor (k)
        for (int i = 0; i < tamaño; i++) {
            for (int j = 0; j < tamaño; j++) {
                matriz[i][j] = k; // Llena la matriz con el valor k
            }
        }

        // Imprimir la matriz
        printf("Matriz %d x %d:\n", tamaño, tamaño);
        imprimirMatriz(matriz, tamaño);

        // Liberar memoria
        liberarMatriz(matriz, tamaño);
    }

    return 0;
}
