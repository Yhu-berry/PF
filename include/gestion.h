// gestion.h 
#ifndef Gestion_H
#define Gestion_H

#include <string>
#include <vector>

//Registros
struct USUARIO{
    std::string Nombre;
    int edad;
    int num_Habitacion;
    std::string DNI;
};

//Variables globales
extern std::vector<USUARIO> usuarios;

//FUCIONES DE LA LIBRERIA gestion.h
void registrar_usuario(USUARIO& usuario);

void ingresarDatos_usuario(USUARIO& usuario);

USUARIO* buscar_usuarioPorDNI(const std::string& DNI);

voi visualizarCategorias_usuario();
void seleccionarHabitacion(int piso);

void reservarHabitacion();

void gestion{};

//Mostrar las reservas
#endif //Fin de Gestion