// gestion.h 
#ifndef Gestion_H
#define Gestion_H

#include <string>
#include <vector>

using namespace std;

//Registros
struct USUARIO{
    string Nombre;
    int edad;
    int num_Habitacion;
    string DNI;
};

//Variables globales
USUARIO usuarios[100];
int TotalUsuarios;

//FUCIONES DE LA LIBRERIA gestion.h

//Registrar usuario
void registrar_usuario();
//Mostrar habitaciones disponibles (nivel terminal o usando GUI)
//Reservar Habitaciones
//Revisiom de la salida (pago)
//Liberar habitacion

#endif