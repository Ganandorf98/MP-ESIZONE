
//Archivo .h Programado por --> Teodoro Sibón Jiménez

#ifndef _CLIENTE_H_
#define _CLIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//Estructura para "Clientes.txt" --> Almacena la informacion del fichero
typedef struct{
char id[10];             //Nombre de usuario del cliente al iniciar sesion
char contrasena[15]; //Contrasena del usuario al iniciar sesion
char nom[10];       //Nombre completo del cliente
char apell[10];     //Primer apellido del cliente
char direccion[30]; //Calle, Numero y Cod. postal del cliente
char localidad[15]; //Localidad cliente
char provincia[10]; //Provincia cliente
char email[30];     //email cliente
int cartera;        //monedas que posee el cliente
}cliente;

int nClientes;          //Numero de clientes en "Clientes.txt"
cliente *vClientes;     //vClientes es un puntero con la direccion de inicio de un vector de clientes

void cargarClientes(cliente **,int *);   //Recibe un vector de estructura de tipo cliente y un numero referente a la cantidad de estructuras a cargar
void imprimeClientes(cliente *,size_t);    //Recibe un vector de estructuras de tipo cliente y un numero referente al numero de estructuras a imprimir

void MenuCliente(char *);
	void MenuClientePerfil(char *);
		void consultaPerfilC(cliente **,int *,char *);
		void modificaPerfilC(cliente **,int *,char *);
	//

	//void MenuClienteProductos(productos **, char *);
	//void MenuClienteDescuentos(descuentos **, char *); //Recibe el id del cleinte y le permite consultar y modificar sus productos, pedidos descuentos, etc
	//void MenuClientePedidos(pedidos **,char *);
	//void MenuClienteDevoluciones(devoluciones **,char *);
//
#endif
