//main.cpp 

#include <iostream>
#include <string>
#include "panel.h"
#include "gestion.h"
#include "mantenimiento.h"
#include "cafeteria.h"
#include "reportes.h"

using namespace std;

//declaracion de las funciones en main.cpp
void mostrarBienvenida();
void mostrarInicio();
void mostrarDespedida();

void mostrarDespedida(){
	
	system("cls");
	cout<<"======================================================"<<endl;
	cout<<"======================================================"<<endl;
	
	cout<<"          GRACIAS POR USAR EL PROGRAMA!"<<endl;
	
	cout<<"======================================================"<<endl;
	cout<<"======================================================" << endl;
	
}
void mostrarBienvenida(){
    cout << "========== BIENVENIDO A LA GESTION DE HOTEL ==========" << endl;
    cout << "Antes de empezar:" << endl;
    cout << " - Diganos sus nombres: "; cin >> admin.NombreAdmin;
    cout << " - Contrasena: "; cin >> admin.Contrasena;
}

void mostrarInicio(){
    int opcion;
    system ("cls");
    
    do {
        system ("cls");
        cout << "================== GESTION DE HOTEL ==================" << endl;
        cout << "======================= INICIO =======================" << endl;
        cout << " 1. Panel" << endl;
        cout << " 2. Gestion" << endl;
        cout << " 3. Mantenimiento" << endl;
        cout << " 4. Tienda" << endl;
        cout << " 5. Reportes" << endl;
        cout << " 0. Salir" << endl;
        cout << "======================================================" << endl;
        cout << "Seleccione una opcion: " << endl;

        cin >> opcion;
        switch (opcion){
            case 1:
                panel();
            break;
            case 2:
                gestion();
            break;
            case 3:
                mantenimiento();
            break;
            case 4:
                cafeteria();
            break;
            case 5:
                reportes();
            break;
            case 0:
            
                cout << "Saliendo . . . " << endl;
                system ("pause");
            break;
            default:
            system ("pause");
            system("cls");
            cout << "Opcion no valida." << endl;

        }
    } while (opcion != 0);
}

int main (){
    mostrarBienvenida();
    mostrarInicio();
    mostrarDespedida();
    return 0;
}