// cafeteria.h 

#ifndef CAFETERIA_H
#define CAFETERIA_H

#define MAX_PRODUCTOS 100

struct Cafeteria {
    std::string nombre;
    float precio;
};

extern Producto menu[MAX_PRODUCTOS];
extern int cantidadProductos;

void mostrarInterfaz();
void venderProductos();
void mostrarProductos();
void anadirProductos();
void eliminarProducos();

#endif