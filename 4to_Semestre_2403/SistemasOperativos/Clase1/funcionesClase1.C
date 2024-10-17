//
// Created by sl397 on 25/07/2024.
//
#include <math.h>
float pi= 3.1416f;

float calcularCirculo(float r) {
    float area= pi*(pow(r,2));
    return area;
}
float calcularVolumenCirculo(float r){
    float volumen= (4/3)*(pi*(pow(r,3)));
    return volumen;
}
float calcularAreaCono(float r, float h) {

    float areaC= (pi*(pow(r,2))*h)/3;
    return areaC;
}
float calcularHipo(float c,float c1) {
    float hipo= sqrt((pow(c,2)+pow(c1,2)));
    return hipo;
}
