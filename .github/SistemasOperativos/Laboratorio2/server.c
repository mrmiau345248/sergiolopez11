/*********************************************
 * Sergio Lopez Ayala
 * Desarrollador de Software
 * Bogota
 * Fecha: 03 de octubre de 2024
 * Tema: Interacción con FIFO en C 
 *          ******SERVER******
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// Define el nombre del FIFO
#define FIFO_FILE "MYFIFO"
// Declaración de la función que invierte una cadena
void reverse_string(char *);

// Función principal del programa
int main() {
    int fd; // Descriptor de archivo para el FIFO
    char readbuf[80]; // Buffer para almacenar la cadena leída
    const char end[] = "FIN"; // Cadena de terminación
    int read_bytes; // Variable para almacenar la cantidad de bytes leídos

    // Elimina el FIFO si ya existe
    unlink(FIFO_FILE);
    
    // Crea el FIFO con los permisos correctos
    mkfifo(FIFO_FILE, 0640);
        
    // Bucle infinito para leer y procesar datos
    while (1) {
        // Abre el FIFO para lectura
        fd = open(FIFO_FILE, O_RDONLY);
        
        // Lee datos del FIFO
        read_bytes = read(fd, readbuf, sizeof(readbuf) - 1);
        
        // Agrega el carácter nulo al final de la cadena leída
        readbuf[read_bytes] = '\0'; 
        // Imprime la cadena recibida y la cantidad de bytes leídos
        printf("Cadena Recibida: \"%s\" y cantidad de bytes %d\n", readbuf, read_bytes);

        // Verifica si la cadena leída es la de terminación
        if (strcmp(readbuf, end) == 0) {
            close(fd); // Cierra el descriptor de lectura
            break; // Sale del bucle si se recibe "FIN"
        }

        // Invierte la cadena leída
        reverse_string(readbuf);
        // Imprime la cadena invertida y su longitud
        printf("FIFOSERVER: Sending Reversed String: \"%s\" y longitud es %d\n", readbuf, (int) strlen(readbuf));

        // Cierra el extremo de lectura antes de abrir para escritura
        close(fd);

        // Abre el FIFO para escritura
        fd = open(FIFO_FILE, O_WRONLY);
        // Verifica si hubo un error al abrir el FIFO para escritura
        if (fd < 0) {
            perror("open for writing"); // Imprime el error
            exit(EXIT_FAILURE); // Sale del programa con error
        }

        // Escribe la cadena invertida de vuelta al FIFO
        if (write(fd, readbuf, strlen(readbuf)) < 0) {
            perror("write"); // Imprime el error si la escritura falla
        }

        close(fd); // Cierra el extremo de escritura

        sleep(2); // Duerme para asegurar que el otro proceso lea esto
    }

    // Elimina el archivo FIFO al finalizar
    unlink(FIFO_FILE);
    return 0; // Termina el programa con éxito
}

// Función para invertir una cadena
void reverse_string(char *str) {
    int last, limit, first; // Variables para índices
    char temp; // Variable temporal para el intercambio
    last = strlen(str) - 1; // Índice del último carácter
    limit = last / 2; // Límite para el intercambio
    first = 0; // Índice del primer carácter

    // Bucle para intercambiar caracteres de la cadena
    while (first < last) {
        temp = str[first]; // Almacena el carácter inicial
        str[first] = str[last]; // Intercambia con el carácter final
        str[last] = temp; // Coloca el carácter inicial en la posición final
        first++; // Avanza el índice del primer carácter
        last--; // Retrocede el índice del último carácter
    }
}
