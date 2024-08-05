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

//Registros globales principales principales

struct USUARIO {
    string Nombre;
    int edad;
    int num_Habitacion;
    string DNI;
};

struct Piso {
    int nHabitaciones;
    string categoriasHabitaciones[20];
};

struct Tienda {
    std::string nombre;
    float precio;
};

// Declaracion de variables globales 

extern USUARIO usuarios[100];
extern int TotalUsuarios = 0;
extern int nCategorias = 0;
extern string CAT[20];
extern int nPisos = 0;
extern Piso P[20];
extern int ocupados[100][100] = {0};



#endif 