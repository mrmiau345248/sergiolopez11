/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Suma de Números con Sentinela
 * Descripción: 
 *   Esta función realiza la suma de una serie de números
 *   ingresados por el usuario. La entrada de números continúa
 *   hasta que se introduce un 0, momento en el cual la función
 *   imprime la suma acumulada.
 **************************************************/
void suma() {
    int x;
    int suma = 0;
    do {
        scanf("%d", &x);
        suma += x;
    } while (x != 0);
    printf("La suma es: %d\n", suma);
}

/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Copia de Cadenas y Dirección de Memoria
 * Descripción: 
 *   La función copia una cadena de texto en otra utilizando la 
 *   función strcpy y muestra la dirección de memoria de la cadena
 *   original. Está diseñada para ilustrar la manipulación de 
 *   cadenas y el uso de punteros en C.
 **************************************************/
void direccion() {
    char p[50], q[50];
    printf("Address of p = %p\n", p);
    strcpy(p, "Hello, I'm the best in Operating Systems!!!");
    strcpy(q, "Goodbye");
    printf("String copied\n");
    printf("%s\n", q);
}

/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Asignación Dinámica de Memoria con calloc
 * Descripción: 
 *   Esta función pide al usuario el número de elementos,
 *   asigna memoria dinámica para esos elementos utilizando 
 *   calloc, y luego calcula e imprime la suma de los elementos
 *   ingresados. Finalmente, libera la memoria asignada.
 **************************************************/
void funcion3() {
    int n, *ptr, sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    ptr = (int*) calloc(n, sizeof(int));
    if (ptr == NULL) {
        printf("Error! Memory not allocated");
        exit(0);
    }
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    printf("Sum = %d\n", sum);
    free(ptr);
    ptr = NULL; // To avoid dangling pointer
}

/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Reasignación Dinámica de Memoria
 * Descripción: 
 *   Esta función demuestra cómo asignar y luego reasignar
 *   memoria dinámica usando malloc y realloc. Muestra las
 *   direcciones de memoria asignadas antes y después de la 
 *   reasignación, ilustrando cómo la memoria puede cambiar.
 **************************************************/
void funcion4() {
    int *ptr, i, n1, n2;
    printf("Enter size: ");
    scanf("%d", &n1);
    ptr = (int*) malloc(n1 * sizeof(int));
    if (ptr == NULL) {
        printf("Error! Memory not allocated\n");
        exit(0);
    }
    printf("Addresses of previously allocated memory: \n");
    for (i = 0; i < n1; ++i)
        printf("%p\n", (void*)(ptr + i));

    printf("Enter the new size: ");
    scanf("%d", &n2);
    // reallocating the memory
    ptr = realloc(ptr, n2 * sizeof(int));
    if (ptr == NULL) {
        printf("Error! Memory not reallocated\n");
        exit(0);
    }
    printf("Addresses of newly allocated memory: \n");
    for (i = 0; i < n2; ++i)
        printf("%p\n", (void*)(ptr + i));
    free(ptr);
    ptr = NULL; // To avoid dangling pointer
}

/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Manejo de Cadenas Dinámicas
 * Descripción: 
 *   Esta función ilustra cómo asignar memoria dinámica para 
 *   cadenas de caracteres, copiar una cadena en dicha memoria,
 *   y luego liberarla. Permite ver el uso de punteros y la 
 *   manipulación de memoria dinámica en cadenas.
 **************************************************/
void funcion5() {
    char *a = function("Hi, It's fun to learn");
    char *b = function("systems engineer");
    printf("From main: %s %s\n", a, b);
    free(a); // Free dynamically allocated memory
    free(b); // Free dynamically allocated memory
}

/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Asignación de Memoria para Cadenas
 * Descripción: 
 *   Esta función recibe una cadena como parámetro, asigna 
 *   memoria dinámica para almacenar una copia de esa cadena,
 *   y devuelve un puntero a la memoria asignada. Muestra la 
 *   importancia de verificar la asignación de memoria.
 **************************************************/
char *function(char *p) {
    char *q = (char*) malloc(strlen(p) + 1); // Allocate memory dynamically
    if (q != NULL) {
        strcpy(q, p);
        printf("From q: the string is %s\n", q);
    } else {
        printf("Error! Memory not allocated for q\n");
    }
    return q; // Return the dynamically allocated memory
}

/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Manipulación de Punteros a Variables
 * Descripción: 
 *   La función muestra cómo trabajar con punteros a variables,
 *   imprimir sus valores y direcciones de memoria. Es útil para 
 *   entender la relación entre punteros y variables en C.
 **************************************************/
void funcion6() {
    int variable = 123;
    int *ptr = &variable;
    printf("Valor de la Variable %d \n", variable);
    printf("Dirección de memoria de la Variable %p\n", &variable);
    printf("Dirección a la que apunta el puntero %p \n", (void*)ptr);
    printf("Valor de la Variable %i \n", *ptr);
}

/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Vector de Punteros
 * Descripción: 
 *   Esta función demuestra el uso de un vector de punteros para
 *   almacenar y acceder a diferentes variables. Permite ver cómo
 *   los punteros pueden apuntar a diferentes elementos y cómo 
 *   acceder a estos valores a través del vector.
 **************************************************/
void funcion7() {
    int *vectorPunteros[3];
    int p = 40, q = 80, r = 120;
    vectorPunteros[0] = &p;
    vectorPunteros[1] = &q;
    vectorPunteros[2] = &r;
    printf("\nForma de acceso al vector de punteros: \n");
    for (int i = 0; i < 3; i++) {
        printf("Para la dirección: %p \t el valor = %d\n", (void*)vectorPunteros[i], *vectorPunteros[i]);
    }
}

