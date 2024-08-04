//tienda.cpp

#include <iostream>
#include <string> 
#include <vector>
#include "tienda.h"

void mostrarInterfaz(){

    do {
        int opcionTienda;
        cout << " ----TIENDA ----" << endl;
        cout << "1.   Verder Producto" << endl;
        cout << "2.   Mostrar Productos" << endl;
        cout << "0.   Volver al inicio" << endl;
        cout << "Seleccione una opcion"; cin >> opcionTienda;
    

        switch (opcionTienda){
            case 1: 
                venderProductos();
            break;
            case 2: 
                mostraProducto();
            break;
            case 0: 
                cout << "Saliendo . . . " << endl;
            break;
            default:
                cout << "Opcion no valida" << endl;
        }
    } while (opcionTienda != 0);
}