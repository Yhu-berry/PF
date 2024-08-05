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
    cin.ignore();
    getline(cin,usuario.DNI);
    cout<<"Edad: ";
    cin>>usuario.edad;
    usuario.num_Habitacion=-1;
}

//Buscar al usuario por el DNI
USUARIO* buscar_usuarioPorDNI(const std::string&DNI){
    for(int i=0; i<TotalUsuarios;i++){
        if(usuarios[i].DNI==DNI){
            return &usuarios[i];
        }
    }
    return nullptr;
}


//Reservar habitacione
void reservarHabitacion(){
    string DNI; 
    cout<<"Ingrese su DNI: ";
    cin>>DNI;

    USUARIO* usuario = buscar_usuarioPorDNI(DNI);
    if(!usuario==nullptr){
        cout<<"Usuario no encontrado"<<endl;
    }
                   
    if(usuario->num_Habitacion!=-1){
        cout<<"Usted ya tiene una habitacion reservada"<<endl;
        return;
    }  

    //Mostrar panel
    int piso;
    cout<<"piso: ";
    cin>>piso;
    if(!(piso>=1 && piso<=nPisos)){
        cout<<"Piso invalido"<<endl;
        return;
    }               
}

