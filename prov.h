//Archivo .h Programado por --> Teodoro Sibón Jiménez

#ifndef _PROV_H_
#define _PROV_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Estructura para "Admin.txt" --> Almacena la informacion del fichero
typedef struct{
char id[10];         //Identificador del proveedor
char contrasena[15];    //Contrasena del proveedor
char empresa[15];       //Nombre de la empresa a la que pertenece
char nom[10];   //Nombre del proveedor
char email[30]; //Email del proveedor
}prov;

int nProvs;          //Numero de clientes en "Clientes.txt"
prov *vProvs;     //vClientes es un puntero con la direccion de inicio de un vector de clientes
void cargarProvs(prov **,int *);   //Recibe un vector de estructura de tipo cliente y un numero referente a la cantidad de estructuras a cargar
void imprimeProvs(prov *,size_t);    //Recibe un vector de estructuras de tipo cliente y un numero referente al numero de estructuras a imprimir

void MenuProv(char *);//Recibe el id del  proveedor y muestra la lista de opciones
	void MenuProvPerfil(char *);
		void consultaPerfilP(prov **,int *,char *);
		void modificaPerfilP(prov **,int *,char *);
	//

//void MenuProvProductos();
//void MenuProvPedidos();

#endif
