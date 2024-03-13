
//Archivo .c Programado por --> José Manuel Troya Valero
#include "prod+categ.h"

//Cabecera: void listar_categoria(categoria**vCategoria,int *n)
//Precondicion: La estructura vCategoria es de tipo categoria y n es de tipo entero ambas deben estar inicalizadas
//Postcondicion:Crea una lista con las categorias que se encuentran en la estructura
void listar_categoria(categoria **vCategoria,int *n){
int i;
puts("A continuacion se mostraran todas las categorias de ESIZON:\n\n");
puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
for(i=0;i<(*n);i++){
    printf("Categoria --> %s \n",(*vCategoria)[i].des_categ);
    printf("ID de la categoria --> %s\n",(*vCategoria)[i].id_categ);
puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
    }
}


//Cabecera:void buscar_categoria(categoria**vCategoria,int *n)
//Precondicion:La estructura vCategoria es de tipo categoria y n es de tipo entero ambas deben estar inicalizadas
//Postcondicion:Permite buscar una categoria mediante su nombre o id
void buscar_categoria(categoria **vCategoria,int *n){
int i,a,j,encontrado=0,encontrado1=0,exit;
char name[15],id[10];
do{
printf("\nPulse 0 para realizar la busqueda mediante ID de la categoria\n");
printf("Pulse 1 para realizar la busqueda mediante el nombre de la categoria\n");
printf("--> ");scanf("%d",&a);

switch(a){
  case 0:
       printf("Introduzca el ID de la categoria --> "); fflush(stdin); scanf("%s",&id);
       for(i=0;i<(*n);i++){
        if(strcmp((*vCategoria)[i].id_categ,id)==0){
            puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
            printf("Datos de la categoria:\n");
             printf("Descripcion categoria --> %s \n",(*vCategoria)[i].des_categ);
             printf("ID de la categoria --> %s \n",(*vCategoria)[i].id_categ);
             puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
             encontrado=1;//si encontrado esta en 1 es que se habrá encontrado el producto en la base de datos
       }}
             if(encontrado==0){printf("\nEl Id introducido no se encuentra en la base de datos\n");}
             break;
  case 1:
  printf("Introduzca el nombre de la categoria --> "); fflush(stdin); scanf("%s",&name);
       for(i=0;i<(*n);i++){
        if(strcmp((*vCategoria)[i].des_categ,name)==0){
            puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
            printf("Datos de la categoria:\n");
             printf("Descripcion categoria --> %s \n",(*vCategoria)[i].des_categ);
             printf("ID de la categoria --> %s \n",(*vCategoria)[i].id_categ);
             puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
             encontrado1=1;//si encontrado esta en 1 es que se habrá encontrado el producto en la base de datos
       }}
             if(encontrado1==0){printf("\nEl nombre introducido no se encuentra en la base de datos\n");}
             break;
             }
             do{
             printf("Pulse 1 para buscar otra categoria/Pulse 2 para salir de (buscar categorias)-->  "); scanf("%d",&exit);
             }while(exit!=1&&exit!=2);

             }while(exit==1);
             }



//Cabecera:void modifica_categoria(categoria**vCategoria,int *n);
//Precondicion:La estructura vCategoria es de tipo categoria y n es de tipo entero ambas deben estar inicalizadas
//Postcondicion:Permite realizar la modificacion de un dato de tipo categoria proporcionando su id
void modifica_categoria(categoria **vCategoria,int *n){
int i,a,encontrado=0;
char id[10],new_id[10],new_desc[30];
printf("Introduce el ID de la categoria a la que desea modificar sus datos --> ");
fflush(stdin);
scanf("%s",&id);
for(i=0;i<(*n);i++){
    if(strcmp((*vCategoria)[i].id_categ,id)==0){
        encontrado=1;//si encontado=1 es porque se ha encontrado el dato en la estructura
        printf("Indique la accion que desea realizar:\n");//Preguntamos que cambio desea realizar el usuario
        puts("1 Cambiar ID de la categoria");
        puts("2 Cambiar La descripcion de la categoria");
        do{
        printf("--> "); scanf("%d",&a);
        }while(a!=1&&a!=2);
        //Creamos un switch para modificar el dato que hay escogido el usuario
        switch(a){
        case 1:
            printf("Introduce el nuevo ID de la categoria --> ");
            fflush(stdin);
            scanf("%s",&new_id);
            strcpy((*vCategoria)[i].id_categ,new_id);//Se copiara el nuevo id en la poscion de memoria i de la estructura Vcategoria
            break;
        case 2:
            printf("Introuce La nueva descripcion de la categoria --> ");
            fflush(stdin);
            scanf("%s",&new_desc);
            strcpy((*vCategoria)[i].des_categ,new_desc);//Se copiara la nueva descripcion de categoria en la poscion de memoria i de la estructura Vcategoria
            break;}
            }



     }
     if(encontrado==0){puts("El ID introducido no se ha encontrado en la Base de datos");}

      else{puts("Los datos han sido modificados correctamente");}

}

