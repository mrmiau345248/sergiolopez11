# Implementación de Pipes Unidireccionales y Bidireccionales con Servidor y Cliente

Este directorio contiene la implementación de sistemas de comunicación entre procesos utilizando **pipes** (tuberías) tanto **unidireccionales** como **bidireccionales** en el contexto de un **servidor** y un **cliente**. Estos mecanismos de comunicación permiten el intercambio de datos entre procesos de forma eficiente y segura.

## Descripción

### Pipes Unidireccionales
Los pipes unidireccionales permiten que un proceso envíe datos a otro proceso de manera secuencial y en una única dirección. En esta implementación, se ha desarrollado un esquema de servidor-cliente en el cual el servidor envía datos al cliente mediante un pipe unidireccional.

### Pipes Bidireccionales
Los pipes bidireccionales permiten la comunicación en ambas direcciones, lo que significa que tanto el servidor como el cliente pueden enviar y recibir datos simultáneamente. Aquí se implementa una solución donde el servidor y el cliente pueden intercambiar mensajes en tiempo real a través de un pipe bidireccional.

## Contenido

- **Servidor Unidireccional:** El servidor envía mensajes al cliente a través de un pipe unidireccional.
- **Cliente Unidireccional:** El cliente recibe mensajes desde el servidor por un pipe unidireccional.
- **Servidor Bidireccional:** El servidor puede enviar y recibir datos del cliente a través de un pipe bidireccional.
- **Cliente Bidireccional:** El cliente puede intercambiar mensajes con el servidor mediante un pipe bidireccional.

## Requisitos

- Sistema operativo Linux o cualquier sistema compatible con pipes POSIX.
- Compilador compatible con C o C++.
- Conocimientos básicos de comunicación entre procesos (IPC) en sistemas Unix/Linux.

## Ejecución

1. Compila los archivos de código fuente correspondientes al servidor y cliente.
   ```bash
   gcc servidor.c -o servidor
   gcc cliente.c -o cliente
