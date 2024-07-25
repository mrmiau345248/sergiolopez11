/****************************************************************
Autor: Sergio Lopez
Materia: Sistemas Operativos
Fecha: 25/07/2024
Tema: Entrada y Salida en C
********************************************************/
#include <stdio.h>
#include "funciones.h"

float pi= 3.1416f;

int main (int argc, char *argv[]) {
    char repetir = 0;

    do {
        printf("Ingrese: \n1 Para suma de enteros\n2 Para area de circulo\n3 Para calcular el volumen de su circulo"
               "\n4 Para calcular el volumen de un cono\n5 Para calcular la tangente\n");
        int opcion;
        scanf("%d",&opcion);
        float radio;
        float altura,c,c1;

        switch (opcion){
            case 1:
                int a, b;

            printf("Ingresa los valores que quieres sumar:\n");
            scanf("%d %d", &a, &b);
            printf("El resultado es: %d\n", a + b);
            break;

            case 2 :
                printf("Ingrese el valor del radio del circulo que desea calcular el area: \n");
            scanf("%f",&radio);
            printf("El area de su circulo es: %.2f\n", calcularCirculo(radio));
            break;
            case 3:
                printf("Ingrese el valor del radio del circulo que desea calcular el volumen: \n");
            scanf("%f", &radio);
            printf("El volumen de su circulo es: %.2f ", calcularVolumenCirculo(radio));
            break;
            case 4:
                printf("Ingrese el valor del radio y altura del cono: \n");
            scanf("%f%f", &radio,&altura);
            printf("El valor del area del cono es: %.2f ", calcularAreaCono(radio,altura));
            break;
            case 5:
                printf("Ingrese el valor de los catetos: \n");
            scanf("%f""%f", &c,&c1);
            printf("La hipotenusa es: %.2f ",calcularHipo(c,c1));

            default: ;
        }

        printf("\n\tDesea realizar algun otro proceso? (Ss/Nn) \n");
        scanf(" %c", &repetir);
    }while  (repetir=='s'||repetir=='S');
    return 0;
}
