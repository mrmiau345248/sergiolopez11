# Taller de Comunicación Bidireccional con Pipe Nombrado (FIFO)

## Descripción

Este taller implementa un sistema de comunicación bidireccional entre un **cliente** y un **servidor** utilizando un pipe nombrado (FIFO). Los procesos cliente y servidor pueden intercambiar mensajes a través del pipe, donde el cliente envía cadenas al servidor y este devuelve las cadenas invertidas.

### Componentes:

- **Servidor**: Recibe cadenas desde el cliente, invierte las cadenas y las devuelve al cliente.
- **Cliente**: Envía cadenas al servidor y recibe las cadenas invertidas de vuelta. El proceso continúa hasta que el cliente envía la cadena `"end"` para finalizar la comunicación.

## Requisitos

- Sistema operativo basado en Unix/Linux.
- Compilador GCC.
- Conocimientos básicos de programación en C.
- Familiaridad con el uso de pipes (FIFO) para la comunicación entre procesos.
