
//Archivo .c Programado por --> José Manuel Troya Valero

#include "prod+categ.h"




///////////////////////////////////////////////////FUNCIONES PARA ADMIN Y CLIENT///////////////////////////////////////

//Cabecera:void busc_prod_categ(categoria **vCategoria,producto **vProducto,int *nc,int *np)
//Precondicion:La estructura vCategoria es de tipo categoria , la estructura vProducto es de tipo producto, nc y np son enteros y todas las variables deben estar inicializadas
//Postcondicion:Permite hacer una lista con los productos que pertenecen a la categoria que introduce el usuario
void busc_prod_categ(categoria **vCategoria,producto **vProducto,int *nc,int *np){
char namecateg[30],idcat[10];
int i,encontrado=0,j;

printf("Introduce el nombre de la categoria --> ");
fflush(stdin);
scanf("%s",&namecateg);
//Buscamos el id de la categoria que tiene ese nombre para poder compararla con la estructura productos
for(i=0;i<(*nc);i++){
    if(strcmp((*vCategoria)[i].des_categ,namecateg)==0){//Si la categoria introducida es igual a la que hay en el vector:
        encontrado=1;
        strcpy(idcat,(*vCategoria)[i].id_categ);//idcat contiene el id de los productos que pertenecen a la categoria introducida pro usuario
          }
   }
if(encontrado==0){puts("No tenemos ninguna categoria con ese nombre");}
else{
//El id de categorias que buscabamos esta en idcat
printf("A continuacion se mostraran todos los productos en la categoria %s\n\n",namecateg);
printf("<<<Categoria: %s >>>\n",namecateg);
puts("-----------------------------------------------------------------\n");
 for(j=0;j<(*np);j++){//Recorremos todos los productos
          if(strcmp(idcat,(*vProducto)[j].categ)==0){//si el id de la categoria del producto y el id de la categoria coinciden:
           printf("Descripcion del producto --> %s \n",(*vProducto)[j].desc_prod);
           printf("Precio del producto: %.2f euros\n",(*vProducto)[j].precio);
           printf("ID del producto --> %s \n",(*vProducto)[j].id_prod);
           printf("ID de la categoria --> %s\n",(*vProducto)[j].categ);
           printf("ID del gestor del producto --> %s\n",(*vProducto)[j].gest);
           printf("Quedan %d en stock\n",(*vProducto)[j].stock);
           printf("Dias maximo para la entrega --> %d\n",(*vProducto)[j].entrega);
puts("-----------------------------------------------------------------\n");
          }
     }
}


}


//Cabecera: void listar_categoria_prod(categoria **vCategoria,producto **vProducto,int *nc,int *np)
//Precondicion: La estructura vCategoria es de tipo categoria , la estructura vProducto es de tipo producto, nc y np son enteros y todas las variables deben estar inicializadas
//Postcondicion:Permite hacer una lista de todos los productos clasificados por su categoria
void listar_categoria_prod(categoria **vCategoria,producto **vProducto,int *nc,int *np){
int i,j;

puts("A continuacion se mostrara una lista con los productos por categorias:\n");
for(i=0;i<(*nc);i++){//Recorremos todas las categorias que hay (solo su descripcion)
     puts("/////////////////////////////////////////////////////////////////////");
     printf("\n\n<<< Categoria: %s >>>\n",(*vCategoria)[i].des_categ);
     puts("-----------------------------------------------------------------\n");
     for(j=0;j<(*np);j++){//Recorremos todos los productos
          if(strcmp((*vCategoria)[i].id_categ,(*vProducto)[j].categ)==0){//si el id de la categoria del producto y el id de la categoria coinciden:
           printf("Descripcion del producto --> %s \n",(*vProducto)[j].desc_prod);
           printf("Precio del producto: %.2f euros\n",(*vProducto)[j].precio);
           printf("ID del producto --> %s \n",(*vProducto)[j].id_prod);
           printf("ID de la categoria --> %s\n",(*vProducto)[j].categ);
           printf("ID del gestor del producto --> %s\n",(*vProducto)[j].gest);
           printf("Quedan %d en stock\n",(*vProducto)[j].stock);
           printf("Dias maximo para la entrega --> %d\n",(*vProducto)[j].entrega);
           puts("-----------------------------------------------------------------\n");
          }
     }
}
}

