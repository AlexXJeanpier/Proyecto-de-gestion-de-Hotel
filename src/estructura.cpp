#include "estructura.h"
#include <string>
//Inicializacion de las variables

//reportes
ADMIN admin;

Report factura[100];
int facturados = 0;
int facturadosGestion = 0;

//cafeteria
Producto menu[MAX_PRODUCTOS];
int cantidadProductos = 0;
Producto seleccion[MAX_PRODUCTOS];


//gestion
USUARIO usuarios[100];
int TotalUsuarios = 0;

//mantenimiento
int nCategorias = 0;
std::string CATEGORIA[20];
float PRECIO[20];
int nPisos = 0;
Piso PISO[20];

//panel
int hotel[100][100] = {0};
int ocupados[100][100] = {0};
int po = 0;
int ho = 0;
int op = 0;
int salir = 0;

int posicionUsuarios = 0;
std::string dni;

//Lo que falta 