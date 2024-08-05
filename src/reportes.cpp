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

//funcion para imprimir los datos del usuario en base a su nombre
void verHistorial(){

    string nombre;
    cout << "Ingrese el nombre del usuario cuyo historial desea ver: ";
    cin.ignore();
    getline(cin, nombre);

    bool encontrado = false;
    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i].nombre == nombre) {
            encontrado = true;
            // Se va a mostrar la información del usuario
            cout << "Nombre: " << usuarios[i].nombre << endl;
            cout << "DNI: " << usuarios[i].dni << endl;
            cout << "Habitacion: " << usuarios[i].habitacion << endl;
            cout << "Deuda actual: $" << usuarios[i].deuda << endl;
            
            // Se mostrara la información del piso
            for (int j = 0; j < numPisos; ++j) {
                if (pisos[j].numero == usuarios[i].habitacion) {
                    cout << "Categoría del piso: " << pisos[j].categoria << endl;
                    break;
                }
            }
            break;
        }
    }
    
    if (!encontrado) {
        cout << "Usuario no encontrado." << endl;
    }
}

void completarPago(){

}