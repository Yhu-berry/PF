//gestion.cpp 
#include "gestion.h"
#include <iostream>
#include <string>

using namespace std;

//Codigo de las funciones 
void registrar_usuario(){
    Usuario& usuario=usuarios[100];
    cout<<"Nombre: ";
    cin>>usuario.nombre;
    cout<<"DNI: ";
    cin>>usuario.DNI;
    cout<<"Edad: ";
    cin>>usuario.edad;
}

