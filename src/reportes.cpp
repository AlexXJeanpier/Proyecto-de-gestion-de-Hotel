//reportes.cpp 

#include "reportes.h"
#include "estructura.h"
#include "gestion.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//interfaz de la funcion 
void reportes(){
    system("cls");

    int opcion;

    do {
        cout << "====================== REPORTES ======================" << endl;
        cout << " 1. Ver historial" << endl;
        cout << " 2. Completar un pago" << endl;
        cout << " 0. Volver al inicio" << endl;
        cout << "======================================================" << endl;
        cout << " Seleccione una opcion: "; cin >> opcion;

        switch (opcion){
            case 1: 
                verHistorial();
            break;
            case 2: 
                completarPago();
            default:
                cout << " >>> [ OPCION NO VALIDA ] <<<"<< endl;
                system ("cls");
        }
    } while (opcion != 0); 
}

//funcion para imprimir los datos del usuario en base a su nombre
void verHistorial(){

    system ("cls");
    string dniReportes;
    cout << "=================== VER HISTORIAL ====================" << endl;
    cout << "Ingrese el DNI del usuario cuyo historial desea ver: " << endl;
    cout << " - DNI: ";
    cin.ignore();
    getline(cin, dniReportes);
    cout << "------------------------------------------------------" << endl;

    //busqueda del usuario por el DNI
    bool encontrado = false;
    for (int i = 0; i < TotalUsuarios; ++i) {
        if (usuarios[i].DNI == dniReportes) {
            encontrado = true;
            // Se va a mostrar la información del usuario
            cout << "Datos del usuario encontrado:" << endl << endl;
            cout << " - Nombre: " << factura[i].nombre << endl;
            cout << " - DNI: " << factura[i].DNI << endl;
            cout << " - Habitacion: " << factura[i].habiA << endl;
            cout << " - Deuda actual: $" << factura[i].totalPagar << endl;
            
            // Se mostrara la información del piso
            for (int j = 0; j < nPisos; ++j) {
                if (PISO[j].NroHabitaciones[j] == usuarios[i].num_Habitacion) {
                    cout << " - Categoria del piso: " << PISO[j].categoriasHabitaciones[j] << endl;
                    break;
                }
            }
            break;
        }
    }
    
    if (!encontrado) {
        system("cls");
        cout << "Usuario no encontrado." << endl;
        system ("pause");
        cout << "======================================================" << endl;
    }
}

//se empieza por buscar de nuevo su DNI
void completarPago(){
    string dniPago;
    system("cls");
    cout << "================= COMPLETAR UN PAGO ==================" << endl;
    cout << "Ingrese el DNI del usuario para completar el pago: " << endl;
    cout << " - DNI: ";
    cin.ignore();
    getline(cin, dniPago);
    cout << "------------------------------------------------------" << endl;

    bool encontrado = false;
    for (int i = 0; i < TotalUsuarios; ++i) {
        if (factura[i].DNI == dniPago) {
            encontrado = true;
            cout << "Monto a pagar del usuario:" << endl;
            cout << " Precio por cafeteria: "<< factura[i].totalPagar << endl;
            cout << " Precio por habitacion: " << endl;
            cout << " TOTAL A PAGAR: " << endl;
            cout << factura[i].nombre << " - $" << factura[i].totalPagar << endl;
            
            float montoPago;
            cout << "------------------------------------------------------" << endl;
            cout << "Ingrese el monto a pagar: " << endl;
            cout << " - Monto: " << endl;
            cin >> montoPago;
            
            if (montoPago > factura[i].totalPagar) {
                cout << "------------------------------------------------------" << endl;
                cout << "El monto ingresado es mayor que la deuda actual. No se puede completar el pago." << endl;
            } else {
                factura[i].totalPagar -= montoPago;
                cout << "------------------------------------------------------" << endl;
                cout << "Pago completado. La nueva deuda del usuario " << factura[i].nombre << " es: $" << usuarios[i].precioCategoria<< endl;
            }
            break;
        }
    }
    
    if (!encontrado) {
        system("cls");
        cout << "Usuario no encontrado." << endl;
        system ("pause");
        cout << "======================================================" << endl;
    }
}