//Archivo .h Programado por --> José Manuel Troya Valero
#ifndef _PROD+CATEG_H_
#define _PROD+CATEG_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Estructura categorias--> almacenara la informacion de "Categorias.txt"
typedef struct{
char id_categ[10];
char des_categ[30];
}categoria;

//Estructura de productos -->  almacenara la informacion de "Productos.txt"
typedef struct{
char id_prod[10];
char desc_prod[40];
char categ[30];
char gest[10];
int stock;// numero de productos que tenemos
int entrega;
float precio;
}producto;

/////////////////////VARIABLES Y ESTRUCTURAS/////////////////////////////////////////////
int nCategorias;//Recibe el numero de categorias en el fichero "Categorias.txt"
categoria *vCategoria; //vCategoria es un puntero con la direccion de inicio de un vector de categoria
int nProductos;//Contiene el numero de productos que hay en "Productos.txt"
producto *vProducto;//vProducto es un puntero con la direccion de inicio de productos
////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////FUNCIONES DE CARGA Y DESCARGA DE PRODUCTOS Y CATEGORIAS////////////////////////////////////////////////
void cargarCategoria(categoria **,int *);//Recibe un vector de estructura de tipo categoria y un numero referente a la cantidad de estructuras a cargar
void imprimeCategoria(categoria *, size_t );//Recibe un vector de estructura de tipo categoria y un numero referente a la cantidad de estructuras a imprimir en el fichero
void cargarProductos(producto **,int *);//Recibe un vector de estructura de tipo producto y un numero referente a las estructuras a cargar
void imprimeProductos(producto *,size_t );//Recibe un vector de estructuras de tipo producto y un numrto referente al numero de estructuras a imprimir en el fichero "Productos.txt"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<CATEGORIAS>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

/////////////////////////////////////FUNCIONES DEL MENU ADMIN (CATEGORIAS)///////////////////////////////
void MenuAdminCategorias();
void listar_categoria(categoria**,int *);//*A* recibe la estructura categoria y permite listar todas las categorias
void buscar_categoria(categoria**,int *);
void add_categoria(categoria**,int *);//*A*   recibe la estructura categoria y un indicador del numero de estructuras que hay, permite añadir mas categorias;
void remove_categoria(categoria**,int *);//*A*   recibe la estructura categoria y un indicador del numero de estructuras que hay, permite quitar categorias
void modifica_categoria(categoria**,int *);//*A*  recibe la estructura categoria y permite hacer modificaciones de las categorias
void listar_categoria_prod(categoria**,producto**,int *,int *);//*A*C* recibe la estructura producto y la estructura categoria incializadas y mostrara todos losproductos que pertencen a la categoria indicada
////////////////////////////////////////////////////////////////////////////////////////////////////////


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<FIN CATEGORIAS>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<PRODUCTOS>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

///////////////////////////////////////FUNCIONES MENU ADMIN(PRODUCTOS)//////////////////////////////////////////
void  MenuAdminProductos();
void listar_producto(producto**,int *);//*A* recibe la estructura producto y permite listar todos los productos
void busqueda_producto(producto**,int *);//*A* recibe la estructura producto y permite buscar un producto
void add_producto(producto**,int *);//*A*   recibe la estructura producto y un indicador del numero de estructuras que hay, permite añadir mas productos;
void remove_producto(producto**,int *);//*A*   recibe la estructura producto y un indicador del numero de estructuras que hay, permite quitar productos
void modifica_producto(producto**,int *);//*A*  recibe la estructura producto y permite hacer modificaciones a los administradores
///////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////FUNCIONES MENU CLIENTE(PRODUCTOS)////////////////////////////////////////////////////////////////

void MenuClientProductos();
//void busqueda_producto(producto**,int *);// SE ENCUENTRA  YA DECLARADA
//void listar_categoria_prod(categoria**,producto**,int *,int *);// SE ENCUENTRA  YA DECLARADA
void busc_prod_categ(categoria**,producto**,int *,int *);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////FUNCIONES MENU PROVEEDOR(PRODUCTOS)//////////////////////////////////////////////////////////
void MenuProvProductos(char*);//Menu con las opciones dentro de proveedor (PRODUCTOS)
void listar_producto_prov(producto**,int*,char*);//*P* recibe la estructura producto y el id del gestor permite listar solo los productos del gestor
void busqueda_producto_prov(producto**,int*,char*);//*P* recibe la estructura producto y el id del gestor permite buscar productos del gestor
void add_producto_prov(producto**,int *,char* );//*P*   recibe la estructura producto y un indicador del numero de estructuras que hay y el id del gestor, permite añadir mas productos;
void remove_producto_prov(producto**,int *,char* );//*P*   recibe la estructura producto , un indicador del numero de estructuras y el id del gestor, permite quitar productos
void modifica_producto_prov(producto**,int *,char *);//*P* recibe la estructura y el id del gestor permite modificar productos del gestor
void listar_categoria_prod_prov(categoria**,producto**,int *,int *,char*);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<FIN PRODUCTOS>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


#endif // _PROD+CATEG_H_
