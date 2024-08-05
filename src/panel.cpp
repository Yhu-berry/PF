//panel.cpp  
#include <iostream>
#include <string>
#include "panel.h"

using namespace std;
	
void menuinter() {
    switch(op) {
        case 1: interfaz(); break;
        case 2: mostrarTotalHabitaciones(); break;
        default:
            cout <<"Porfavor digite una opcion correcta";
    }
    cout <<"\nPresione 0 para volver "; cin >> salir;
    system("cls");
}

void mostrarPanel() {
    system("cls");
    for (int i=pisos.size();i>0;i--) {
        cout <<"Piso #"<<i<< "  ";
        for (int j=0;j<pisos[i-1].nHabitaciones;j++) {
            if (ocupados[i-1][j] == 1) {
                cout <<"H-"<<i<<j+1<<"[1] ";
            } else {
                cout <<"H-"<<i<<j+1<<"[0] ";
            }
        }
        cout <<endl;
    }
    cout <<"Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}



void mostrarTotalHabitaciones() {
    int totalHabitaciones = nPisos*nHabitaciones;
    int habitacionesOcupadas = 0;
    int habitacionesDisponibles = 0;
    
    for (int i=1;i<=nPisos;i++) {
        for (int j=1;j<=nHabitaciones;j++) {
            if (ocupados[i][j] == 1) {
                habitacionesOcupadas++;
            } else {
                habitacionesDisponibles++;
            }
        }
    }
    cout <<"Total de habitaciones: "<<totalHabitaciones<<endl;
    cout <<"Habitaciones ocupadas: "<<habitacionesOcupadas<<endl;
    cout <<"Habitaciones disponibles: " <<habitacionesDisponibles<<endl;
}

void menu() {
    cout <<"1. ver habitaciones disponibles\n";
    cout <<"2. Mostrar total de habitaciones\n";
    cout <<"Digite una opcion: "; cin >> op;
    menuinter();
    while (salir == 0) {
        menu();
    }
}
void comprobarocupad{
	system("cls");
            if (po>0 && po<=nPisos && ho>0 && ho<=nHabitaciones && ocupados[po][ho] == 0) {
                ocupados[po][ho] = 1;
            } else {
                cout <<"No esta disponible esa habitacion\n";
            }
            break;
        }
}