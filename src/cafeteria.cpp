//cafeteria.cpp

#include "cafeteria.h"
#include "estructura.h"
#include <iostream>
#include <string> 
#include <iomanip>//se incluye esta libreria para compilar el programa usando setw

using namespace std;

//cafeteria
void cafeteria(){
    int opcion;
    bool exit = false;
   
    while (!exit) {
        system("cls");
        cout <<"====================== CAFETERIA ====================="<< endl;
        cout <<" 1. Anadir Producto"<< endl;
        cout <<" 2. Eliminar Producto" << endl;
        cout <<" 3. Mostrar Productos" << endl;
        cout <<" 4. Vender Productos" << endl;
        cout <<" 0. Volver al inicio" << endl;
        cout <<"======================================================" << endl;
        cout <<" Seleccione una opcion: "; cin >> opcion;
        cin.ignore();
         
        switch (opcion) {
            case 1: 
                anadirProductos();
                break;
            case 2: 
                eliminarProductos();
                break;
            case 3: 
                mostrarProductos(); 
                cin.get();
                break;
            case 4: 
                venderProductos(); 
                cin.get();
                break;
            case 0: exit = true;
            	system("cls");
                break;
            default: 
                cout << " >>> [ OPCION NO VALIDA ] <<<" << endl;
                cin.get();
        }
    }
}

void mostrarProductos() {
    system("cls");
    cout << "Menu de Cafeteria:" << endl;
    cout << left << setw(30) << "Producto" << "Precio\n"; // Define ancho para la columna de productos
    cout << "------------------------------------------------------" << endl;
    
    for (int i = 0; i < cantidadProductos; i++) {
        cout << left << setw(30) << menu[i].nombre << menu[i].precio << endl;
    }
}

void venderProductos(){
	string fin = "si";
    string dniCafeteria;
    bool hayDNI = false;
    cout << "Ingrese el DNI del huesped: ";
    cin >> dniCafeteria;
    cin.ignore();
    for (int i = 0; i < 100; i++ ){
        if (dniCafeteria == usuarios[i].DNI){
            hayDNI = true;
            break;
        }
    }
    if (hayDNI){
        int cantidadSeleccion = 0;
        char nombre[30];
        int cantidad;
        system("cls");
        cout <<"Ingrese los productos que desee." << endl;
       
        while (true) {
        	
            cout <<"Nombre del producto: "; cin.getline(nombre, 30);
            
            string nombreProducto(nombre);
           
            int i = 0;
            for (i = 0; i < cantidadProductos; i++) {
                if (menu[i].nombre == nombreProducto) {
                    break;
                }
            }
            if (i < cantidadProductos) {
                cout <<"Ingrese la cantidad del producto a comprar: ";
                cin >> cantidad;
                cin.ignore();
                for (int j = 0; j < cantidad; j++) {
                    seleccion[cantidadSeleccion] = menu[i];
                    cantidadSeleccion++;
                }
            } else {
                cout <<"Producto no encontrado." << endl;
            }
            cout << endl;
            cout <<"Desea comprar algun producto mas?s/n ";cin >> fin;
            cin.ignore();
            if (fin == "no"){
                break;  
            }
        }
        if (cantidadSeleccion == 0) {
            cout <<"No se ha seleccionado ningun producto." << endl;
            return;
        }
       	
       	system("cls");
        float total = 0;
        cout <<"Factura:\n";
        cout <<"Producto                        Cantidad  Subtotal" << endl;
        cout <<"------------------------------------------------------" << endl;
       
        for (int i = 0; i < cantidadProductos; i++) {
            int cantidadProducto = 0;
            for (int j = 0; j < cantidadSeleccion; j++) {
                if (seleccion[j].nombre == menu[i].nombre) {
                    cantidadProducto++;
                }
            }
            if (cantidadProducto > 0) {
                float subtotal = cantidadProducto * menu[i].precio;
                total += subtotal;
                cout << menu[i].nombre;
                cout <<"                              "<< cantidadProducto <<"      "<< subtotal << '\n';
                for (int k = 0; k < 100; k++){
                    if (dniCafeteria == usuarios[i].DNI){
                        factura[i].nombre = usuarios[i].Nombre;
                        factura[i].DNI = usuarios[i].DNI;
                        factura[i].totalPagar = subtotal;
                        facturados++;
                    }
                }
            }
        }
       
        cout <<"------------------------------------------------------" << endl;
        cout <<"Total: "<< total << endl;
        system("pause");
    }
    else {
        cout << "Usuario no encontrado" << endl;
        system("pause");
    }
}

void anadirProductos(){

    system("cls");
    if (cantidadProductos >= MAX_PRODUCTOS) {
        cout <<"No se pueden agregar más productos. El menu esta lleno." << endl;
        return;
    }
    
    Producto nuevoProducto;
    cout << "=================== ANADIR PRODUCTO ==================" << endl;
    cout <<" - Ingrese el nombre del producto: ";
    getline(cin, nuevoProducto.nombre);
    cout <<" - Ingrese el precio del producto: ";
    cin >> nuevoProducto.precio;
    cin.ignore(); 
    menu[cantidadProductos] = nuevoProducto;
    cantidadProductos++;
    cout <<"Producto agregado con exito." << endl;
    cout << "======================================================" << endl;
    system("pause");
}

void eliminarProductos(){

    system("cls");
    string nombre;
    cout << "================= ELIMINAR PRODUCTO ==================" << endl;
    cout <<"Ingrese el nombre del producto: " << endl;
    cout << " - Nombre: ";
    getline(cin, nombre);
    
    int i;
    for (i =0;i<cantidadProductos;i++) {
        if (menu[i].nombre == nombre) {
            break;
        }
    }
    
    if (i < cantidadProductos) {
        for (int j=i;j<cantidadProductos-1;j++) {
            menu[j] = menu[j + 1];
        }
        cantidadProductos--;
        cout <<"Producto eliminado con exito." << endl;
        cout << "======================================================" << endl;
        system("pause");
    } 	else {
        	cout <<"Producto no encontrado." << endl;
            cout << "======================================================" << endl;
            system("pause");
    	}
}