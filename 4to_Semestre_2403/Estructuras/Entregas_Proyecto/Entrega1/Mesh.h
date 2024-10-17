#ifndef PROYECTOEST_MESH_H
#define PROYECTOEST_MESH_H

#include <iostream>
#include <string>
#include <vector>
#include "Figura.h"

using namespace std;

class Mesh {
private:
    string nombre;
    int n;
    vector<Figura> figuras;
    vector<Vertice> vertices;

public:
    Mesh() : nombre(""), n(0), figuras() , vertices(){}

// Constructor con parámetros
    Mesh( const string& nombre, int n,  const vector<Figura>& figuras, const vector<Vertice>& vertices) {
    this->nombre = nombre;
    this->n = n;
    this->vertices = vertices;
    this->figuras = figuras;
}
    // Setter para nombre
    void setNombre( const string& nuevoNombre) {
        nombre = nuevoNombre;
    }

    // Getter para nombre
const string getNombre()const {
        return nombre;
    }

    // Setter para n
    void setN(int nuevoN)  {
        n = nuevoN;
    }

    // Getter para n
    int getN() const  {
        return n;
    }

    // Setter para figuras
    void setFiguras( const vector<Figura>& nuevasFiguras) {
        figuras = nuevasFiguras;
    }

    // Getter para figuras
const vector<Figura>& getFiguras() const  {
        return figuras;
    }

    // Setter para vertices
    void setVertices(const  vector<Vertice>& nuevosVertices) {
        vertices = nuevosVertices;
    }

    // Getter para vertices
 vector<Vertice>& getVertices()   {
        return vertices;
    }

    // Método para contar el número de figuras
    int cantFiguras()  {
        return figuras.size();
    }
   Vertice buscarVertice(int nombre) {
       for(Vertice v:vertices){
           if(v.getNombre()==nombre){
               return v;
           }
       }
       return Vertice();
   }

   Figura buscarFigura(int nombre) {
       for (Figura figura : figuras){
           if (figura.getFigura() == nombre){
               return figura;
           }
       }
       return Figura();
   }

    // Método para agregar una figura al vector
    void agregarFigura( Figura& figura) {
        figuras.push_back(figura);
    }

    // Método para agregar un vértice al vector
    void agregarVertice( Vertice& vertice) {
        vertices.push_back(vertice);
    }

    // Método para contar la cantidad de aristas
    int cantAristas() {
        int cant = 0;
        for (int i = 0; i < figuras.size(); i++) {
            cant += figuras[i].calcArista();
        }
        return cant;
    }

    // Método para obtener el punto mínimo (Pmin)
    vector<int> Pmin() {
        vector<int> v;
        if (figuras.empty()) return v;

        int xmin = figuras[0].buscarVertice(0).getX();
        int ymin = figuras[0].buscarVertice(0).getY();
        int zmin = figuras[0].buscarVertice(0).getZ();

        for (int i = 0; i < figuras.size(); i++) {
             vector<Vertice>& verticesFigura = figuras[i].getVertices();
            for (int j = 0; j < verticesFigura.size(); j++) {
                if (verticesFigura[j].getX() < xmin) xmin = verticesFigura[j].getX();
                if (verticesFigura[j].getY() < ymin) ymin = verticesFigura[j].getY();
                if (verticesFigura[j].getZ() < zmin) zmin = verticesFigura[j].getZ();
            }
        }

        v.push_back(xmin);
        v.push_back(ymin);
        v.push_back(zmin);

        return v;
    }

    // Método para obtener el punto máximo (Pmax)
    vector<int> Pmax() {
        vector<int> v;
        if (figuras.empty()) return v;

        int xmax = figuras[0].buscarVertice(0).getX();
        int ymax = figuras[0].buscarVertice(0).getY();
        int zmax = figuras[0].buscarVertice(0).getZ();

        for (int i = 0; i < figuras.size(); i++) {
             vector<Vertice>& verticesFigura = figuras[i].getVertices();
            for (int j = 0; j < verticesFigura.size(); j++) {
                if (verticesFigura[j].getX() > xmax) xmax = verticesFigura[j].getX();
                if (verticesFigura[j].getY() > ymax) ymax = verticesFigura[j].getY();
                if (verticesFigura[j].getZ() > zmax) zmax = verticesFigura[j].getZ();
            }
        }

        v.push_back(xmax);
        v.push_back(ymax);
        v.push_back(zmax);

        return v;
    }
};

#endif //PROYECTOEST_MESH_H
