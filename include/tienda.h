// tienda.h 

#ifndef TIENDA_H
#define TIENDA_H

#define MAX_PRODUCTOS 100

struct Tienda {
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