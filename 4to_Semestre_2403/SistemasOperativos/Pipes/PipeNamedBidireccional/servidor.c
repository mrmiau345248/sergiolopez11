/*********************************************
 * Sergio Lopez Ayala
 * Desarrollador de Software
 * Bogota
 * Fecha: 17 de octubre de 2024
 * Taller Pipe Named Bidireccional
 * -------------LADO DEL SERVIDOR-------------
 ***************************************************/

#include <stdio.h>      
#include <stdlib.h>    
#include <sys/types.h>  
#include <sys/stat.h>   
#include <fcntl.h>      

#define FIFO_FILE "/tmp/fifo_twoway"  // Define el nombre y ubicación del archivo FIFO

// Prototipo de la función para invertir una cadena de caracteres
void reverse_string(char *);  

int main() {
   int fd;                // Descriptor de archivo para el FIFO
   char readbuf[80];      // Buffer para almacenar la cadena leída del cliente
   char end[10];          // Cadena que indica el final del proceso
   int to_end;            // Variable para controlar si se ha recibido la cadena "end"
   int read_bytes;        // Variable para almacenar el número de bytes leídos

   /* Crear el FIFO si no existe */
   // `mkfifo` crea un archivo FIFO con permisos de lectura/escritura. Si ya existe, no hace nada.
   mkfifo(FIFO_FILE, S_IFIFO|0640);

   // Se copia la cadena "end" en la variable `end`, que se usará para terminar la ejecución
   strcpy(end, "end");

   // Abrimos el FIFO en modo lectura/escritura (O_RDWR)
   // El servidor necesita leer y escribir en el mismo FIFO
   fd = open(FIFO_FILE, O_RDWR);

   // Bucle infinito para leer las cadenas enviadas por el cliente
   while (1) {
      // Leer los datos del cliente del FIFO en `readbuf`
      // `read` retorna el número de bytes leídos
      read_bytes = read(fd, readbuf, sizeof(readbuf));

      // Se agrega un carácter nulo al final del buffer para asegurarse de que sea una cadena válida
      readbuf[read_bytes] = '\0';

      // Mostrar la cadena recibida en el servidor
      printf("FIFOSERVER: Received string: \"%s\" and length is %d\n", readbuf, (int)strlen(readbuf));

      // Comparar la cadena recibida con "end" para determinar si se debe finalizar el proceso
      to_end = strcmp(readbuf, end);

      // Si se recibe la cadena "end", se cierra el FIFO y se sale del bucle
      if (to_end == 0) {
         close(fd);  // Cierra el descriptor de archivo
         break;      // Rompe el bucle y termina el programa
      }

      // Llama a la función para invertir la cadena recibida
      reverse_string(readbuf);

      // Mostrar la cadena invertida que se enviará al cliente
      printf("FIFOSERVER: Sending Reversed String: \"%s\" and length is %d\n", readbuf, (int) strlen(readbuf));

      // Escribir la cadena invertida de vuelta al FIFO para que el cliente la reciba
      write(fd, readbuf, strlen(readbuf));

      /* 
      sleep(2) - Espera 2 segundos para asegurar que el proceso cliente tenga tiempo de leer
      la respuesta antes de que el servidor vuelva a escribir otra cadena. Esto previene
      que el servidor lea su propia respuesta si ambos procesos intentan acceder al FIFO
      simultáneamente.
      */
      sleep(2);
   }

   // Finaliza el programa
   return 0;
}

// Función que invierte la cadena de caracteres recibida
void reverse_string(char *str) {
   int last, limit, first;
   char temp;

   // `last` es el índice del último carácter de la cadena (antes del carácter nulo)
   last = strlen(str) - 1;

   // `limit` es el punto medio de la cadena, usado para saber cuándo detener el intercambio de caracteres
   limit = last / 2;

   // `first` es el índice del primer carácter de la cadena
   first = 0;

   // Bucle para intercambiar los caracteres de los extremos hacia el centro
   while (first < last) {
      // Intercambiar el carácter en la posición `first` con el de la posición `last`
      temp = str[first];
      str[first] = str[last];
      str[last] = temp;

      // Mover los índices hacia el centro de la cadena
      first++;
      last--;
   }

   // No es necesario retornar nada, ya que la cadena fue modificada en su lugar
   return;
}
