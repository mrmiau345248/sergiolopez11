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
    int **matriz1 = (int **)malloc(tamaño * sizeof(int *));
    int **matriz2 = (int **)malloc(tamaño * sizeof(int *));
    int **resultado = (int **)malloc(tamaño * sizeof(int *));

    for (int i = 0; i < tamaño; i++) {
        matriz1[i] = (int *)malloc(tamaño * sizeof(int));
        matriz2[i] = (int *)malloc(tamaño * sizeof(int));
        resultado[i] = (int *)malloc(tamaño * sizeof(int));
    }

    // Llenar la primera matriz con el valor 1
    for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            matriz1[i][j] = 1;
        }
    }

    // Llenar la segunda matriz con el valor 2
    for (int i = 0; i < tamaño; i++) {
        for (int j = 0; j < tamaño; j++) {
            matriz2[i][j] = 2;
        }
    }

    // Multiplicar las matrices
    multiplicarMatrices(matriz1, matriz2, resultado, tamaño);

    // Imprimir las matrices
    printf("Matriz 1 (%d x %d):\n", tamaño, tamaño);
    imprimirMatriz(matriz1, tamaño);

    printf("Matriz 2 (%d x %d):\n", tamaño, tamaño);
    imprimirMatriz(matriz2, tamaño);

    printf("Resultado de la multiplicación (%d x %d):\n", tamaño, tamaño);
    imprimirMatriz(resultado, tamaño);

    // Liberar memoria
    liberarMatriz(matriz1, tamaño);
    liberarMatriz(matriz2, tamaño);
    liberarMatriz(resultado, tamaño);

    return 0;
}
