//reportes.cpp 

#include "reportes.h"
#include <iostream>

using namespace std;

//interfaz de la funcion 
void interfazReportes(){
    do {
        int opcion;
        cout << " ----REPORTES---- " << endl;
        cout << "1.   Ver historial" << endl;
        cout << "2.   Completar un pago" << endl;
        cout << "0.   Volver al inicio" << endl;
        cout << "Seleccione una opcion"; cin >> opcion;

        switch (opcion){
            case 1: 
                verHistorial();
            break;
            case 2: 
                completarPago();
            default:
                cout << "Opcion no valida";
        }
    } while (opcion != 0); 
}

void verHistorial(){

}

void completarPago(){

}