/*********************************************
 * Sergio Lopez Ayala
 * Desarrollador de Software
 * Bogota
 * Fecha: 03 de octubre de 2024
 * Parcial 2 Sistemas Operativos
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_FILE "MYFIFO"

void leerArchivo(const char* archivo, int* n, int** arreglo) {
    FILE *MYFIFO = fopen(archivo,"r");

    *arreglo = malloc(*n * sizeof(int)); 
    for (int i = 0; i < *n; i++) {
        fscanf(MYFIFO,"%d",&((*arreglo)[i]));
    }

    fclose(MYFIFO);
    
}


int sumaArreglo(int* arreglo, int n){
int t=0;
for(int i=0; i< n; i++){
    t= arreglo[i];
}
return t;
}

int main( int argc, char* argv[]){
    char readbuf[80];
    const char end[]="FIN";
    if (argc != 5) {
        fprintf(stderr, "Uso: %s N1 archivo00 N2 archivo01\n", argv[0]);
        return EXIT_FAILURE;
    }

   
    int *arr1 = NULL;
    int *arr2 = NULL;
    int cant1 = atoi(argv[1]);
    char* archivo00 = argv[2];
    int cant2 = atoi(argv[3]);
    char* archivo01 = argv[4];


leerArchivo(archivo00, &cant1,&arr1);
leerArchivo(archivo01,&cant2,&arr2);

int fd[2];
int fd1[2];
int fd2[2];

pipe(fd);
pipe(fd1);
pipe(fd2);

pid_t pid1= fork();

if(pid1==0){

int sumaArr1=sumaArreglo(arr1, cant1);
    close(fd[0]);
    printf("GranHijo: [%d] Sum_File1 = %d\n", getpid(), sumaArr1);
    write(fd[1],&sumaArr1, sizeof(sumaArr1));
    close(fd[1]);
    exit (0);
}

pid_t pid2= fork();

if(pid2==0){
int sumaArr2=sumaArreglo(arr2, cant2);
    close(fd1[0]);
    printf("GranHijo: [%d] Sum_File1 = %d\n", getpid(), sumaArr2);
    write(fd1[1],&sumaArr2, sizeof(sumaArr2));
    close(fd1[1]);
    exit (0);
}

pid_t pid3= fork();

if(pid3==0){

int sumaArr3=sumaArreglo(arr1, cant1);
    close(fd2[0]);
   int sumaArr, sumaArr2;
        read(fd[0], &sumaArr, sizeof(sumaArr));
        read(fd1[0], &sumaArr2, sizeof(sumaArr2));
        int t = sumaArr + sumaArr2;
        printf("PrimerHijo: [%d] Suma total = %d\n", getpid(), t);
        write(fd2[1], &t, sizeof(t));
        close(fd2[1]);
        exit(0);
    }


    close(fd[1]);
    close(fd1[1]); 
    close(fd2[1]);
    int t;
    read(fd2[0], &t, sizeof(t));
    printf("Padre: [%d] Suma total = %d\n", getpid(), t);

    // Esperar a que los hijos terminen
    wait(NULL);
    wait(NULL); 
    wait(NULL);

    free(arr1); //libera el arreglo 1
    free(arr2); //libera el arreglo 2
    return 0;

}