//Cabecera: void listar_producto(producto **vProducto,int *n);
//Precondicion: La estructura vProducto es de tipo producto y el entero n deben estar inicializados
//Postcondicion hace una lista de productos mostrando
void listar_producto(producto **vProducto,int *n){
int i;
puts("A continuacion se mostraran todos los datos de todos los productos de ESIZON:\n\n");
puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
for(i=0;i<(*n);i++){
    printf("Descripcion del producto --> %s \n",(*vProducto)[i].desc_prod);
    printf("Precio del producto: %.2f euros\n",(*vProducto)[i].precio);
    printf("ID del producto --> %s \n",(*vProducto)[i].id_prod);
    printf("ID de la categoria --> %s\n",(*vProducto)[i].categ);
    printf("ID del gestor del producto --> %s\n",(*vProducto)[i].gest);
    printf("Quedan %d en stock\n",(*vProducto)[i].stock);
    printf("Dias maximo para la entrega --> %d\n",(*vProducto)[i].entrega);

puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
    }
}


//Cabecera: void busqueda_producto(producto **vProducto,int *n)
//Precondicion: La estructura vProducto es de tipo producto y el entero n deben estar inicializados
//Postcondicion:Permite realizar la busqueda de un producto y mostrar sus datos
void busqueda_producto(producto **vProducto,int *n){
int i,a,j,encontrado=0,encontrado1=0,exit;
char name[30],id[10];
do{
printf("\nPulse 0 para realizar la busqueda mediante ID del producto\n");
printf("Pulse 1 para realizar la busqueda mediante el nombre del producto\n");
printf("-->");scanf("%d",&a);

switch(a){
  case 0:
       printf("Introduzca el id del producto --> "); fflush(stdin); scanf("%s",&id);
       for(i=0;i<(*n);i++){
        if(strcmp((*vProducto)[i].id_prod,id)==0){
            puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
            printf("Datos del producto:\n");
             printf("Producto --> %s \n",(*vProducto)[i].desc_prod);
             printf("Precio del producto: %.2f euross\n",(*vProducto)[i].precio);
             printf("ID del producto --> %s \n",(*vProducto)[i].id_prod);
             printf("ID de la categoria --> %s\n",(*vProducto)[i].categ);
             printf("ID del gestor del producto --> %s\n",(*vProducto)[i].gest);
             printf("Quedan %d en stock\n",(*vProducto)[i].stock);
             printf("Dias maximo para la entrega --> %d\n",(*vProducto)[i].entrega);
             puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
             encontrado=1;//si encontrado esta en 1 es que se habrá encontrado el producto en la base de datos
       }}
             if(encontrado==0){printf("\nEl Id introducido no se encuentra en la base de datos\n");}
             encontrado=0;
             break;
  case 1:
    printf("Introduzca el nombre del producto --> ");
    fflush(stdin);
    gets(name);
      for(j=0;j<(*n);j++){
        if(strcmp((*vProducto)[j].desc_prod,name)==0){//Si ambas cadenas son iguales:
             puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
             printf("Datos del producto:\n");
             printf("Producto --> %s \n",(*vProducto)[j].desc_prod);
             printf("Precio del producto: %.2f euros\n",(*vProducto)[j].precio);
             printf("ID del producto --> %s \n",(*vProducto)[j].id_prod);
             printf("ID de la categoria --> %s\n",(*vProducto)[j].categ);
             printf("ID del gestor del producto --> %s\n",(*vProducto)[j].gest);
             printf("Quedan %d en stock\n",(*vProducto)[j].stock);
             printf("Dias maximo para la entrega --> %d\n",(*vProducto)[j].entrega);
             puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
             encontrado1=1;}
             }
             if(encontrado1==0){printf("\nEl nombre introducido no se encuentra en la base de datos\n");}
             encontrado1=0;
             break;}
             do{
             printf("Pulse 1 para buscar otro producto/Pulse 2 para salir de (buscar producto)-->  "); scanf("%d",&exit);
             }while(exit!=1&&exit!=2);

             }while(exit==1);
             }

//Cabecera:void add_producto(producto **vProducto,int *n);
//Precondicion: La estructura vProducto es de tipo producto y el entero n deben estar inicializados
//Postcondicion:Permite añadir un producto a la estructura
void add_producto(producto **vProducto,int *n){
    *vProducto=realloc((producto *)(*vProducto),((*n)+1)*sizeof(producto));
   fflush(stdin);

    printf("\nIntroduce los nuevos datos del producto:\n");
    puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
    printf("\nIntroduce el nombre del Producto --> "); scanf("%s",&(*vProducto)[*n].desc_prod); fflush(stdin);
    printf("\nIntroduce el precio del producto --> "); scanf("%.2f",&(*vProducto)[*n].precio);fflush(stdin);
    printf("\nIntroduce el ID del producto --> ");     scanf("%s",&(*vProducto)[*n].id_prod);fflush(stdin);
    printf("\nIntroduce el ID de la categoria --> ");     scanf("%s",&(*vProducto)[*n].categ);fflush(stdin);
    printf("\nIntroduce el ID del gestor del producto --> "); scanf("%s",&(*vProducto)[*n].gest);fflush(stdin);
    printf("\nIntroduce el n de productos en stock --> "); scanf("%d",&(*vProducto)[*n].stock);
    printf("\nIntroduce n de dias maximos para entrega --> "); scanf("%d",&(*vProducto)[*n].entrega);
    puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
    (*n)++;
    printf("Los datos se han guardado correctamente\n");
}