/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Suma de Valores Usando Punteros
 * Descripción: 
 *   Esta función pide dos valores al usuario, los asigna a 
 *   punteros, y luego calcula e imprime la suma de estos valores
 *   usando los punteros. Es una ilustración básica del uso de 
 *   punteros para realizar operaciones aritméticas.
 **************************************************/
void funcion8() {
    int valor1, valor2;
    int *ptrV1, *ptrV2;
    ptrV1 = &valor1;
    ptrV2 = &valor2;
    printf("\nIngrese dos valores a ser sumados \n");
    scanf("%d %d", &valor1, &valor2);
    printf("\nLa suma es = %d\n", *ptrV1 + *ptrV2);
}

/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Manipulación Dinámica de Matrices
 * Descripción: 
 *   Esta función ilustra cómo asign
 *   memoria dinámica para una matriz 2D basada en el número de
 *   filas y columnas proporcionadas por el usuario como argumentos
 *   del programa. La función también inicializa la matriz con valores
 *   de productos de índices y finalmente libera la memoria asignada.
 **************************************************/
void funcion9(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Se requieren dos argumentos: número de filas y columnas\n");
        return;
    }

    int rows, cols;
    int **matrix;

    rows = atoi(argv[1]);
    cols = atoi(argv[2]);

    // Asignar memoria para las filas de la matriz
    matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        printf("Error al asignar memoria para las filas\n");
        return;
    }

    // Asignar memoria para cada columna de cada fila
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Error al asignar memoria para las columnas\n");
            // Liberar la memoria previamente asignada
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return;
        }
    }

    // Inicializar y mostrar la matriz
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * j;
        }
    }

    printf("Matriz:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Liberar memoria
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Declaración y Uso de Punteros
 * Descripción: 
 *   Esta función demuestra cómo declarar y usar punteros
 *   para almacenar direcciones de variables enteras. Se
 *   ilustra la importancia de inicializar punteros y la 
 *   relación entre punteros y variables.
 **************************************************/
void funcion10() {
    int valor1, valor2;
    int *ptrV1, *ptrV2;
    ptrV1 = &valor1;
    ptrV2 = &valor2;
}

/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Punteros Dobles
 * Descripción: 
 *   Esta función ilustra el uso de punteros dobles (punteros a
 *   punteros) para acceder a variables y sus valores. Muestra 
 *   cómo se puede usar un puntero doble para obtener la dirección
 *   de un puntero y el valor final de la variable apuntada.
 **************************************************/
void funcion11() {
    int var = 480, *varptr = &var, **doubleptr = &varptr;
    printf("Valor de la Variable \t\t = %d\n", var);
    printf("Valor del puntero \t\t = %d\n", *varptr);
    printf("Valor del puntero doble \t = %d\n", **doubleptr);
    printf("Dirección de la Variable \t = %p\n", &var);
    printf("Dirección del puntero \t\t = %p\n", varptr);
    printf("Dirección del puntero doble \t = %p\n", doubleptr);
}

/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Asignación Dinámica y Liberación de Memoria
 * Descripción: 
 *   Esta función asigna memoria dinámica utilizando malloc
 *   y demuestra cómo almacenar y mostrar valores en un arreglo.
 *   También se asegura de liberar la memoria asignada para evitar
 *   fugas de memoria.
 **************************************************/
void funcion12() {
    int *varptr1 = malloc(4 * sizeof(int));
    int *varptr2 = malloc(sizeof(int[4]));
    int *varptr3 = malloc(4 * sizeof *varptr3);

    if (varptr1) {
        for (int i = 0; i < 4; i++)
            varptr1[i] = i * i;
        for (int i = 0; i < 4; i++)
            printf("varptr[%d]\t == %d\n", i, varptr1[i]);
    }
    printf("Se libera memoria reservada\n");
    free(varptr1);
    free(varptr2);
    free(varptr3);
}

/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Asignación y Uso de Memoria con calloc
 * Descripción: 
 *   Esta función asigna memoria dinámica para almacenar valores 
 *   enteros utilizando calloc, que inicializa la memoria asignada
 *   a cero. La función muestra los valores almacenados y luego 
 *   libera la memoria.
 **************************************************/
void funcion13() {
    int *varptr1 = calloc(4, sizeof(int));
    int *varptr2 = calloc(1, sizeof(int[4]));
    int *varptr3 = calloc(4, sizeof *varptr3);

    if (varptr1) {
        for (int i = 0; i < 4; i++)
            printf("varptr2[%d]\t == %d\n", i, varptr2[i]);
    }
    printf("Se libera memoria reservada\n");
    free(varptr1);
    free(varptr2);
    free(varptr3);
}

/*************************************************
 * Autor: Sergio Lopez Ayala
 * Fecha: 01 / 08 / 24 - 08 / 08 / 24
 * Materia: Sistemas Operativos
 * Tema: Repetición de Función Anterior
 * Descripción: 
 *   Esta función es idéntica a la anterior, demostrando 
 *   nuevamente el uso de calloc para asignar memoria dinámica
 *   y su posterior liberación. Esto refuerza el concepto de 
 *   asignación de memoria dinámica en C.
 **************************************************/
void funcion14() {
    int *varptr1 = calloc(4, sizeof(int));
    int *varptr2 = calloc(1, sizeof(int[4]));
    int *varptr3 = calloc(4, sizeof *varptr3);

    if (varptr1) {
        for (int i = 0; i < 4; i++)
            printf("varptr2[%d]\t == %d\n", i, varptr2[i]);
    }
    printf("Se libera memoria reservada\n");
    free(varptr1);
    free(varptr2);
    free(varptr3);
}
