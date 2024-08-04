//se anadira y declarara los registros globales

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include <string>
#include <vector>

struct Disposicion {
    int idHabitacion;
    int piso;
    std::string categoria;
};


struct Usuario {
    int idUsuario;
    std::string nombre;
    std::string telefono;
    std::string direccion;
    int numeroHabitacion; 
};


struct Producto {
    int idProducto;
    std::string nombre;
    std::string categoria;
    double precio;
};

#endif 