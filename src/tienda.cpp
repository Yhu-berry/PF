//tienda.cpp

#include <iostream>
#include <string> 
#include <vector>
#include "tienda.h"

void mostrarInterfaz() {
    Producto menu[MAX_PRODUCTOS];
    int cantidadProductos = 0;
    int opcion;
    bool exit = false;
    
    while (!exit) {
        system("cls");
        cout <<"\tRecepcion-Cafeteria\n\n";
        cout <<"1. Anadir Producto\n";
        cout <<"2. Eliminar Producto\n";
        cout <<"3. Mostrar Productos\n";
        cout <<"4. Vender Productos\n";
        cout <<"5. Salir\n";
        cout <<"Opcion: "; cin >> opcion;
        cin.ignore();

void mostrarProducto(){

}

void venderProductos(){

}

void anadirProductos(){

}
void eliminarProducos(){

}