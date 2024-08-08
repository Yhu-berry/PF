//panel.cpp  
#include "panel.h"
#include "estructura.h"
#include "gestion.h"
#include <iostream>
#include <string>

using namespace std;

void panel(){
    int opcion;
    system("cls")
    do{
        cout << "==================== PANEL ====================" << endl;
        cout << "1. Ver habitaciones disponibles" << endl;
        cout << "2. Mostrar total de habitaciones" << endl;
        cout << "0. Salir" << endl;
        cout << "===============================================" << endl;
        cout << "Digite una opcion: "; cin >> opcion;
        
        switch (opcion)
        {
        case 1:
            mostrarPanel();
            break;
        case 2:
            totalHabitaciones();
            break;
        case 0:
            system("cls");
            break;
        default:
            break;
        }
    }
}

//continuar
void verPanel(){
    mostrarPanel();
    int piso;
    cout<<"Piso: "<< piso<<endl;
}



//corregir 
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

//se puede hacer sin punteros
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
