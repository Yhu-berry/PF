//gestion.cpp 
#include "gestion.h"
#include <iostream>
#include <string>

using namespace std;
//Variables globales
USUARIO usuarios[100];
int TotalUsuarios=0;

//Codigo de las funciones 
void registrar_usuario(USUARIO& usuario){
    cout<<"Nombre: ";
    cin.ignore();
    getline(cin,usuario.Nombre); //Desde la entrada va a leer el nombre completo
    cout<<"DNI: ";
    cin>>usuario.DNI;
    cout<<"Edad: ";
    cin>>usuario.edad;

    usuario.num_Habitacion=-1;
    TotalUsuarios++;
}

