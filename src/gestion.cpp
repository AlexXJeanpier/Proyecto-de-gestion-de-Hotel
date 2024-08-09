//gestion.cpp 

#include "estructura.h"
#include "gestion.h"
#include "mantenimiento.h"  // nHabitaciones le pertenece a esta libreria
#include "panel.h" //mostrarPanel()
#include <iostream>
#include <string>

using namespace std;

void gestion(){
    int opcion;
    do{
        system("cls");
        cout<<"======================= GESTION ======================"<<endl;
        cout<<" 1. Registrar usuario" <<endl;
        cout<<" 2. Reservar habitacion" << endl;
        cout<<" 0. Volver al inicio" << endl;
        cout<<"======================================================"<<endl;
        cout<<"Seleccione una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
                registrar_usuario();
                break;
            case 2:
                reservarHabitacion();
                break;
            case 0:
                break;
            default:
                cout<<"Opcion incorrecta\n";
        }
    }while(opcion !=0);
}


//Usa arreglos de mantenimiento.h
void visualizarCategorias(){
    cout<<"=============VISUALIZAR=============="<<endl;
    for(int i=0; i<nCategorias; i++){
        cout<<"Categoria: "<<CATEGORIA[i]<<"-Precio.S/"<<PRECIO[i]<<endl;
    }
    cout<<"======================================"<<endl;
    cout<<"presione enter para continuar..";
    cin.ignore();
    cin.get();
}


//Codigo de las funciones 
//Ya no se va usar punteros o varibles por referencias ya que existe etructura que contiene todo

void registrar_usuario(){
    ingresarDatos_usuario();
}


void ingresarDatos_usuario(){
    cout<<"Nombre: ";
    cin.ignore();
    getline(cin,usuarios[posicionUsuarios].Nombre); //Desde la entrada va a leer el nombre completo
    cout<<"DNI: ";
    cin.ignore();
    getline(cin,usuarios[posicionUsuarios].DNI);
    cout<<"Edad: ";
    cin>>usuarios[posicionUsuarios].edad;
    usuarios[posicionUsuarios].num_Habitacion=-1;
    //en cada iteracion se va a incrementar 
    posicionUsuarios++;
    //Cada usuario posee su posicion
    TotalUsuarios=posicionUsuarios;
}


//Buscar al usuario por el DNI, pero no va a retornar unn valor por tanto se ha de usar  void
 void buscar_usuarioPorDNI(){
    for(int i=0; i<TotalUsuarios;i++){
        if(usuarios[i].DNI==dni){
            //Usuario encontrado
            cout<<"Usuario encontrado en la posicionn "<<i<<endl;
            return;
        }
    }
    //No es necesario que retorne algo ya que es unna funcion void
    cout<<"Usuario no encontrado\n";
}


void seleccionarHabitacion(int piso){
    //Se elimino la validacion del piso ya que esta en panel.cpp

    cout<<"Habitaciones disponibles en el piso"<< piso <<":\n";

    for(int j=0;j <PISO[piso-1].nHabitaciones;j++){
        //si dentr esta el 0 es por ue esta desocupada
        if(ocupados[piso-1][j]==0){
            cout<<"Habitacion"<< (j+1)<< "";
        }
    }
    cout<<endl;

    int num_Habitacion;
    cout<<"numero de habitacion a reservar: ";
    cin>>num_Habitacion;

//si es mayor que el numero de habitaciones y ocupar dicho valor en el vector
    if(!(num_Habitacion>= 1 && num_Habitacion <= PISO[piso-1].nHabitaciones || ocupados[piso-1][num_Habitacion-1]==1)){
        cout<<"Habitacion invalida"<<endl;
        return;
    }

    //ocupar habitacion en panel
    ocupados[piso-1][num_Habitacion-1]=1;
    usuarios[posicionUsuarios-1].num_Habitacion=num_Habitacion;
}


//Reservar habitaciones
//buscar_usuarioPorDNI ya no devuelve un valor 
void reservarHabitacion(){
    system("cls");
    cout<<"Ingrese su DNI: ";
    cin>>dni;
    
    buscar_usuarioPorDNI();

    int usuarioEncontrado;
    //Verificar si tiene o no una habitacion
    if(usuarioEncontrado==-1){
        for(int i=0;i<TotalUsuarios;i++){
            if(usuarios[i].DNI==dni){
                usuarioEncontrado=i;
                break;
            }
        }
    }

    if(usuarioEncontrado==-1){
        cout<<"Usuario no encontrado"<<endl;
        return;
    }

    //si el usuario es diferente a menos uno significa que ya se recorrio en otra instancia ese arreglo
    //El numero de habitacion ya ha sido reservado             
    if(usuarios[usuarioEncontrado].num_Habitacion !=-1){
        cout<<"Usted ya tiene una habitacion reservada"<<endl;
        return;
    } 
//mantenimiento para saber los precios (lo muestra de manera superficial mejorar eso)
visualizarCategorias();
//funcion de panel.h
verPanel();

}
