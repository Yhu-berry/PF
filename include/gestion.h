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
extern USUARIO usuarios[100];
extern int TotalUsuarios;

//FUCIONES DE LA LIBRERIA gestion.h

//Registrar usuario
void registrar_usuario(USUARIO& usuario);

//Mostrar habitaciones disponibles (nivel terminal o usando GUI)

//Reservar Habitaciones (cuando se reserve la habitacion =0, dato que se pasra a panel.cpp)
void reservarHabitacion();

//Revisiom de la salida (pago)
//Liberar habitacion

#endif //Fin de Gestion