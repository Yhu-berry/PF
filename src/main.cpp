//main.cpp 

#include <iostream>
#include <string>
#include "panel.h"
#include "gestion.h"
#include "mantenimiento.h"
#include "tienda.h"
#include "reportes.h"
#include "clientes.h"

using namespace std;

string nombresAdmin;

struct ADMIN {
    string NombreAdmin;
    string Contrasena;
    strinf nombreHotel;
}

ADMIN admin;

void mostrarBienvenida(){
    cout << "* * * BIENVENIDO A LA GESTION DE HOTEL * * *" << endl;
    cout << "Antes de empezar, diganos sus nombres: "; cin >> admin.NombreAdmin;
    cout << "contrasena: "; cin >> admin.Contrasena;
}

void mostrarInicio(){

    do {
        cout << " ---- INICIO---- "
        cout << "1.   Panel" << endl;
        cout << "2.   Gestion" << endl;
        cout << "3.   Mantenimiento" << endl;
        cout << "4.   Tienda" << endl;
        cout << "5.   Reportes" << endl;
        cout << "6.   Clientes" << endl;
        cout << "0.   Salir" << endl;
        cout << "Seleccione una opcion..." << endl;

        cin >> opcion;
        switch (opcion){
            case 1:
                panel();
            break;
            case 2:
                gestion();
            break;
            case 3:
                mantenimiento();
            break;
            case 4:
                tienda();
            break;
            case 5:
                reportes();
            breakl;
            case 6: 
                clientes();
            break;
            case 0:
                cout << "Saliendo . . . " << endl;
            break;
            default:
            cout << "opcion no valida" << endl;

        }
    }
}

int main (){
    mostrarBienvenida();
    mostrarInicio();
    return 0;
}