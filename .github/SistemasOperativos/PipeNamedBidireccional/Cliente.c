/*********************************************
 * Sergio Lopez Ayala
 * Desarrollador de Software
 * Bogota
 * Fecha: 17 de octubre de 2024
 * Taller Pipe Named Bidireccional
 * -------------LADO DEL CLIENTE-------------
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_FILE "/tmp/fifo_twoway"  // Ruta del archivo FIFO utilizado para la comunicación

int main() {
   int fd;                // Descriptor de archivo para el FIFO
   int end_process;       // Control para verificar si el usuario ha terminado el proceso
   int stringlen;         // Longitud de la cadena ingresada por el usuario
   int read_bytes;        // Bytes leídos desde el FIFO
   char readbuf[80];      // Buffer para almacenar los datos leídos
   char end_str[5];       // Cadena "end" para finalizar el proceso

   // Mensaje de inicio del cliente
   printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");

   // Abre el FIFO en modo lectura/escritura
   fd = open(FIFO_FILE, O_RDWR);

   // Copiamos la cadena "end" en la variable `end_str` para comparar luego
   strcpy(end_str, "end");

   // Bucle infinito para enviar y recibir mensajes del servidor
   while (1) {
      printf("Enter string: ");  // Solicita al usuario ingresar una cadena
      fgets(readbuf, sizeof(readbuf), stdin);  // Lee la entrada del usuario

      // Calcula la longitud de la cadena y elimina el salto de línea
      stringlen = strlen(readbuf);
      readbuf[stringlen - 1] = '\0';  // Reemplaza el salto de línea con el carácter nulo

      // Compara la cadena ingresada con "end" para saber si se debe terminar el proceso
      end_process = strcmp(readbuf, end_str);

      // Si la cadena ingresada no es "end", envía al servidor y espera la respuesta
      if (end_process != 0) {
         // Envía la cadena al servidor a través del FIFO
         write(fd, readbuf, strlen(readbuf));

         // Muestra la cadena enviada
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));

         // Lee la respuesta del servidor (cadena invertida)
         read_bytes = read(fd, readbuf, sizeof(readbuf));

         // Añade el carácter nulo al final de la cadena leída para asegurar su integridad
         readbuf[read_bytes] = '\0';

         // Muestra la cadena invertida recibida del servidor
         printf("FIFOCLIENT: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));
      } else {
         // Si se ingresa "end", se envía la cadena final, se cierra el FIFO y se termina el proceso
         write(fd, readbuf, strlen(readbuf));
         printf("FIFOCLIENT: Sent string: \"%s\" and string length is %d\n", readbuf, (int)strlen(readbuf));
         close(fd);  // Cierra el archivo FIFO
         break;  // Sale del bucle y termina la ejecución del cliente
      }
   }

   return 0;  // Fin del programa
}
