//se anadira y declarara los registros globales

#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include <string>
#include <vector>

using namespace std;

struct Administrador {
    string nombreAdministrador;
    string Contrasena;
    strinf nombreHotel;
}

//principales

struct Usuario {
    id = 0;
    string nombre;
    string apellido;
    string correo;
    string telefono;
    string direccion;
    string tipo;
};

struct Disposicion {
    int piso = 0;
    int numeroHabitacion = 0;
    string categoria;
    bool ocupada = false;
};

struct Tienda {
    string nombreProducto;
    int idProducto = 0;
    string nombreProducto;
    float precio = 0.0f;
    int cantidadDisponible = 0;
};

// Declaracion de los vectores globales
extern vector<Usuario> usuarios;
extern vector<Disposicion> habitaciones;
extern vector<Tienda> productos;

// Declaracion de los demas vectores 

#endif 