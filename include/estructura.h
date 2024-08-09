//se anadira y declarara los registros globales
#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include <string>
#define MAX_PRODUCTOS 100

// Estructura del administrador del hotel
struct ADMIN {
    std::string NombreAdmin;
    std::string nombreHotel;
};

//Falta definir que tipo de variable es o si es un arreglo
extern ADMIN admin;

//Registros globales principales principales
struct USUARIO {
    std::string Nombre;
    int edad;
    int num_Habitacion;
    std::string DNI;
    int deuda;
};

struct Piso {
    int nHabitaciones;
    std::string categoriasHabitaciones[20];
    float preciosHabitaciones[20];
    //
    int NroHabitaciones[20];
};

struct Producto {
    std::string nombre;
    float precio;
};

struct Report {
    std::string nombre;
    std::string DNI;
    //SE NECESITA CAMBIO EN el nombre de las variables no se eniende que es
    float totalPagar;
    std::string habiA;
    std::string catA;
    float preA;
};

//reporte
extern Report factura[100];
extern int facturados;
extern int facturadosGestion;

// Declaracion de variables globales 
//cafeteria
extern Producto menu[MAX_PRODUCTOS];
extern int cantidadProductos;
extern Producto seleccion[MAX_PRODUCTOS];

//Gestion
extern USUARIO usuarios[100];
extern int TotalUsuarios;

//mantenimiento 
extern int nCategorias;
extern std::string CAT[20];
extern int nPisos;
extern std::string CATEGORIA[20];
extern float PRECIO[20];
//P=Pisos?
extern Piso PISO[20];
extern int ocupados[100][100];

// Hotel a travez del panel
extern int hotel[100][100];

//panel variables necesarias para llenar con 1 y 0 
extern int po;
extern int ho;
extern int op;

//de preferencia seria mejor usar una variable bool y while para salir 
extern int salir;

//Se agrego posicionUsuarios(gestion) para saber donde colocar 1 y 0
extern int posicionUsuarios;
//El dni que se va a comparar con el ingresado anteriormente 
extern std::string dni; 

#endif 