//Cabecera:void remove_producto(producto **vProducto,int *n)
//Precondicion: La estructura vProducto es de tipo producto y el entero n deben estar inicializados
//Postcondicicion: Permite eliminar un producto
void remove_producto(producto **vProducto,int *n){
int i,aux;
char remove[10];
printf("Introduce el ID del producto que desea eliminar --> "); scanf("%s",&remove);
for(i=0;i<(*n);i++){ //Buscamos el id del producto que tiene el ID introducido por usuario
    if(strcmp((*vProducto)[i].id_prod,remove)==0){
         aux=i;}
}
//Desplazamos todos los productos una posicion
for(i=aux;i+1<(*n);i++){
        strcpy((*vProducto)[i].id_prod,(*vProducto)[i+1].id_prod);
        strcpy((*vProducto)[i].desc_prod,(*vProducto)[i+1].desc_prod);
        strcpy((*vProducto)[i].categ,(*vProducto)[i+1].categ);
        strcpy((*vProducto)[i].gest,(*vProducto)[i+1].gest);
        (*vProducto)[i].stock=(*vProducto)[i+1].stock;
        (*vProducto)[i].entrega=(*vProducto)[i+1].entrega;
        (*vProducto)[i].precio=(*vProducto)[i+1].precio;}
        (*n)--;//Reajustamos n
        *vProducto=realloc((producto *)(*vProducto),((*n))*sizeof(producto));//Reajustamos la memoria del vector para que tenga uno menos

        }

//Cabecera:void modifica_producto(categoria **vCategoria,int *n)
//Precondicion:La estructura vProducto es de tipo producto y n es de tipo entero ambas deben estar inicalizadas
//Postcondicion:Permite modificar los datos de un producto
void modifica_producto(producto **vProducto,int *n){
int i,a,encontrado=0,new_stock,new_entrega,exit;
float new_price;
char id[10],new_id[10],new_desc[30],new_idcateg[10],new_idgest[10];
printf("Introduce el ID del producto  que desea modificar sus datos --> ");
fflush(stdin);
scanf("%s",id);
for(i=0;i<(*n);i++){
    if(strcmp((*vProducto)[i].id_prod,id)==0){
        encontrado=1;//si encontado=1 es porque se ha encontrado el dato en la estructura
        do{
        printf("Indique la accion que desea realizar:\n");//Preguntamos que cambio desea realizar el usuario
        puts("1 Cambiar ID del producto");
        puts("2 Cambiar La descripcion del producto");
        puts("3 Cambiar el ID de la categoria que pertenece");
        puts("4 Cambiar el ID del gestor del producto");
        puts("5 Cambiar el Stockage del producto");
        puts("6 Cambiar el compromiso de entrega");
        puts("7 Cambiar el precio del producto");
        do{
        printf("--> "); scanf("%d",&a);
        }while(a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6&&a!=7);
        puts("\n");
        //Creamos un switch para modificar el dato que haya escogido el usuario
        switch(a){
        case 1:
            printf("Introduce el nuevo ID del producto --> ");
            fflush(stdin);
            scanf("%s",&new_id);
            strcpy((*vProducto)[i].id_prod,new_id);//Se copiara el nuevo id en la poscion de memoria i de la estructura Vcategoria
            puts("El dato ha sido  modificado");
            break;
        case 2:
            printf("Introduce la nueva descripcion del producto --> ");
            fflush(stdin);
            gets(new_desc);
            strcpy((*vProducto)[i].desc_prod,new_desc);//Se copiara la nueva descripcion de categoria en la poscion de memoria i de la estructura Vcategoria
            puts("El dato ha sido  modificado");
            break;
        case 3:
            printf("Introduce el nuevo ID de la categoria a la que pertenece --> ");
            fflush(stdin);
            scanf("%s",&new_idcateg);
            strcpy((*vProducto)[i].categ,new_idcateg);
            puts("El dato ha sido  modificado");
            break;
        case 4:
            printf("Introduce el nuevo ID del gestor del producto --> ");
            fflush(stdin);
            scanf("%s",&new_idgest);
            strcpy((*vProducto)[i].gest,new_idgest);
            puts("El dato ha sido  modificado");
            break;
        case 5:
            printf("Introduce el nuevo stockage (articulos) --> ");
            scanf("%d",&new_stock);
           ((*vProducto)[i].stock)=new_stock;
            puts("El dato ha sido  modificado");
            break;
        case 6:
            printf("Introduce el numero de dias maximos para la entrega --> ");
            scanf("%d",&new_entrega);
           ((*vProducto)[i].entrega)=new_entrega;
           puts("El dato ha sido  modificado");
           break;
        case 7:
            printf("Introduce el nuevo precio del producto  --> ");
            scanf("%.2f",&new_price);
           ((*vProducto)[i].precio)=new_price;
           puts("El dato ha sido  modificado");
           break;}
         do{
         printf("\nPulse 1 para realizar otro cambio en el producto/Pulse 2 para salir del menu (modificar producto)--> ");
         scanf("%d",&exit);
         }while(exit!=1&&exit!=2);

        }while(exit==1);
            }



     }
     if(encontrado==0){puts("El ID introducido no se ha encontrado en la Base de datos");}

      else{puts("Los datos han sido modificados correctamente");}

}