//Cabecera:void add_categoria(categoria **vCategoria,int *n)
//Precondicion:La estructura vCategoria es de tipo categoria y n es de tipo entero ambas deben estar inicalizadas
//Postcondicion:Permite añadir una nueva categoria
void add_categoria(categoria **vCategoria,int *n){
    *vCategoria=realloc((categoria *)(*vCategoria),((*n)+1)*sizeof(categoria));
   fflush(stdin);

    printf("\nIntroduce los nuevos datos de la categoria:\n");
    puts("\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
    printf("\nIntroduce el nombre de la categoria --> "); scanf("%s",&(*vCategoria)[*n].des_categ); fflush(stdin);
    printf("\nIntroduce el ID de la categoria --> ");     scanf("%s",&(*vCategoria)[*n].id_categ);fflush(stdin);
    puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n" );
    (*n)++;
    printf("Los datos se han guardado correctamente\n");
}


//Cabecera:void remove_categoria(categoria **vCategoria,int *n)
//Precondicion:La estructura vCategoria es de tipo categoria y n es de tipo entero ambas deben estar inicalizadas
//Postcondicion:Permite eliminar un producto
void remove_categoria(categoria **vCategoria,int *n){
    int i,aux;
char remove[10];
printf("Introduce el ID de la categoria que desea eliminar --> "); scanf("%s",&remove);
for(i=0;i<(*n);i++){ //Buscamos el id del producto que tiene el ID introducido por usuario
    if(strcmp((*vCategoria)[i].id_categ,remove)==0){
         aux=i;}
}
//Desplazamos todos los productos una posicion
for(i=aux;i+1<(*n);i++){
        strcpy((*vCategoria)[i].id_categ,(*vCategoria)[i+1].id_categ);//Desplazamos elementos una posicion
        strcpy((*vCategoria)[i].des_categ,(*vCategoria)[i+1].des_categ);}//Desplazamos elementos una posicion
        (*n)--;//Reajustamos n
        *vCategoria=realloc((categoria *)(*vCategoria),((*n))*sizeof(categoria));//Reajustamos la memoria del vector para que tenga uno menos
   printf("\nLa categoria se elimino correctamente\n");
}




//Postcondicion: Permite hacer una lista de los productos por categoria
//Cabecera: void MenuCategAmin()
//Precondicion:-----
//Postcondiciomn: Crea un menu con las opciones que tiene un administrador en el menu categorias
void MenuAdminCategorias(){
int a,exit;
puts("Bienvenido al menu de Categorias (Administrador)\n");
printf("Cargando datos del fichero Categorias.txt....\n");
cargarCategorias(&vCategoria,&nCategorias);
do{
printf("\nElija una opcion:\n");
puts("1 Listar categorias");
puts("2 Anadir categoria");
puts("3 Eliminar categoria");
puts("4 Buscar categoria");
puts("5 Modificar categoria");
puts("6 Listar productos por categoria");
fflush(stdin);
printf("--> ");scanf("%d",&a);
switch(a){
case 1: listar_categoria(&vCategoria,&nCategorias);break;
case 2: add_categoria(&vCategoria,&nCategorias);break;
case 3: remove_categoria(&vCategoria,&nCategorias);break;
case 4: buscar_categoria(&vCategoria,&nCategorias);break;
case 5: modifica_categoria(&vCategoria,&nCategorias);break;
case 6:
    cargarProductos(&vProducto,&nProductos);//Cargamos la estructura de productos(Vproductos)
    listar_categoria_prod(&vCategoria,&vProducto,&nCategorias,&nProductos);
    break;}

do{
printf("\n\nPulse 1 para realizar otra operacion/Pulse 2 para salir --> ");scanf("%d",&exit);
}while(exit!=1&&exit!=2);
}while(exit==1);
puts("\n");
imprimeCategorias(vCategoria,nCategorias);
}

/*LA SIGUIENTE FUNCION (MAIN) SIRVE PARA COMPROBAR QUE TODOS LOS MENUS FUNCIONAN CORRECTAMENTE
  INDEPENDIENTEMENTE DEL PROGRAMA PRONCIPAL
  SI EXISTE ALGUN FALLO EN EL PROGRAMA PRINCIPAL SE PODRA COMPROBAR EL CORRECTO FUNCIONAMIENTO
  DE LAS FUNCIONES PROGRAMADAS POR  (JOSÉ MANUEL TROYA) , UTILIZANDO LA FUNCION MAIN.*/
/*int main(){
printf("Usted a seleccionado menu categorias\n\n");
MenuAdminCategorias();
//NOTA"Solo los administradores pueden acceder al menu de categorias"
return 0;
}*/




