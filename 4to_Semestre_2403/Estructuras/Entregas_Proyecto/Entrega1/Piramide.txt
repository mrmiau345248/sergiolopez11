#ifndef FIGURA_H
#define FIGURA_H

#include "Vertice.h"
#include <vector>

using namespace std;

class Figura {
private:
    int figura;
    int cantVert;
    vector<Vertice> vertices;

public:
    Figura() : figura(0), cantVert(0), vertices() {}

    Figura(int figura, int cantVert,  vector<Vertice>& vertices){
        this -> figura= figura;
        this -> cantVert= cantVert;
        this -> vertices= vertices;
    }
    // Setter para figura
    void setFigura(int nuevaFigura) {
        figura = nuevaFigura;
    }

    // Getter para figura
    int getFigura()  {
        return figura;
    }

    // Setter para cantVert
    void setCantVert(int nuevaCantVert) {
        cantVert = nuevaCantVert;
    }

    // Getter para cantVert
    int getCantVert()  {
        return cantVert;
    }

    // Setter para vertices
    void setVertices( vector<Vertice>& nuevosVertices) {
        vertices = nuevosVertices;
    }

    // Getter para vertices
     vector<Vertice>& getVertices()  {
        return vertices;
    }

    // Método para buscar un vértice por nombre
    Vertice buscarVertice(int nombre)  {
        for (Vertice vertice : vertices) {
            if (vertice.getNombre() == nombre) {
                return vertice;
            }
        }
        // Aquí podrías lanzar una excepción o retornar un valor por defecto si no se encuentra el vértice
        return Vertice();  // Retorna un objeto Vertice por defecto
    }

    // Método para agregar un vértice
    void agregarVertice( Vertice& vertice) {
        vertices.push_back(vertice);
    }

     int calcArista(){
          return cantVert;
      } 

string impriVertices() {
    string s;
    for (size_t i = 0; i < vertices.size(); ++i) {
        s += to_string(vertices[i].getNombre());
        if (i != vertices.size() - 1) {
            s += " ";  // Agrega un espacio entre los nombres, pero no al final.
        }
    }
    return s;
}

};

#endif // FIGURA_H
