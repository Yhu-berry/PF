//main.cpp 

#include <iostream>
#include <string>
#include "panel.h"
#include "gestion.h"
#include "mantenimiento.h"
#include "cafeteria.h"
#include "reportes.h"

using namespace std;

//declaracion de las funciones en main.cpp
void mostrarBienvenida();
void mostrarInicio();
void despedida();

void mostrarDespedida(){
	
	system("cls");
	cout<<"\n\n-----------------------------------------------------"<<endl;
	cout<<"-----------------------------------------------------"<<endl;
	
	cout<<"\tGRACIAS POR USAR EL PROGRAMA!"<<endl;
	
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"-----------------------------------------------------\n\n\n\n";
	
}
void mostrarBienvenida(){
    cout << "* * * BIENVENIDO A LA GESTION DE HOTEL * * *" << endl;
    cout << "Antes de empezar, diganos sus nombres: "; cin >> admin.NombreAdmin;
    cout << "contrasena: "; cin >> admin.Contrasena;
}

void mostrarInicio(){
    int opcion;

    do {
        cout << " ---- INICIO---- "
        cout << "1.   Panel" << endl;
        cout << "2.   Gestion" << endl;
        cout << "3.   Mantenimiento" << endl;
        cout << "4.   Tienda" << endl;
        cout << "5.   Reportes" << endl;
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
                cafeteria();
            break;
            case 5:
                reportes();
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
    mostrarDespedida();
    return 0;
}