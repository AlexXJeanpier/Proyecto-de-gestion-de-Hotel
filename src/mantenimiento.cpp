
#include "mantenimiento.h"
#include "estructura.h"
#include <iostream>
#include <string>

using namespace std;

void iniciar(){
	string categoria;
	float precio;

	system("cls");
	cout<<"====================== INICIAR ======================="<<endl<<endl;
	cout<<"Complete los siguientes datos:"<<endl<<endl;
	
	// ingresar numero de pisos	
	cout<<" - Numero de pisos: "; cin>>nPisos;
	
	// ingresar categorias y precios
	cout<<" - Numero de categorias: "; cin>>nCategorias;
	cin.ignore();
	cout<<endl;
	
	for(int i=0; i<nCategorias; i++){
		cout<<"   Categoria #"<<i+1<<": "; getline(cin, categoria);
		CATEGORIA[i]=categoria;
		cout<<"   Precio #"<<i+1<<": "; cin>>precio;
		PRECIO[i]=precio;
		cin.ignore();
		cout<<endl;
	}
    
	// mostrar categorias y precios ingresados
	cout<<"------------------------------------------------------"<<endl;
	cout<<"CATEGORIAS Y PRECIOS INGRESADOS: "<<endl<<endl;
	for(int i=0; i<nCategorias; i++){
		cout<<"   "<<CATEGORIA[i]<<" - S/ "<<PRECIO[i]<<endl;
	}
	cout<<"------------------------------------------------------"<<endl<<endl;
	
	system("pause");
	system("cls");
	   
	// ingresar numero de habitaciones por piso
	for(int i=0; i<nPisos; i++){
		cout<<"Numero de habitaciones en el piso #"<<i+1<<": "; cin>>PISO[i].nHabitaciones;
		cin.ignore();
	}
	
	// asignar categoria a cada habitacion
	cout<<endl;
	cout<<"Asigne categorias a cada habitacion:"<<endl<<endl;
	for(int i=0; i<nPisos; i++){
		for(int j=0; j<PISO[i].nHabitaciones; j++){
			cout<<"   Piso #"<<i+1<<", Habitacion #"<<j+1<<" : "<<endl;
			cout<<"   - Categoria: "; getline(cin, categoria);
			PISO[i].categoriasHabitaciones[j]=categoria;
			
			// asignar precio basado en la categoria
			for(int k=0; k<nCategorias; k++){
				if(CATEGORIA[k]==categoria){
					PISO[i].preciosHabitaciones[j]=PRECIO[k];
					break;
				}
			}
			cout<<endl;
		}
	}
    
	// mostrar categorias y precios asignados a las habitaciones
	cout<<"------------------------------------------------------"<<endl;
	cout<<"Categorias asignadas a cada habitaciones:"<<endl;
	for(int i=0; i<nPisos; i++){
		cout<<endl;
		cout<<"   Piso #"<<i+1<<":"<<endl;
		for(int j=0; j<PISO[i].nHabitaciones; j++){
			cout<<"   - Habitacion #"<<j+1<<": "<<PISO[i].categoriasHabitaciones[j]<<" - S/ "<<PISO[i].preciosHabitaciones[j]<<endl;
		}
	}
	cout<<"------------------------------------------------------"<<endl<<endl;

	cout<<"======================================================"<<endl<<endl;    
}

void agregarHabitaciones(int pisoIndex){
	int nNuevasHabitaciones;
	string categoria;
	
	cout<<"Numero de habitaciones nuevas para el piso #"<<pisoIndex+1<<": ";
	cin>>nNuevasHabitaciones;
	cin.ignore();
	
	int habitacionInicio=PISO[pisoIndex].nHabitaciones;
	PISO[pisoIndex].nHabitaciones=PISO[pisoIndex].nHabitaciones+nNuevasHabitaciones;
	
	cout<<endl;
	for(int j=habitacionInicio; j<PISO[pisoIndex].nHabitaciones; j++){
		cout<<"   Habitacion #"<<j+1<<" : "<<endl;
		cout<<"   - Categoria: "; getline(cin, categoria);
		PISO[pisoIndex].categoriasHabitaciones[j]=categoria;
		
		for(int k=0; k<nCategorias; k++){
			if(CATEGORIA[k]==categoria){
				PISO[pisoIndex].preciosHabitaciones[j]=PRECIO[k];
				break;
			}
		}
		cout<<endl;
	}
}

