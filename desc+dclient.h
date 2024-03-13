//Archivo .h Programado por --> José Manuel Troya Valero
#ifndef _DESC+DCLIENT_H_

#define _DESC+DCLIENT_H_
#include "clientes.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//Estructura para descuentos -->  contiene los datos de "Descuentos.txt"
typedef struct{
char id_cod[20];
char desc_desc[30];
char tipo[20]; //si es codigo promocional(codpro) o cheque regalo(cheqreg)
int estado[20];//Activo/noactivo
float importe;
char aplic[10];//si es aplicable a todos los productos esizon/ O no lo es  (todo/esizon
}descuento;
//Estructura para descuentos de clientes
typedef struct{
char id_client[20];
char id_cod[20];//debe ser que (descuent) desc_desc
char fech_asig[15];//Sin formato
char fech_cad[15];
char estado[20];//Activo o No activo
}desclient;

///////////////////////////////////VARIABLES A UTILIZAR Y ESTRUCTURAS////////////////////////////////
int nDescuentos; //Numero de descuentos en "Descuentos.txt"
int nDesclient;
descuento *vDescuento;// vector de estructura que contiene la direccion de inicio de un vector de descuentos
desclient *vDesclient;
/////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////FUNCIONES DE CARGA Y DESCARGA////////////////////////////////////
void cargarDesclient(desclient**,int*);
void imprimeDesclient(desclient *,size_t );
void cargarDescuentos(descuento **,int *);//Recibe un vector de estructura de tipo descuento y un numero referente a la cantidad de estructuras a cargar
void imprimeDescuentos(descuento *, size_t );//Recibe un vector de estructuras de tipo descuento  y un numero referente al numero de estructuras a imprimir en el fichero
/////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////FUNCIONES UTILIZADAS POR MENU ADMINISTRADORES(DESCUENTOS)///////////////////
void MenuAdminDescuentos();
void listar_descuento(descuento**,int*);//Recibe un vector de estructura de tipo descuento, y hace una lista con todos los descuentosd
void busqueda_descuento(descuento**,int*);//Recibe un vector de estructura de tipo descuento, y busca los descuentos que indicque el usuario
void remove_descuento(descuento**,int *);//Recibe un vector de estructura de tipo descuento y un entero con el numero de datos que contine el vector, elimina un descuento indicado
void add_descuento(descuento**,desclient**,cliente**,int*,int *,int *);
void asig_desc(descuento**,desclient**,cliente**,int*,int *,int*);
void modifica_descuento(descuento**,int*);//Recibe un vector de estructura de tipo descuento, y modifica algun descuento
void listar_desc_client(descuento**,desclient**,cliente**,int*,int*,int*);
void calcula_fecha(char*);
void busc_desc_client(descuento**,desclient**,cliente**,int*,int*,int*);
void listar_desc_client_usado(descuento**,desclient**,cliente**,int*,int*,int*);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////FUNCIONES UTILIZADAS POR MENU CLIENTES (DESCUENTOS)///////////////////


void desc_client(desclient**,int*,char*);

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _DESC+DCLIENT_H_
