#include "mantenimiento.h"
#include <iostream>
using namespace std;

int nCategorias=0;
string CAT[20];
int nPisos=0;

piso P[20];

void iniciar(){
	string categoria;

	system("cls");
	cout<<"======================= INICIO ======================="<<endl<<endl;
	cout<<"Complete los siguientes datos:"<<endl<<endl;
	
	// ingresar numero de pisos	
	cout<<" - Numero de pisos: "; cin>>nPisos;
	
	// ingresar categorias
	cout<<" - Numero de categorias: "; cin>>nCategorias;
	cin.ignore();
	cout<<endl;
	
	for(int i=0; i<nCategorias; i++){
		cout<<"   Categoria #"<<i+1<<": "; getline(cin, categoria);
		CAT[i]=categoria;
	}
	cout<<endl;
    
	// mostrar categorias ingresadas
	cout<<"------------------------------------------------------"<<endl;
	cout<<"   CATEGORIAS INGRESADAS: ";
	for(int i=0; i<nCategorias; i++){
		cout<<CAT[i]<<" ";
	}
	cout<<endl<<"------------------------------------------------------"<<endl<<endl;
	   
	// ingresar numero de habitaciones por piso
	for(int i=0; i<nPisos; i++){
		cout<<"Numero de habitaciones en el piso #"<<i+1<<": "; cin>>P[i].nHabitaciones;
		cin.ignore();
	}
	
	// asignar categoria a cada habitacion
	cout<<endl;
	cout<<"Asigne categorias a cada habitacion:"<<endl<<endl;
	for(int i=0; i<nPisos; i++){
		for(int j=0; j<P[i].nHabitaciones; j++){
			cout<<"   Piso #"<<i+1<<", Habitacion #"<<j+1<<" : "<<endl;
			cout<<"   - Categoria: "; getline(cin, categoria);
			P[i].categoriasHabitaciones[j]=categoria;
			cout<<endl;
		}
	}
    
	// mostrar categorias asignadas a las habitaciones
	cout<<"------------------------------------------------------"<<endl;
	cout<<"Categorias asignadas a cada habitaciones:"<<endl;
	for(int i=0; i<nPisos; i++){
		cout<<endl;
		cout<<"   Piso #"<<i+1<<":"<<endl;
		for(int j=0; j<P[i].nHabitaciones; j++){
			cout<<"   - Habitacion #"<<j+1<<": "<<P[i].categoriasHabitaciones[j]<<endl;
		}
	}
	cout<<"------------------------------------------------------"<<endl<<endl;

	cout<<"======================================================"<<endl<<endl;    
}

void editar(){
	// visualizar datos de inicio registrado
	// agregar pisos -> agregar habitaciones 
	// agregar categorias -> editar categoria de una habitacion
}

void visualizar(){
	system ("cls");
	cout<<"===================== VISUALIZAR ====================="
	
	// encontrar el numero maximo de habitaciones en cualquier piso
	int maxHabitaciones=0;
	for(int i=0; i<nPisos; i++){
		if(P[i].nHabitaciones>maxHabitaciones)
			maxHabitaciones=P[i].nHabitaciones;
	}
	
	// imprimir encabezado de cada piso
	for(int i=0; i<nPisos; i++){
		cout<<" >> PISO "<<i+1<<" <<\t";
	}
	cout<<endl;
	
	// imprimir la informacion de cada habitacion por piso
	for(int j=0; j<maxHabitaciones; j++){
		for(int i=0; i<nPisos; i++){
			if(j<P[i].nHabitaciones)
				cout<<"#"<<j+1<<" ["<<P[i].categoriasHabitaciones[j]<<"]\t";
			else
				cout<<"\t\t";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"======================================================"<<endl<<endl;
}

void mantenimiento(){
	int opcion;
	
	do{
		cout<<"=================== MANTENIMIENTO ===================="<<endl;
		cout<<" 1. Iniciar"<<endl;
		cout<<" 2. Editar"<<endl;
		cout<<" 3. Visualizar"<<endl;
		cout<<" 0. Salir"<<endl;
		cout<<"======================================================"<<endl;
		cout<<" Seleccione una opcion: "; cin>>opcion;
		
		switch(opcion){
			case 1:
				iniciar();
				break;
			case 2:
				editar();
				break;
			case 3:
				visualizar();
				break;
			case 0:
				// salir al menu de main.cpp
				break;
			default:
				cout<<"Opcion no valida"<<endl;
				break;
		}
	} while(opcion!=0);
}
