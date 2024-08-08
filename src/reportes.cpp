//reportes.cpp 

#include "reportes.h"
#include "estructura.h"
#include "gestion.h"
#include <iostream>
#include <string>

using namespace std;

//interfaz de la funcion 
void reportes(){

    int opcion;

    do {
        cout << " ----REPORTES---- " << endl;
        cout << "1.   Ver historial" << endl;
        cout << "2.   Completar un pago" << endl;
        cout << "0.   Volver al inicio" << endl;
        cout << "Seleccione una opcion: "; cin >> opcion;

        switch (opcion){
            case 1: 
                verHistorial();
            break;
            case 2: 
                completarPago();
            default:
                cout << "Opcion no valida."<< endl;
                system ("cls");
        }
    } while (opcion != 0); 
}

//funcion para imprimir los datos del usuario en base a su nombre
void verHistorial(){

    string dni;
    cout << "Ingrese el DNI del usuario cuyo historial desea ver: ";
    cin.ignore();
    getline(cin, dni);

    //busqueda del usuario por el DNI
    bool encontrado = false;
    for (int i = 0; i < TotalUsuarios; ++i) {
        if (usuarios[i].DNI == dni) {
            encontrado = true;
            // Se va a mostrar la información del usuario
            cout << "Nombre: " << factura[i].nombre << endl;
            cout << "DNI: " << factura[i].DNI << endl;
            cout << "Habitacion: " << factura[i].habiA << endl;
            cout << "Deuda actual: $" << factura[i].totalPagar << endl;
            
            // Se mostrara la información del piso
            for (int j = 0; j < nPisos; ++j) {
                if (PISO[j].NroHabitacion[j] == usuarios[i].num_Habitacion) {
                    cout << "Categoría del piso: " << pisos[j].categoriasHabitaciones[j] << endl;
                    break;
                }
            }
            break;
        }
    }
    
    if (!encontrado) {
        system("cls");
        cout << "Usuario no encontrado." << endl;
    }
}

//se empieza por buscar de nuevo su DNI
void completarPago(){
    string nombre;
    cout << "Ingrese el nombre del usuario para completar el pago: ";
    cin.ignore();
    getline(cin, nombre);

    bool encontrado = false;
    for (int i = 0; i < numUsuarios; ++i) {
        if (usuarios[i].nombre == nombre) {
            encontrado = true;
            cout << "Deuda actual del usuario " << usuarios[i].nombre << ": $" << usuarios[i].deuda << endl;
            
            float montoPago;
            cout << "Ingrese el monto a pagar: ";
            cin >> montoPago;
            
            if (montoPago > usuarios[i].deuda) {
                cout << "El monto ingresado es mayor que la deuda actual. No se puede completar el pago." << endl;
            } else {
                usuarios[i].deuda -= montoPago;
                cout << "Pago completado. La nueva deuda del usuario " << usuarios[i].nombre << " es: $" << usuarios[i].deuda << endl;
            }
            break;
        }
    }
    
    if (!encontrado) {
        cout << "Usuario no encontrado." << endl;
    }

}