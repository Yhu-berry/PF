//main.cpp 

#include <iostream>
#include <string>
#include "panel.h"
#include "gestion.h"
#include "mantenimiento.h"
#include "tienda.h"
#include "reportes.h"
#include "clientes.h"

using namespace std;

struct USUARIO {
    string Nombre;
    int edad;
    int numero;
    int DNI;
};

USUARIO usuario[100];

struct DISPOSICION {
    string habitaciones;
    string categoria;
    int pisos;
};

DISPOSICION disposicion[100];

struct TIENDA {
    string nombreProducto;
    string descripcion;
    float precio;
};

TIENDA tienda[100];

int main (){

    return 0;
}