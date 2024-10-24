# Productor-Consumidor con Hilos en C

Este proyecto implementa el clásico problema **Productor-Consumidor** utilizando hilos (threads) en C con la biblioteca **pthread**. El propósito de este programa es simular la interacción entre múltiples productores y consumidores utilizando variables de condición y mutexes para sincronizar el acceso a una variable compartida.

## Descripción del Proyecto

El problema del **Productor-Consumidor** involucra dos tipos de entidades:
- **Productores**: Crean (o "producen") unidades de trabajo, que en este caso se representan incrementando una variable compartida.
- **Consumidores**: Consumen (o "eliminan") unidades de trabajo, lo que se representa decrementando dicha variable compartida.

La sincronización entre productores y consumidores se logra utilizando **variables de condición** y **mutexes** para asegurar que no haya condiciones de carrera (race conditions) cuando varios hilos intentan acceder y modificar la variable compartida simultáneamente.

### Componentes Clave

- **Mutexes (`pthread_mutex_t`)**: Se utilizan para bloquear el acceso a secciones críticas del código que modifican la variable compartida `counter`.
- **Variables de Condición (`pthread_cond_t`)**: Permiten que los productores y consumidores se "duerman" cuando no pueden realizar su trabajo, esperando a que otra entidad despierte (notifique) cuando sea posible continuar.

## Requisitos Previos

Para compilar y ejecutar este programa, necesitas:
- Un compilador de C como `gcc`.
- Soporte para la biblioteca **pthread** (normalmente incluida en sistemas Linux).

## Estructura del Código

El proyecto está implementado en un único archivo de C que contiene:

1. **Variables Globales**:
   - `counter`: El recurso compartido entre productores y consumidores.
   - `counter_mutex`: Protege el acceso a `counter`.
   - `condVarProd` y `condVarCons`: Variables de condición para sincronizar productores y consumidores.

2. **Funciones**:
   - `productor`: Función ejecutada por los hilos productores, incrementa el valor de `counter` y avisa a los consumidores cuando hay algo disponible.
   - `consumidor`: Función ejecutada por los hilos consumidores, decrementa el valor de `counter` y avisa a los productores cuando pueden seguir produciendo.
   - `main`: Crea los hilos productores y consumidores y los coordina.

## Instrucciones de Compilación y Ejecución

### Compilación

Puedes compilar el programa utilizando el siguiente comando en un entorno Linux con `gcc`:

```bash
gcc -o productor_consumidor productor_consumidor.c -lpthread
