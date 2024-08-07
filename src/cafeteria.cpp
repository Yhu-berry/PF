//cafeteria.cpp

#include <iostream>
#include <string> 
#include <vector>
#include "cafeteria.h"

using namespace std;

Producto menu[MAX_PRODUCTOS];
int cantidadProductos = 0;

void mostrarInterfaz(){
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
            case 1: anadirProductos(); 
                break;
            case 2: eliminarProductos(); 
                break;
            case 3: mostrarProductos(); cin.get(); 
                break;
            case 4: venderProductos(); cin.get(); 
                break;
            case 5: exit = true; 
                break;
            default: cout << "Opción no válida. Intente nuevamente.\n";
            cin.get();
        }
    }
}

void mostrarProductos(){
    system("cls"); 
    cout <<"Menú de Cafetería:\n";
    cout <<"Producto                        Precio\n";
    cout <<"--------------------------------------\n";
    for (int i = 0; i < cantidadProductos; i++) {
        cout << menu[i].nombre;
        cout <<"                          " << menu[i].precio << '\n';
    }
}

void venderProductos(){
	string fin = "si";
    string dni;
    bool hayDNI = false;
    cout << "Ingrese el DNI del huesped: ";
    cin >> dni;
    for (int i = 0; i < 100; i++ ){
        if (dni == usuarios[i].DNI){
            hayDNI = true;
        }
    }
    if (hayDNI){
        int cantidadSeleccion = 0;
        string nombre;
        int cantidad;
        float total = 0;
        cout <<"Digite lo que desee. "<<endl;
       
        while (fin == "si") {
        	
            cout <<"Nombre del producto: "; cin >> nombre;
           
            int i = 0;
            for (i = 0; i < cantidadProductos; i++) {
                if (menu[i].nombre == nombre) {
                    break;
                }
            }
            if (i < cantidadProductos) {
                cout <<"Ingrese la cantidad del producto a comprar: ";
                cin >> cantidad;
                cin.ignore();
                for (int j = 0; j < cantidad; j++) {
                    seleccion[cantidadSeleccion] = menu[i];
                    cantidadSeleccion++;
                }
            } else {
                cout <<"Producto no encontrado.\n";
            }
            cout << endl;
            cout <<"Desea comprar algun producto mas?si/no: ";cin >> fin;
        }
        
        if (cantidadSeleccion == 0) {
            cout <<"No se ha seleccionado ningun producto.\n";
            return;
        }
        
       	system("cls");
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
                cout <<"                              "<< cantidadProducto <<"      "<< subtotal << '\n';
                for (int k = 0; k < 100; k++){
                    if (dni == usuarios[i].DNI){
                        factura[i].nombre = usuarios[i].Nombre;
                        factura[i].DNI = usuarios[i].DNI;
                        factura[i].totalPagar = subtotal;
                        facturados++;
                    }
                }
            }
        }
       
        cout <<"----------------------------------------------\n";
        cout <<"Total: "<< total << '\n';
    }
    else {
        cout << "Usuario no encontrado"<<endl;
	}
}

void anadirProductos(){
    if (cantidadProductos >= MAX_PRODUCTOS) {
        cout <<"No se pueden agregar más productos. El menú está lleno.\n";
        return;
    }
    
    Producto nuevoProducto;
    cout <<"Ingrese el nombre del producto: ";
    getline(cin, nuevoProducto.nombre);
    cout <<"Ingrese el precio del producto: ";
    cin >> nuevoProducto.precio;
    cin.ignore(); 
    menu[cantidadProductos] = nuevoProducto;
    cantidadProductos++;
    cout <<"Producto agregado con éxito.\n";
}

void eliminarProductos(){
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