////////////////////////////////////////////////FIN FUNCIONES DE PRODUCTOS ADMIN Y CLIENTES/////////////////////////////////////



////////////////////////////////FUNCIONES PRODUCTOS PROVEEDORES///////////////////////////////////////////////

//Cabecera: void listar_producto_prov(product **vProducto,int *n,char *id)
//Precondicion: La estructura vProducto es de tipo producto , el id y n son de tipo entero ,todas las variables deeben estar inicializadas
//Postcondicion:Hace una lista con los productos que coinciden con el id  del gestor
void listar_producto_prov(producto **vProducto,int *n,char *id){//(CORRECTO)
int i,encontradoProv=0;
puts("A continuacion se mostraran todos sus productos:\n");
puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
for(i=0;i<(*n);i++){
    if(strcmp((*vProducto)[i].gest,id)==0){
    printf("Descripcion del producto --> %s \n",(*vProducto)[i].desc_prod);
    printf("Precio del producto: %.2f euros\n",(*vProducto)[i].precio);
    printf("ID del producto --> %s \n",(*vProducto)[i].id_prod);
    printf("ID de la categoria --> %s\n",(*vProducto)[i].categ);
    printf("ID del gestor del producto --> %s\n",(*vProducto)[i].gest);
    printf("Quedan %d en stock\n",(*vProducto)[i].stock);
    printf("Dias maximo para la entrega --> %d\n",(*vProducto)[i].entrega);

puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
   encontradoProv=1;
   } }


if(encontradoProv==0){puts("\nActualmente no posee ningun producto en ESIZON");}



}

//Cabecera:void add_producto_prov(product **vProducto,int *n,char *id)
//Precondicion:La estructura vProducto es de tipo producto , el id y n son de tipo entero ,todas las variables deeben estar inicializadas
//Postcondicion: Añade un producto con el id del del gestor (Proveedor)
void add_producto_prov(producto **vProducto,int *n,char *id){
*vProducto=realloc((producto *)(*vProducto),((*n)+1)*sizeof(producto));
   fflush(stdin);

    printf("\nIntroduce los nuevos datos del producto:\n");
    puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
    printf("\nIntroduce el nombre del Producto --> "); scanf("%s",&(*vProducto)[*n].desc_prod); fflush(stdin);
    printf("\nIntroduce el precio del producto --> "); scanf("%.2f",&(*vProducto)[*n].precio);fflush(stdin);
    printf("\nIntroduce el ID del producto --> ");     scanf("%s",&(*vProducto)[*n].id_prod);fflush(stdin);
    printf("\nIntroduce el ID de la categoria --> ");     scanf("%s",&(*vProducto)[*n].categ);fflush(stdin);
    strcpy((*vProducto)[*n].gest,id);//Ponemos como id del gestor el id del gestor que esta añadiendo el producto
    printf("\nIntroduce el n de productos en stock --> "); scanf("%d",&(*vProducto)[*n].stock);
    printf("\nIntroduce n de dias maximos para entrega --> "); scanf("%d",&(*vProducto)[*n].entrega);
    puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
    (*n)++;
    printf("Los datos se han guardado correctamente\n");



}


