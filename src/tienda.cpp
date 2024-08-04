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
                cout << "Saliendo de tienda. . . " << endl;
            break;
            default:
                cout << "Opcion no valida" << endl;
        }
    } while (opcionTienda != 0);
}

void mostraProducto(){
    do {
        int opcionMostrarProducto;
        cout << " ----MOSTRAR PRODUCTO----" << endl;
        cout << "1.   Anadir producto" << endl;
        cout << "2.   Eliminar producto" << endl;
        cout << "0.   Atras"
        cout << "Seleccione una opcion"; cin opcionMostrarProducto;
        switch (opcionMostrarProducto){
            case 1: 
                anadirProductos();
            break;
            case 2: 
                eliminarProducos();
            break;
            case 0:
                cout << "Saliendo de mostrar producto" << endl;
            default:
                cout << "Opcion no valida." << endl;
        }
    }
}

void venderProductos(){
    
}

void anadirProductos(){

}
void eliminarProducos(){

}