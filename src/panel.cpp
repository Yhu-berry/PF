//panel.cpp  
#include <iostream>
#include <string>
#include "panel.h"

using namespace std;
	
void menu() {
    cout <<"1. ver habitaciones disponibles\n";
    cout <<"2. reservar habitacion\n";
    cout <<"3. Mostrar total de habitaciones\n";
    cout <<"Digite una opcion: "; cin >> op;
    menuinter();
    while (salir == 0) {
        menu();
	}	
}