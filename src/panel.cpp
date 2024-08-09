//panel.cpp  

#include "panel.h"
#include "estructura.h"
#include "gestion.h" // Para poder usar la funcion seleccionarHabitacion
#include <iostream>
#include <string>

using namespace std;


//continuar
void verPanel(){
    mostrarPanel();
    int piso;
    cout << "------------------------------------------------------" << endl;
    cout<<" - Seleccione el piso: "; cin >> piso;
    if(!(piso >= 1 && piso <= nPisos)) {
        cout << "Piso invalido" << endl;
        return;
    }

    seleccionarHabitacion(piso);
}



//corregir 
void mostrarPanel() {
    system("cls");
    for (int i = 0; i < nPisos; i++) {
        cout << "Piso #" << i+1 << "  ";
        for (int j = 0; j < PISO[i].nHabitaciones; j++) {
            if (ocupados[i][j] == 1) {
                cout << "H-" << i+1 << j+1 << "[1] ";
            } else {
                cout << "H-" << i+1 << j+1 << "[0] ";

            }
        }
        cout << endl;
    }
    system ("pause");
    cin.ignore();
    cin.get();
}


//se puede hacer sin punteros
void mostrarTotalHabitaciones() {
    system("cls");
    int totalHabitaciones = 0;
    int habitacionesOcupadas = 0;

    for (int i = 0; i < nPisos; i++) {
        totalHabitaciones += PISO[i].nHabitaciones;
        for (int j = 0; j < PISO[i].nHabitaciones; j++) {
            if (ocupados[i][j] == 1) {
                habitacionesOcupadas++;
            }
        }
    }

    int habitacionesDisponibles = totalHabitaciones - habitacionesOcupadas;

    cout << "Total de habitaciones: " << totalHabitaciones << endl;
    cout << "Habitaciones ocupadas: " << habitacionesOcupadas << endl;
    cout << "Habitaciones disponibles: " << habitacionesDisponibles << endl;
    system("pause");
}

void panel() {
    int opcion;
   
    system("cls");
    do {
    	system("cls");
        cout << "==================== PANEL ====================" << endl;
        cout << "1. Ver habitaciones disponibles" << endl;
        cout << "2. Mostrar total de habitaciones" << endl;
        cout << "0. Salir" << endl;
        cout << "===============================================" << endl;
        cout << "Seleccione una opcion: "; cin >> opcion;
       
        switch(opcion){
            case 1:
                mostrarPanel();
                break;
            case 2:
                mostrarTotalHabitaciones();
                break;
            case 0:
                // salir al menu de main.cpp
                system("cls");
                break;              
            default:
                cout<<" >>> [ OPCION NO VALIDA ] <<<"<<endl;
                break;
        }
    } while(opcion!=0);
}