#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int fd[2]; // Descriptores de archivo, son dos por los tubos. 
    // fd[0] se usa para la lectura de datos
    //fd[1] se usa para escribir los datos

    if (pipe(fd) == -1) { // Las pipes retornan -1 en caso de que no sea exitoso el proceso de abrirlas y 1 en caso de que si.
        printf("No se pudo abrir la pipe\n");
        return 1 ; }
    int id= fork();

    if( id==-1){ // si id es = -1 el fork fallo
        printf("No se pudo hacer el fork\n"); // No es comun recbir este error ya que normalmente se debe tener la capcidad de generar los procesos
                return 4;   }
    if (id==0){// id es el proceso hijo del fork
        int x;
        printf("Ingrese un numero: ");
        scanf("%d",&x);
        
        if( write(fd[1],&x,sizeof(int))==-1){ //Write retorna el numero que contiene si es exitosa, en caso de no serlo, retorna -1
            printf("No se pudo escribir en %d\n", x);
                return 2;        }
        //despues de usar un fd se debe cerrar como se hace con los dmas archivos
        close(fd[1]);
        close(fd[0]); // se cierran los archivos no utilizados

    }else {//id recibio proceso padre, sabemos que no fallo gracias a la verificacion previa

        int y;
       if( read(fd[0], &y,sizeof(int))==-1){
        printf("No se pudo leer en %d\n", y);
                return 3;  
        } //-1 quiere decir que algo fallo y 0 quiere decir que se llego al final del proceso
        close(fd[1]);
        close(fd[0]);
        printf("Obtenido de el proceso hijo: %d\n", y);
    }
    return 0;}
