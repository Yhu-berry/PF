//gestion.cpp 
#include "gestion.h"
#include <iostream>
#include <string>

using namespace std;

//Variables globales
vector<USUARIO> usuarios;

//Codigo de las funciones 
void ingresarDatos_usuario(USUARIO& usuario){
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

void registar_usuario(USUARIO& usuario){
    ingresarDatos_usuario(usuario);
    usuarios.push_back(usuario);
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

void seleccionarHabitacion(int piso){
    cout<<"Habitaciones disponibles en el piso"<< piso <<":\n"
    for(int j=0;j<piso[piso-1].nHabitaciones;j++){
        cout<<"Habitacion #"<< (j+1)<< "";
    }
    cout<<endl;

    int num_Habitacion;
    cout<<"Ingrese el numero de la habitacion: ";
    cin>>num_Habitacion;

//si es mayor que el numero de habitaciones
    if(num_Habitacion1 || num_Habitacion>piso[piso-1].nHabitaciones){
        cout<<"Habitacion invalida"<<endl;
        return;
    }

    //ocupar habitacion 
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

    seleccionarHabitacion(piso);

    int num_Habitacion;

    cout<<"ingrese el numero de la habitacion: ";
    cin>>num_Habitacion;
    usuario->num_Habitacion=piso*100+num_Habitacion;
    cout<<"Habitacion reservada con exito\t"<<"H"<<piso<<num_Habitacion<<endl;
}