//Cabecera: void remove_producto_prov(producto **vProducto,int *n,char *id)
//Precondicion: La estructura vProducto es de tipo producto , el id y n son de tipo entero ,todas las variables deeben estar inicializadas
//Postcondicion: Permite eliminar un producto, si este tiene el mismo identificador de gestor que el id
void remove_producto_prov(producto **vProducto,int *n,char *id){//CORRECTO
int i,aux,encontrado=0;
char remove[10];
printf("Introduce el ID del producto que desea eliminar --> "); scanf("%s",&remove);

for(i=0;i<(*n);i++){ //Buscamos el id del producto que tiene el ID introducido por usuario
    if(strcmp((*vProducto)[i].id_prod,remove)==0){
         aux=i;
         encontrado=1;}
}
if(encontrado==1){//Si el producto se encuentra en la base de datos
//Desplazamos todos los productos una posicion
if(strcmp((*vProducto)[aux].gest,id)==0){//Si el id del gestor coincide con el identificador del gestor del producto se eliminara el producto
for(i=aux;i+1<(*n);i++){
        strcpy((*vProducto)[i].id_prod,(*vProducto)[i+1].id_prod);
        strcpy((*vProducto)[i].desc_prod,(*vProducto)[i+1].desc_prod);
        strcpy((*vProducto)[i].categ,(*vProducto)[i+1].categ);
        strcpy((*vProducto)[i].gest,(*vProducto)[i+1].gest);
        (*vProducto)[i].stock=(*vProducto)[i+1].stock;
        (*vProducto)[i].entrega=(*vProducto)[i+1].entrega;
        (*vProducto)[i].precio=(*vProducto)[i+1].precio;}
        (*n)--;//Reajustamos n
        *vProducto=realloc((producto *)(*vProducto),((*n))*sizeof(producto));

        puts("El producto se ha eliminado correctamente\n");
        }
else{printf("No tiene permiso para modificar este producto\n");}

        }//Reajustamos la memoria del vector para que tenga uno menos
else{printf("El id introducido no se encuentra en la base de datos\n");}


}

//Cabecera:void busqueda_producto_prov(producto **vProducto,int *n,char *id)
//Precondicion: La estructura vProducto es de tipo producto , el id y n son de tipo entero ,todas las variables deeben estar inicializadas
//Postcondicion:Permite buscar los productos cuyo id_gest que coinciden con el id del gestor del producto que esta accediendo
void busqueda_producto_prov(producto **vProducto,int *n,char *id){//CORRECTO
int i,a,j,encont=0,exit,encontrado1=0;
char name[30],id_prod[10];
do{
do{
printf("\nPulse 1 para realizar la busqueda mediante ID del producto\n");
printf("Pulse 2 para realizar la busqueda mediante el nombre del producto\n");
printf("-->");scanf("%d",&a);
}while(a!=1&&a!=2);
switch(a){
  case 1:
       printf("Introduzca el id del producto --> "); fflush(stdin); scanf("%s",&id_prod);
       for(i=0;i<(*n);i++){

        if(strcmp((*vProducto)[i].id_prod,id_prod)==0){//si encontramos el producto en la base de datos
            encont=1;//si encont =1 se habra encontrado en la base de datos
            //2ª Condicion el id del gestor del producto debe coincidir con el   id del gestor que accede (id)
          if(strcmp((*vProducto)[i].gest,id)==0){
            encont=2;//si encont =2 se habra encontrado en la base de datos y ademas coincidira con el id del gestor
            puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
            printf("Datos del producto:\n");
             printf("Producto --> %s \n",(*vProducto)[i].desc_prod);
             printf("Precio del producto: %.2f euros\n",(*vProducto)[i].precio);
             printf("ID del producto --> %s \n",(*vProducto)[i].id_prod);
             printf("ID de la categoria --> %s\n",(*vProducto)[i].categ);
             printf("ID del gestor del producto --> %s\n",(*vProducto)[i].gest);
             printf("Quedan %d en stock\n",(*vProducto)[i].stock);
             printf("Dias maximo para la entrega --> %d\n",(*vProducto)[i].entrega);
             puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");

       }
       }

    }
    if(encont==0){printf("\nEl id introducido no se encuentra en la base de datos\n");}
    if(encont==1){printf("\nNo tiene permiso para mostrar este producto(Su id de gestor no coincide)\n");}
    //reiniciamos encont
    encont=0;
             break;
  case 2:
     printf("Introduzca el nombre del producto --> "); fflush(stdin); scanf("%s",&name);
       for(i=0;i<(*n);i++){

        if(strcmp((*vProducto)[i].desc_prod,name)==0){//si encontramos el producto en la base de datos
            encont=1;//si encont =1 se habra encontrado en la base de datos
            //2ª Condicion el id del gestor del producto debe coincidir con el   id del gestor que accede (id)
          if(strcmp((*vProducto)[i].gest,id)==0){
            encont=2;//si encont =2 se habra encontrado en la base de datos y ademas coincidira con el id del gestor
            puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
            printf("Datos del producto:\n");
             printf("Producto --> %s \n",(*vProducto)[i].desc_prod);
             printf("Precio del producto: %.2f euros\n",(*vProducto)[i].precio);
             printf("ID del producto --> %s \n",(*vProducto)[i].id_prod);
             printf("ID de la categoria --> %s\n",(*vProducto)[i].categ);
             printf("ID del gestor del producto --> %s\n",(*vProducto)[i].gest);
             printf("Quedan %d en stock\n",(*vProducto)[i].stock);
             printf("Dias maximo para la entrega --> %d\n",(*vProducto)[i].entrega);
             puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");

       }
       }

    }
    if(encont==0){printf("\nEl nombre introducido no se encuentra en la base de datos\n");}
    if(encont==1){printf("\nNo tiene permiso para mostrar este producto(Su id de gestor no coincide)\n");}
    //reiniciamos encont
    encont=0;
             break;}
             do{
             printf("\n\nPulse 1 para buscar otro producto/Pulse 2 para salir de (buscar producto)-->  "); scanf("%d",&exit);
             }while(exit!=1&&exit!=2);

             }while(exit==1);
             }


