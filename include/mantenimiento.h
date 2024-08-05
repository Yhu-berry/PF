#ifndef MANTENIMIENTO_H
#define MANTENIMIENTO_H

#include <string>

struct piso{
    int nHabitaciones;
    std::string categoriasHabitaciones[20];
};

extern int nCategorias;
extern std::string CAT[20];
extern int nPisos;
extern piso P[20];

void iniciar();
void editar();
void visualizar();
void mantenimiento();

#endif