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

void venderProductos(Producto menu[], int cantidadProductos){
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
        if (i < cantidadProductos) {
            cout <<"Cantidad: ";
            cin >> cantidad;
            cin.ignore(); 
            for (int j = 0; j < cantidad; j++) {
                seleccion[cantidadSeleccion] = menu[i];
                cantidadSeleccion++;
            }
        } else {
            cout <<"Producto no encontrado.\n";
        }
    }
    if (cantidadSeleccion == 0) {
        cout <<"No se ha seleccionado ningún producto.\n";
        return;
    }
    
    float total = 0;
    cout <<"Factura:\n";
    cout <<"Producto                        Cantidad  Subtotal\n";
    cout <<"----------------------------------------------\n";
    
    for (int i = 0; i < cantidadProductos; i++) {
        int cantidadProducto = 0;
        for (int j = 0; j < cantidadSeleccion; j++) {
            if (seleccion[j].nombre == menu[i].nombre) {
                cantidadProducto++;
            }
        }
        if (cantidadProducto > 0) {
            float subtotal = cantidadProducto * menu[i].precio;
            total += subtotal;
            cout << menu[i].nombre;
            cout <<"                          "<< cantidadProducto <<"      "<< subtotal << '\n';
        }
    }
    
    cout <<"----------------------------------------------\n";
    cout <<"Total: "<< total << '\n';
}

void anadirProductos(Producto menu[], int& cantidadProductos){
    if (cantidadProductos >= MAX_PRODUCTOS) {
        cout <<"No se pueden agregar más productos. El menú está lleno.\n";
        return;
    }
    
    Producto nuevoProducto;
    cout <<"Ingrese el nombre del producto: "; getline(cin, nuevoProducto.nombre);
    cout <<"Ingrese el precio del producto: "; cin >> nuevoProducto.precio;
    cin.ignore(); 
    menu[cantidadProductos] = nuevoProducto;
    cantidadProductos++;
    cout <<"Producto agregado con éxito.\n";
}
void eliminarProductos(Producto menu[], int& cantidadProductos){
    string nombre;
    cout <<"Ingrese el nombre del producto a eliminar: ";
    getline(cin, nombre);
    
    int i;
    for (i =0;i<cantidadProductos;i++) {
        if (menu[i].nombre == nombre) {
            break;
        }
    }
    
    if (i < cantidadProductos) {
        for (int j=i;j<cantidadProductos-1;j++) {
            menu[j] = menu[j + 1];
        }
        cantidadProductos--;
        cout <<"Producto eliminado con éxito.\n";
    } else {
        cout <<"Producto no encontrado.\n";
    }
}