//Cabecera: void  modifica_producto_prov(producto **vProducto,int *n,char *id)
//Postcondicion: La estructura vProducto es de tipo producto , el id y n son de tipo entero ,todas las variables deeben estar inicializadas
//Precondicion: Permite modificar un producto del proveedor que accede
void  modifica_producto_prov(producto **vProducto,int *n,char *id_gest){//CORRECTO

int i,a,encontrado=0,new_stock,new_entrega,exit;
float new_price;
char id[10],new_id[10],new_desc[30],new_idcateg[10],new_idgest[10];
printf("Introduce el ID del producto  que desea modificar sus datos --> ");
fflush(stdin);
scanf("%s",id);
for(i=0;i<(*n);i++){
    if((strcmp((*vProducto)[i].id_prod,id)==0)&&(strcmp((*vProducto)[i].gest,id_gest)==0)){
        encontrado=1;//si encontado=1 es porque se ha encontrado el dato en la estructura y ademas es igual al id del gestor del producto
        do{
        printf("Indique la accion que desea realizar:\n");//Preguntamos que cambio desea realizar el usuario
        puts("1 Cambiar ID del producto");
        puts("2 Cambiar La descripcion del producto");
        puts("3 Cambiar el ID de la categoria que pertenece");
        puts("4 Cambiar el ID del gestor del producto");
        puts("5 Cambiar el Stockage del producto");
        puts("6 Cambiar el compromiso de entrega");
        puts("7 Cambiar el precio del producto");
        do{
        printf("--> "); scanf("%d",&a);
        }while(a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6&&a!=7);
        puts("\n");
        //Creamos un switch para modificar el dato que haya escogido el usuario
        switch(a){
        case 1:
            printf("Introduce el nuevo ID del producto --> ");
            fflush(stdin);
            scanf("%s",&new_id);
            strcpy((*vProducto)[i].id_prod,new_id);//Se copiara el nuevo id en la poscion de memoria i de la estructura Vcategoria
            puts("El dato ha sido  modificado");
            break;
        case 2:
            printf("Introduce la nueva descripcion del producto --> ");
            fflush(stdin);
            gets(new_desc);
            strcpy((*vProducto)[i].desc_prod,new_desc);//Se copiara la nueva descripcion de categoria en la poscion de memoria i de la estructura Vcategoria
            puts("El dato ha sido  modificado");
            break;
        case 3:
            printf("Introduce el nuevo ID de la categoria a la que pertenece --> ");
            fflush(stdin);
            scanf("%s",&new_idcateg);
            strcpy((*vProducto)[i].categ,new_idcateg);
            puts("El dato ha sido  modificado");
            break;
        case 4:
            printf("Introduce el nuevo ID del gestor del producto --> ");
            fflush(stdin);
            scanf("%s",&new_idgest);
            strcpy((*vProducto)[i].gest,new_idgest);
            puts("El dato ha sido  modificado");
            break;
        case 5:
            printf("Introduce el nuevo stockage (articulos) --> ");
            scanf("%d",&new_stock);
           ((*vProducto)[i].stock)=new_stock;
            puts("El dato ha sido  modificado");
            break;
        case 6:
            printf("Introduce el numero de dias maximos para la entrega --> ");
            scanf("%d",&new_entrega);
           ((*vProducto)[i].entrega)=new_entrega;
           puts("El dato ha sido  modificado");
           break;
        case 7:
            printf("Introduce el nuevo precio del producto (entero) --> ");
            scanf("%.2f",&new_price);
           ((*vProducto)[i].precio)=new_price;
           puts("El dato ha sido  modificado");
           break;}
         do{
         printf("\nPulse 1 para realizar otro cambio en el producto/Pulse 2 para salir del menu (modificar producto)--> ");
         scanf("%d",&exit);
         }while(exit!=1&&exit!=2);

        }while(exit==1);
            }



     }
     if(encontrado==0){puts("El ID introducido no se ha encontrado en la Base de datos o no tiene permiso para modificar el producto(no coincide con su id de gestor)");}

      else{puts("Los datos han sido modificados correctamente");}

}

