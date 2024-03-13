//Archivo .h Programado por --> Teodoro Sibón Jiménez
#ifndef _ADMIN_H_
#define _ADMIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "prov.h"



//Estructura para "Admin.txt" --> Almacena la informacion del fichero
typedef struct{
char id[10];         //Identificador del admin
char contrasena[15];    //Contrasena del admin
char nom[10];   //Nombre del admin
char email[30]; //Email del admin
}admin;

int nAdmins;        //Numero de Adminprovs en "Adminprov.txt"
admin *vAdmins;  //vAdminprovs es un pùntero con la direccion de inicio de un vector de adminprovs

void cargarAdmins(admin **,int *);// Recibe un vector de  estructura de tipo adminprov y un numero referente a la cantidad de estructuras a cargar
void imprimeAdmins(admin *,size_t );//Recibe un vector de estructuras de tipo adminprov y un numero referente al numero de estructuras a imprimir

void MenuInicio(admin *,int,cliente *,int,prov *,int); //Recibe la lista de administradores,clientes y proveedores y te presenta un menu de inicio de sesion que deriva en los demas dependiendo de que usuario loguee
void MenuAdmin(char *);

	void MenuAdminPerfil(char *);
		void consultaPerfil(admin **,int *,char *);
		void modificaPerfil(admin **,int *,char *);
	//
	void MenuAdminClientes();	//Recibe el listado de clientes y muestra un menu con opciones para la lista que puede modificar
		void listarCliente(cliente**,int *);
		void busquedaCliente(cliente**,int *);
		void addCliente(cliente**,int *);
		void removeCliente(cliente**,int *);
		void modificaCliente(cliente**, int *);
	//
	void MenuAdminProveedores();
		void listarProveedor(prov**, int *);
		void busquedaProveedor(prov**, int *);
		void addProveedor(prov**, int *);
		void removeProveedor(prov**, int *);
		void modificaProveedor(prov**, int *);
	//
//	void MenuAdminProductos();//recibe el listado de productos y muestra la lista con opciones

//	void MenuAdminCategorias();//Recibe el listado de categorias de productos y muestra la lista de opciones

//void MenuAdminPedidos(pedidos **,char *);//Recibe el listado de pedidos de productos y muestra las opciones
//void MenuAdminTransportistas(transportistas **,char *);
//void MenuAdminDescuentos(descuentos **,char *);
//void MenuAdminDevoluciones(devoluciones **,char *);
//void MenuAdminSalir();

#endif
