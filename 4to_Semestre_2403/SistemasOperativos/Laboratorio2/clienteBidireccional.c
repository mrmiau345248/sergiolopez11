/*********************************************
 * Sergio Lopez Ayala
 * Desarrollador de Software
 * Bogota
 * Fecha: 03 de octubre de 2024
 * Tema: Interacción con FIFO en C 
 *          ******CLIENTE******
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

// Define el nombre del FIFO
#define FIFO_FILE "MYFIFO"

// Función principal del programa
int main() {
    int fd; // Descriptor de archivo para el FIFO
    int end_process; // Variable para verificar la cadena de terminación
    char readbuf[80]; // Buffer para almacenar la cadena ingresada
    const char end_str[] = "end"; // Cadena que indica el final del proceso

    // Mensaje de inicio para el usuario
    printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");

    // Abre el FIFO para escritura solamente
    fd = open(FIFO_FILE, O_WRONLY);
    
    // Bucle infinito para enviar mensajes
    while (1) {
        // Solicita al usuario que ingrese una cadena
        printf("Enter string: ");
        // Lee la cadena ingresada por el usuario
        fgets(readbuf, sizeof(readbuf), stdin);
        
        // Elimina el carácter de nueva línea
        size_t stringlen = strlen(readbuf); // Obtiene la longitud de la cadena
        if (stringlen > 0 && readbuf[stringlen - 1] == '\n') {
            readbuf[stringlen - 1] = '\0'; // Reemplaza el carácter de nueva línea por el carácter nulo
        }

        // Compara la cadena ingresada con la cadena de terminación
        end_process = strcmp(readbuf, end_str);
        if (end_process != 0) { // Si la cadena no es "end"
            // Escribe la cadena en el FIFO
            write(fd, readbuf, strlen(readbuf));
            // Imprime la cadena enviada y su longitud
            printf("FIFOCLIENT: Sent string: \"%s\" and string length is %lu\n", readbuf, strlen(readbuf));

            // Cierra el extremo de escritura para leer la respuesta
            close(fd);

            // Reabre el FIFO para lectura
            fd = open(FIFO_FILE, O_RDONLY);
         
            // Lee la respuesta del servidor
            int read_bytes = read(fd, readbuf, sizeof(readbuf) - 1);
            
            // Cierra el extremo de lectura
            close(fd);

            // Reabre para escritura en la siguiente iteración
            fd = open(FIFO_FILE, O_WRONLY);
            
        } else { // Si la cadena es "end"
            // Escribe la cadena de terminación en el FIFO
            write(fd, readbuf, strlen(readbuf));
            // Imprime la cadena enviada y su longitud
            printf("FIFOCLIENT: Sent string: \"%s\" and string length is %lu\n", readbuf, strlen(readbuf));
            close(fd); // Cierra el FIFO
            break; // Sale del bucle
        }
    }

    return 0; // Termina el programa con éxito
}
