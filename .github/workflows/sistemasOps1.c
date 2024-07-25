#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct persona {
    char nombre[100];
    char apellido[60];
    char carrera[100];
    char semestre[100];
    char exp[1500];
};

struct materia {
    char nombre[100];
    int creditos;
    char salon[100];
};
struct materia materias[] = {
    {"Estructuras de datos", 3, "Ingenieria: 106"},
    {"Sistemas de informacion", 3, "Baron: 608"},
    {"Sistemas Operativos", 3, "Baron: 002"},
    {"Hoja de calculo", 2, "Baron: s101"},
    {"Fundamentos de software", 3, "Ingenieria: 96C"},
    {"Etica", 2, "Baron: 403"},
    {"Probabilidad", 3, "Baron: 503"}
};
void asignarAMemoria(int *p, int v){
  *p=v;
}
struct materia* buscarMateria(char *nombre) {
    for(int i=0; i <7; i++) {
        if (strcmp(materias[i].nombre, nombre) == 0) {
            return &materias[i];
        }
    }
    return NULL;
}
/*
void carreraDeBuses() {
    int pos = 0;
    int max_pos = 10;
    while(pos <= max_pos) {

        printf("\033[H\033[J");

        for(int i = 0; i < pos; i++) {
            printf(" ");
        }

        printf("  ----\n");
        for(int i = 0; i < pos; i++) {
            printf(" ");
        }
        printf(" /--|\\\n");
        for(int i = 0; i < pos; i++) {
            printf(" ");
        }
        printf("O----O\n");

        pos++;

        usleep(200000); // Pausa de 200 milisegundos
    }

}
*/
struct persona p1 = {"Sergio","Lopez",  "Ingenieria de Sistemas", "Tercer Semestre",
    "\n\tTengo experiencia en back end y front end de desarrollo de proyecto de RenCar, aplicacion usada para la gestion "
    "\tde automoviles y servicio de parqueadero. Desarrolle dos proyecto de redes y telocomucaciones de manera\n "
    "\tindividual siendo el primero el modelaje y conexion a NAT\n"
    "\tde dos edificios con 4 departamentos los cuales adicionalmente contaron con servidor DNS, redundancia en\n"
    "\tlas conexiones y protocolo de Spanning Three en las mismas. Todo esto dividiendo la red en varias subredes\n"
    "\ty realizando las diferentes asignaciones a cada uno de los departamentos.\n"
    "\tTodo esto haciendo uso de la herramineta GNS3 y WireShark. El segundo proyecto desarrollado fue\n"
    "\tel diseño y programacion de un servidor DNS en Java, completamente funcional para ser\n"
    "\timplementado dentro de la topologia previamente disañada y probada en GNS3.\n "
    "\tActualmente me encuentro cursando certificacion de ISC2 en seguridad de la informacion asi como\n "
    "\tdesenvolviendome en desarrollo WEB en HTML, CSS y Java Script.\n"};


int main(int argc, char *argv[]) {
    int valor;
    int* opcion=&valor;
    char repetir = 0;

    printf("Miauuuuuu %d\n ", *opcion);

    do{
        printf("Ingrese la opcion que desea escoger\n"
               "\t1. Para nombre y carrera.\n"
               "\t2.Para nombre y experiencia.\n"
               "\t3.Para nombre.\n"
               "\t4.Para buscar materia.\n"
              /* "\t5.Para nombre y carrera de buses.\n")*/;
        scanf("%d",opcion);
        switch (*opcion) {
            case 1:
                const char *presentacion = "\t\t!!!!!!!!!!!!!!!PRESENTACION!!!!!!!!!!!!!!!\n"
                                           "\tNOMBRE: \t%s\n"
                                           "\tAPELLIDO:\t%s\n"
                                           "\tCARRERA: \t%s\n"
                                           "\tSEMESTRE: \t%s\n"
                                           "\t<---------------------------MATERIAS--------------------------->\n";
            printf("+");
            for (int i = 0; i < 80; i++) {
                printf("-");
            }
            printf("+\n");

            printf(presentacion, p1.nombre,p1.apellido, p1.carrera, p1.semestre);

            for (int i = 0; i < 7; i++) {
                printf("\t%s, \t%d creditos, en \t%s\n", materias[i].nombre, materias[i].creditos, materias[i].salon);
            }

            printf("\n");
            printf("+");
            for (int i = 0; i < 80; i++) {
                printf("-");
            }
            printf("+\n");


            break;
            case 2:
                printf("\t+");
            for (int i = 0; i < 110; i++) {
                printf("-");
            }
            printf("+\n");
                presentacion = "\t\t!!!!!!!!!!!!!!!PRESENTACION!!!!!!!!!!!!!!!\n"
                                      "\tNOMBRE: \t%s\n"
                                      "\tAPELLIDO:\t%s\n"
                                      "%s";
            printf(presentacion,p1.nombre,p1.apellido, p1.exp);
            printf("\t+");
            for (int i = 0; i < 110; i++) {
                printf("-");
            }
            printf("+\n");

            break;
            case 3:

                printf("+");
            for (int i = 0; i < 80; i++) {
                printf("-");
            }
            printf("+\n");
                presentacion = "\t\t!!!!!!!!!!!!!!!PRESENTACION!!!!!!!!!!!!!!!\n"
                                                 "\tNOMBRE: \t%s\n"
                                                 "\tAPELLIDO:\t%s\n";
            printf(presentacion,p1.nombre,p1.apellido);
            printf("+");
            for (int i = 0; i < 80; i++) {
                printf("-");
            }
            printf("+\n");
            break;
            case 4:
                char valor1[100];
            char* miau=valor1;
            printf("Ingrese la materia a encontrar: -> ");
            scanf(" %[^\n]",miau);
            if(buscarMateria(miau)!=NULL) {
                printf("+");
                for (int i = 0; i < 80; i++) {
                    printf("-");
                }
                printf("+\n");
                printf("\tLa materia solicitada es:\n"
                       "\tNOMBRE: %s\n"
                       "\tCREDITOS: %d\n"
                       "\tSALON: %s\n",buscarMateria(miau)->nombre,buscarMateria(miau)->creditos,buscarMateria(miau)->salon);
                printf("+");
                for (int i = 0; i < 80; i++) {
                    printf("-");
                }
                printf("+\n");
            }else {
                printf("Materia no encontrada\n");
            }
            break;
           /* case 6:
                carreraDeBuses();
            break;*/
            default:
                printf("+");
            for (int i = 0; i < 50; i++) {
                printf("-");
            }
            printf("+\n");
                printf("Selecciona una de las opciones validas :)");
            printf("\n+");
            for (int i = 0; i < 50; i++) {
                printf("-");
            }
            printf("+\n");
        }
        printf("\n\tDesea realizar algun otro proceso? (Ss/Nn) \n");
        scanf(" %c", &repetir);
    }while  (repetir=='s'||repetir=='S');
    return 0;

}
