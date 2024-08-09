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
                cout<<" >>> [ OPCION NO VALIDA ] <<<" << endl;
        }
    }while(opcion !=0);
}


//Usa arreglos de mantenimiento.h
void visualizarCategorias(){
    cout<<"===================== VISUALIZAR ====================="<<endl;
    for(int i=0; i<nCategorias; i++){
        cout<<"Categoria: "<<CATEGORIA[i]<<" - Precio.S/"<<PRECIO[i]<<endl;
    }
    cout<<"======================================================"<<endl;
    system ("pause");
    cin.ignore();
    cin.get();
}


//Codigo de las funciones 
//Ya no se va usar punteros o varibles por referencias ya que existe etructura que contiene todo

void registrar_usuario(){
    ingresarDatos_usuario();
}


void ingresarDatos_usuario(){
    cout << "------------------------------------------------------" << endl;
    cout<<"- Nombre: ";
    cin.ignore();
    getline(cin,usuarios[posicionUsuarios].Nombre); //Desde la entrada va a leer el nombre completo
    cout<<"- DNI: ";
    getline(cin,usuarios[posicionUsuarios].DNI);
    cout<<"- Edad: ";
    cin>>usuarios[posicionUsuarios].edad;
    usuarios[posicionUsuarios].num_Habitacion=-1;
    cout << "Registrado correctamente" << endl;
    system ("pause");
    //en cada iteracion se va a incrementar 
    posicionUsuarios++;
    //Cada usuario posee su posicion
    TotalUsuarios=posicionUsuarios;
} 

//Buscar al usuario por el DNI, pero no va a retornar unn valor por tanto se ha de usar  void
int buscar_usuarioPorDNI(){
    cout<<"Ingrese su DNI: ";
    cin>>dni;
    for(int i=0; i<TotalUsuarios;i++){
        if(dni == usuarios[i].DNI){
            //Usuario encontrado
            return 1;
        }
    }

    return -1;
}


void seleccionarHabitacion(int piso){
    //Se elimino la validacion del piso ya que esta en panel.cpp

    cout << "------------------------------------------------------" << endl;
    cout<<"Habitaciones disponibles en el piso "<< piso << endl;

    for(int j=0;j <PISO[piso-1].nHabitaciones;j++){
        //si dentr esta el 0 es por ue esta desocupada
        if(ocupados[piso-1][j]==0){
            cout<<" - Habitacion #"<< (j+1)<< " : " << endl;
        }
    }
    cout<<endl;

    int num_Habitacion;
    cout << "------------------------------------------------------" << endl;
    cout<<"Numero de habitacion a reservar: ";
    cin>>num_Habitacion;

//si es mayor que el numero de habitaciones y ocupar dicho valor en el vector
    if(!(num_Habitacion>= 1 && num_Habitacion <= PISO[piso-1].nHabitaciones || ocupados[piso-1][num_Habitacion-1]==1)){
        cout<<"Habitacion invalida"<<endl;
        return;
    }
    cout << "Registrado exitosamente" << endl;
    system ("pause");
    factura[posicionUsuarios - 1].habiA = num_Habitacion;
    factura[posicionUsuarios- 1].catA = PRECIO[posicionUsuarios];
    //factura[posicionUsuarios - 1].catA = 

    //ocupar habitacion en panel
    ocupados[piso-1][num_Habitacion-1]=1;
    usuarios[posicionUsuarios-1].num_Habitacion=num_Habitacion;
}


//Reservar habitaciones
//buscar_usuarioPorDNI ya no devuelve un valor 
void reservarHabitacion(){
    system("cls");
    int piso;
    
    int usuarioEncontrado = buscar_usuarioPorDNI();

    //Verificar si tiene o no una habitacion
    if(usuarioEncontrado==1){
        for(int i=0;i<TotalUsuarios;i++){
            if(usuarios[i].DNI==dni){
                cout<<"Usuario encontrado" <<endl;
                system ("pause");
                usuarioEncontrado=i;
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
