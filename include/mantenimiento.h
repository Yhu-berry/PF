#ifndef MANTENIMIENTO_H
#define MANTENIMIENTO_H

#include <string>

struct piso{
    int nHabitaciones;
    std::string categoriasHabitaciones[20];
    float preciosHabitaciones[20];
};

extern int nCategorias;
extern std::string CATEGORIA[20];
extern float PRECIO[20];
extern int nPisos;
extern piso PISO[20];

void iniciar();
void agregarHabitaciones(int pisoIndex);
void editar();
void visualizar();
void mantenimiento();

#endif