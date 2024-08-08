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
        //marca ERROR
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
    }while(opcion!=0);
}

//continuar
void verPanel(){
    mostrarPanel();
    int piso;
    cout<<"Piso: "<< piso;
    if(!(piso >= 1 && piso <= nPisos)) {
        cout << "Piso invalido" << endl;
        return;
    }

    seleccionarHabitacion(piso);
}



//corregir 
void mostrarPanel() {
    system("cls");
    for (int i=0;i<nPisos;i++) {
        cout <<"Piso #"<<i<< "  ";
        for (int j=0;j<PISO[i].nHabitaciones;j++) {
            if (ocupados[i][j] == 1) {
                cout <<"H-"<<i+1<<j+1<<"[1] ";
            } else {
                cout <<"H-"<<i+1<<j+1<<"[0] ";
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
    system("cls");
    int totalHabitaciones = 0;
    int habitacionesOcupadas = 0;
    /*int habitacionesDisponibles = 0;*/
    
    for (int i=0;i<nPisos;i++) {
        totalHabitaciones += PISO[i].nHabitaciones;
        for (int j=0;j<PISO[i].nHabitaciones;j++){
            if (ocupados[i][j] == 1) {
                habitacionesOcupadas++;
            } /*else {
                habitacionesDisponibles++;
            }*/
        }
    }
    cout <<"Total de habitaciones: "<<totalHabitaciones<<endl;
    cout <<"Habitaciones ocupadas: "<<habitacionesOcupadas<<endl;
    /*cout <<"Habitaciones disponibles: " <<habitacionesDisponibles<<endl;*/
}
