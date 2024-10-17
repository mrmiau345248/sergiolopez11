#ifndef PROYECTOEST_VERTICE_H
#define PROYECTOEST_VERTICE_H

#include <iostream>

class Vertice {
private:
    int nombre, x, y, z;

public:
    // Constructor por defecto
    Vertice() : nombre(0), x(0), y(0), z(0) {}

    // Constructor con parámetros
    Vertice(int nombre, int x, int y, int z) : nombre(nombre), x(x), y(y), z(z) {}

    // Getters
    int getNombre()  { return nombre; }
    int getX()  { return x; }
    int getY()  { return y; }
    int getZ()  { return z; }

    // Setters
    void setNombre(int nuevoNombre) { nombre = nuevoNombre; }
    void setX(int nuevoX) { x = nuevoX; }
    void setY(int nuevoY) { y = nuevoY; }
    void setZ(int nuevoZ) { z = nuevoZ; }

    // Método para mostrar información
    void mostrarInfo()  {
        std::cout << "Nombre: " << nombre << ", Coordenadas: (" << x << ", " << y << ", " << z << ")" << std::endl;
    }

   
};

#endif // PROYECTOEST_VERTICE_H
