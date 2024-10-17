/*********************************************
 * Sergio Lopez Ayala
 * Desarrollador de Software
 * Bogota
 * Fecha: 03 de octubre de 2024
 * Tema: fork() 
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

// Función para crear procesos utilizando fork
void creacion_fork(int linea) {
    pid_t proceso; // Declaración de una variable para almacenar el ID del proceso
    proceso = fork(); // Crea un nuevo proceso

    // Verifica si hubo un error en la creación del proceso
    if (proceso < 0) {
        printf("Error creación proceso\n"); // Imprime mensaje de error
        exit(1); // Sale del programa con error
    } else if (proceso == 0) // Si estamos en el proceso hijo
        printf("%d: Proceso =HIJO=: %d\n", linea, getpid()); // Imprime información del proceso hijo
    else // Si estamos en el proceso padre
        printf("%d: Proceso =PADRE= %d\n", linea, getpid()); // Imprime información del proceso padre
}

// Función principal del programa
int main(int argc, char *argv[]) {
    // Convierte el argumento de la línea de comandos a un entero
    int p = (int) atoi(argv[1]); 
    // Bucle para crear 'p' procesos
    for (int i = 0; i < p; i++)
        creacion_fork(i); // Llama a la función para crear procesos

    // Imprime una línea de separación
    printf("\n---\n\n");
    return 0; // Termina el programa con éxito
}
