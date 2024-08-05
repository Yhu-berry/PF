//tienda.cpp

#include <iostream>
#include <string> 
#include <vector>
#include "tienda.h"

void mostrarInterfaz(){
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
          
        switch (opcion) {
            case 1: anadirProductos(menu, cantidadProductos); break;
            case 2: eliminarProductos(menu, cantidadProductos); break;
            case 3: mostrarProductos(menu, cantidadProductos); cin.get(); break;
            case 4: venderProductos(menu, cantidadProductos); cin.get(); break;
            case 5: exit = true; break;
            default: cout << "Opción no válida. Intente nuevamente.\n"; cin.get();
        }
    }
}

void mostrarProductos(Producto menu[], int cantidadProductos){
    system("cls"); 
    cout <<"Menú de Cafetería:\n";
    cout <<"Producto                        Precio\n";
    cout <<"--------------------------------------\n";
    for (int i = 0; i < cantidadProductos; i++) {
        cout << menu[i].nombre;
        cout <<"                          " << menu[i].precio << '\n';
    }
}

void venderProductos(Producto menu[], int cantidadProductos) {
    Producto seleccion[MAX_PRODUCTOS];
    int cantidadSeleccion = 0;
    string nombre;
    int cantidad;
    system("cls");
    cout <<"Ingrese los productos que desee. Escriba 'FIN' para terminar.\n";
    
    while (true) {
        cout <<"Nombre del producto: ";
        getline(cin, nombre);
        if (nombre == "FIN") break;
        
        int i;
        for (i = 0; i < cantidadProductos; i++) {
            if (menu[i].nombre == nombre) {
                break;
            }
        }
	}
}

void anadirProductos(){

}
void eliminarProducos(){

}