//Cabecera: void listar_categoria_prod_prov(categoria **vCategoria,producto **vProducto,int *nc,int *np,ichar *id)
//Precondicion: vCategoria es una etsructura de tipo categoria,vProducto es una estrucutra de tipo producto
//              nc y np son de tipo entero y el id es una array. todas las variables deben estar inicializadas
//Postcondicion: Permite hacer una lista por categorias de aquellos prductos que coinciden con el id del proveedor
void listar_categoria_prod_prov(categoria **vCategoria,producto **vProducto,int *nc,int *np,char *id){
int i,j,encontrado=0;

puts("A continuacion se mostrara una lista con sus  productos por categorias:\n");
for(i=0;i<(*nc);i++){//Recorremos todas las categorias que hay (solo su descripcion)
     puts("/////////////////////////////////////////////////////////////////////");
     printf("\n\n<<< Categoria: %s >>>\n",(*vCategoria)[i].des_categ);
     puts("-----------------------------------------------------------------\n");
     for(j=0;j<(*np);j++){//Recorremos todos los productos
          if((strcmp((*vCategoria)[i].id_categ,(*vProducto)[j].categ)==0)&&(strcmp(id,(*vProducto)[j].gest)==0)){//si el id de la categoria del producto y el id de la categoria coinciden, y ademas el id del gestor del prodcuto coincide con el id del gestor que accede:
           encontrado=1;
           printf("Descripcion del producto --> %s \n",(*vProducto)[j].desc_prod);
           printf("Precio del producto: %.2f euros\n",(*vProducto)[j].precio);
           printf("ID del producto --> %s \n",(*vProducto)[j].id_prod);
           printf("ID de la categoria --> %s\n",(*vProducto)[j].categ);
           printf("ID del gestor del producto(Su ID) --> %s\n",(*vProducto)[j].gest);
           printf("Quedan %d en stock\n",(*vProducto)[j].stock);
           printf("Dias maximo para la entrega --> %d\n",(*vProducto)[j].entrega);
           puts("-----------------------------------------------------------------\n");
          }
     }
}
if(encontrado==0){printf("No existe ningun producto con su id de gestor\n"); }
}



//////////////////////////////FIN FUNCIONES PRODUCTOS PROVEEDORES//////////////////////////////////////////



////////////////////////////////FUNCIONES DE MENU///////////////////////////////
void  MenuAdminProductos(){
int a,exit;
puts("\n\n<<<Bienvenido al menu de Productos(administrador)>>>\n");
printf("Cargando datos del fichero Productos.txt....\n");
cargarProductos(&vProducto,&nProductos);
do{
printf("\nElija una opcion:\n");
puts("1 Listar productos");
puts("2 Anadir producto");
puts("3 Eliminar producto");
puts("4 Buscar producto");
puts("5 Modificar producto");
fflush(stdin);
printf("\n--> ");scanf("%d",&a);
switch(a){
case 1: listar_producto(&vProducto,&nProductos);break;
case 2: add_producto(&vProducto,&nProductos);break;
case 3: remove_producto(&vProducto,&nProductos);break;
case 4: busqueda_producto(&vProducto,&nProductos);break;
case 5: modifica_producto(&vProducto,&nProductos);break;}
do{
printf("\n\nPulse 1 para realizar otra operacion/Pulse 2 para salir de (Menu administrador Productos) --> ");scanf("%d",&exit);
}while(exit!=1&&exit!=2);
}while(exit==1);
imprimeProductos(vProducto,nProductos);//volvemos a guardar los datos en el fichero
}

