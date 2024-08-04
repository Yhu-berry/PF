#include "mantenimiento.h"
#include <iostream>
using namespace std;

struct piso{
	int nHabitaciones;
	string categoriasHabitaciones[20];	
};

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
	// mostrar categorias asignadas a las habitaciones
    
    cout<<"======================================================"<<endl<<endl;    
}

void editar(){
	// visualizar datos de inicio registrado
	// agregar pisos -> agregar habitaciones 
	// agregar categorias -> editar categoria de una habitacion
}

void visualizar(){
	// visualizar inicio registrado
}