void editar(){
	int opcion;
	int pisoIndex;
	char agregarAhora;
	
	system("cls");
	do{
		cout<<"======================= EDITAR ======================="<<endl;
		cout<<" 1. Agregar piso"<<endl;
		cout<<" 2. Agregar habitacion"<<endl;
		cout<<" 0. Regresar"<<endl;
		cout<<"======================================================"<<endl;
		cout<<" Seleccione una opcion: "; cin>>opcion;
		cin.ignore();
		
		switch(opcion){
			case 1:
				// agregar piso -> agregar habitaciones a nuevo piso
				system("cls");
				nPisos++;
				cout<<"==================== AGREGAR PISO ===================="<<endl;
				cout<<"PISO #" <<nPisos<<" AGREGADO."<<endl;
				cout<<"Desea agregar habitaciones ahora? (S/N): ";
				cin>>agregarAhora;
				cin.ignore();
				cout<<endl;
				
				// agregar habitaciones ahora
				if(agregarAhora=='s'||agregarAhora=='S')
					agregarHabitaciones(nPisos-1);
				break;
				
			case 2:
				// agregar habitaciones a un piso existente
				system("cls");
				cout<<"================= AGREGAR HABITACION ================="<<endl<<endl;;
				cout<<"Ingrese el piso (1-"<<nPisos<<"): ";
				cin>>pisoIndex;
				cin.ignore();
				
				if(pisoIndex>=1 && pisoIndex<=nPisos){
					cout<<endl;
					agregarHabitaciones(pisoIndex-1); 	
				} else{
					cout<<">>> [ NUMERO DE PISO NO VALIDO ] <<<"<<endl<<endl;
				}
				break;		
						
			case 0:
				// regresar al menu de mantenimiento
				system("cls");
				break;			
					
			default:
				cout<<" >>> [ OPCION NO VALIDA ] <<<"<<endl<<endl;
				break;
		}
	} while(opcion!=0);
}

void visualizar(){
	system ("cls");
	cout<<"===================== VISUALIZAR ====================="<<endl;
	
	// encontrar el numero maximo de habitaciones en cualquier piso
	int maxHabitaciones=0;
	for(int i=0; i<nPisos; i++){
		if(PISO[i].nHabitaciones>maxHabitaciones)
			maxHabitaciones=PISO[i].nHabitaciones;
	}
	
	// imprimir encabezado de cada piso
	for(int i=0; i<nPisos; i++){
		cout<<" >> PISO "<<i+1<<" <<\t";
	}
	cout<<endl;
	
	// imprimir la informacion de cada habitacion por piso
	for(int j=0; j<maxHabitaciones; j++){
		for(int i=0; i<nPisos; i++){
			if(j<PISO[i].nHabitaciones)
				cout<<"#"<<j+1<<" ["<<PISO[i].categoriasHabitaciones[j]<<"]\t";
			else
				cout<<"\t\t";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"======================================================"<<endl<<endl;
}

void mantenimiento(){
	int opcion;
	
	system("cls");
	do{
		cout<<"=================== MANTENIMIENTO ===================="<<endl;
		cout<<" 1. Iniciar"<<endl;
		cout<<" 2. Editar"<<endl;
		cout<<" 3. Visualizar"<<endl;
		cout<<" 0. Salir"<<endl;
		cout<<"======================================================"<<endl;
		cout<<" Seleccione una opcion: "; cin>>opcion;
		
		switch(opcion){
			case 1:
				iniciar();
				break;
			case 2:
				editar();
				break;
			case 3:
				visualizar();
				break;
			case 0:
				// salir al menu de main.cpp
				system("cls");
				break;
			default:
				cout<<" >>> [ OPCION NO VALIDA ] <<<"<<endl<<endl;
				break;
		}
	} while(opcion!=0);
}