void MenuClientProductos(){
puts("\n\n<<<Bienvenido al menu de Productos(Cliente)>>>\n");
int a,exit,opc;
printf("Cargando datos del fichero Productos.txt....\n");
cargarProductos(&vProducto,&nProductos);
do{
printf("Elija una opcion:\n");
puts("1 Consulta de productos por categoria");
puts("2 Consulta de productos por nombre");
printf("\n--> ");scanf("%d",&a);
switch(a){

case 1:
    do{
    printf("Como desea realizar la consulta?\n");
    puts("1 Hacer listado por categorias de todos los productos de ESIZON");
    puts("2 Buscar categoria y mostrar productos");
    printf("--> ");scanf("%d",&opc);
    }while(opc!=1&&opc!=2);
    switch(opc){
    case 1://CORRECTO Y COMPROBADO
        cargarCategorias(&vCategoria,&nCategorias);
        listar_categoria_prod(&vCategoria,&vProducto,&nCategorias,&nProductos);
        break;
    case 2:
        cargarCategorias(&vCategoria,&nCategorias);
        busc_prod_categ(&vCategoria,&vProducto,&nProductos,&nCategorias);//DA UN ERROR
        break;
    }break;

case 2:  busqueda_producto(&vProducto,&nProductos);break;

}


do{
printf("\n\nPulse 1 para realizar otra operacion/Pulse 2 para salir de (Menu Productos cliente) --> ");scanf("%d",&exit);
}while(exit!=1&&exit!=2);

}while(exit==1);
//No es necesario guardar los datos en el fichero porque cliente no tiene acceso a ninguna modificacion
}


void MenuProvProductos(char *id){//EL PROVEEDOR SOLO PODRA ACCEDER AQUELLOS PRODUCTOS QUE COINCIDAN CON SU ID
int a,exit;
puts("\n\n<<<Bienvenido al menu de Productos(Proveedores)>>>\n");;
printf("Cargando datos del fichero Productos.txt....\n");

cargarProductos(&vProducto,&nProductos);
do{
printf("\nElija una opcion:\n");
puts("1 Listar sus productos");
puts("2 Anadir producto");
puts("3 Eliminar producto");
puts("4 Buscar en sus productos");
puts("5 Modificar producto");
puts("6 Listar sus productos por categoria");
fflush(stdin);
printf("\n--> ");scanf("%d",&a);
switch(a){
case 1: listar_producto_prov(&vProducto,&nProductos,id);break;
case 2: add_producto_prov(&vProducto,&nProductos,id);break;
case 3: remove_producto_prov(&vProducto,&nProductos,id);break;
case 4: busqueda_producto_prov(&vProducto,&nProductos,id);break;
case 5: modifica_producto_prov(&vProducto,&nProductos,id);break;
case 6:
        cargarCategorias(&vCategoria,&nCategorias);//cargamos la estrucutura categoria  que nos hara falta para la siguientew funcion
        listar_categoria_prod_prov(&vCategoria,&vProducto,&nCategorias,&nProductos,id);

          break;


}
do{
printf("\n\nPulse 1 para realizar otra operacion/Pulse 2 para salir de (Menu administrador Productos) --> ");scanf("%d",&exit);
}while(exit!=1&&exit!=2);
}while(exit==1);
imprimeProductos(vProducto,nProductos);//volvemos a guardar los datos en el fichero

}








/////////////////////////////////////////////////////////////////////////////////

/*LA SIGUIENTE FUNCION (MAIN) SIRVE PARA COMPROBAR QUE TODOS LOS MENUS FUNCIONAN CORRECTAMENTE
  INDEPENDIENTEMENTE DEL PROGRAMA PRONCIPAL
  SI EXISTE ALGUN FALLO EN EL PROGRAMA PRINCIPAL SE PODRA COMPROBAR EL CORRECTO FUNCIONAMIENTO
  DE LAS FUNCIONES PROGRAMADAS POR  (JOSÉ MANUEL TROYA) , UTILIZANDO LA FUNCION MAIN.*/

/*int main(){
int op;
printf("\nIndique el tipo de usuario:\n");
puts("1 Administrador");
puts("2 Cliente");
//puts("3 Proveedor\n");(PENDIENTE)
do{
    printf("--> ");
    scanf("%d",&op);
}while(op!=1&&op!=2&&op!=3);
switch(op){
case 1: MenuAdminProductos();break;
case 2: MenuClientProductos();break;
//case 3: MenuProvProductos();break;(PENDIENTE)
}*/





//}



