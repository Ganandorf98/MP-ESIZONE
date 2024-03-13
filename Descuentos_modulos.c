//Archivo .c Programado por --> José Manuel Troya Valero

#include"desc+dclient.h"


//Cabecera:void listar_descuento(descuento **vDescuento,int *n
//Precondicion:La estructura vDescuento es de tipo descuento y n es de tipo entero ambas deben estar inicializadas
//Postcondicion: Permite hacer un lista de todos los descuentos que tiene ESIZON

void listar_descuento(descuento **vDescuento,int *n){
int i;
puts("A continuacion se mostraran todos los descuentos de ESIZON:\n\n");
puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
for(i=0;i<(*n);i++){
    printf("Descripcion --> %s \n",(*vDescuento)[i].desc_desc);
    printf("Identificador --> %s\n",(*vDescuento)[i].id_cod);
    printf("Tipo --> %s\n",(*vDescuento)[i].tipo);
    printf("Estado --> %s\n",(*vDescuento)[i].estado);
    printf("Importe del descuento --> %.2f euros\n",(*vDescuento)[i].importe);
    printf("Aplicabilidad --> %s\n",(*vDescuento)[i].aplic);
puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
    }

}


//Cabecera:void buscar_descuento(descuento **vDescuento,int *n)
//Precondicion:La estructura vDescuento es de tipo descuento y n es de tipo entero ambas deben estar inicalizadas
//Postcondicion:Permite buscar un decuento mediante su descripcion o su id
void busqueda_descuento(descuento **vDescuento,int *n){
int i,a,j,encontrado=0,encontrado1=0,exit;
char name[30],id[20];
do{
do{
printf("\n1 Realizar busqueda mediante Identificador del descuento o codigo promocional\n");
printf("2 Realizar busqueda mediante Descripcion del del descuento o codigo promocional\n");
printf("--> ");scanf("%d",&a);
}while(a!=1&&a!=2);
switch(a){
  case 1:
       printf("Introduzca el ID del descuento o codigo promocional --> "); fflush(stdin); scanf("%s",&id);
       for(i=0;i<(*n);i++){
        if(strcmp((*vDescuento)[i].id_cod,id)==0){
            puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
            printf("Descripcion --> %s \n",(*vDescuento)[i].desc_desc);
            printf("Identificador --> %s\n",(*vDescuento)[i].id_cod);
            printf("Tipo --> %s\n",(*vDescuento)[i].tipo);
            printf("Estado --> %s\n",(*vDescuento)[i].estado);
            printf("Importe del descuento --> %.2f euros\n",(*vDescuento)[i].importe);
            printf("Aplicabilidad --> %s\n",(*vDescuento)[i].aplic);
            puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
             encontrado=1;//si encontrado esta en 1 es que se habrá encontrado el producto en la base de datos
       }}
             if(encontrado==0){printf("\nEl Id introducido no se encuentra en la base de datos\n");}
             break;
  case 2:
  printf("Introduzca la descripcion del cheque regalo o codigo promocional --> "); fflush(stdin); scanf("%s",&name);
       for(i=0;i<(*n);i++){
        if(strcmp((*vDescuento)[i].desc_desc,name)==0){
            puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
            printf("Descripcion --> %s \n",(*vDescuento)[i].desc_desc);
            printf("Identificador --> %s\n",(*vDescuento)[i].id_cod);
            printf("Tipo --> %s\n",(*vDescuento)[i].tipo);
            printf("Estado --> %s\n",(*vDescuento)[i].estado);
            printf("Importe del descuento --> %.2f euros\n",(*vDescuento)[i].importe);
            printf("Aplicabilidad --> %s\n",(*vDescuento)[i].aplic);
            puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
             encontrado1=1;//si encontrado esta en 1 es que se habrá encontrado el producto en la base de datos
       }}
             if(encontrado1==0){printf("\nLa descripcion  introducida no se encuentra en la base de datos\n");}
             break;
             }
             do{
             printf("\nPulse 1 para buscar otro producto/Pulse 2 para salir de (buscar descuentos) -->  "); scanf("%d",&exit);
             }while(exit!=1&&exit!=2);

             }while(exit==1);
             }


/////////////////////////////PENDDEINTE/////////////////////////////
//Cabecera:  void modifica_descuento(descuento **vDescuento,int *n)
//Precondicion:La estructura vDescuento es de tipo descuento n es de tipo entero y todad las variables deben estar inicializadas
//Postcondicion: Permite modificar un descuento
/*MODIFICAREMOS:
-EL ID DEL DESCUENTO -DESCRIPCION DEL DESCUENTO(TAMBIEN SE CAMBIARA EN ESTRUCTURA DESCLIENT) -TIPO DE DESCUENTO
-ESTADO(TAMBIEN SE CAMBIARA EN ESTRUCTURA DESCLIENT) -EL IMPORTE -LA APLICABILIDAD*/
/*POR LO TANTO SI CAMBIAMOS EL ESTADO DE UN DESCUENTO REPERCUTIRÁ EN TODOS LOS CLIENTES QUE POSEAN DICHO DESCUENTO, DEL MISMO MODO
CON LA DESCRIPCIÓN DEL DESCUENTO */
void modifica_descuento(descuento **vDescuento,int *n){//PENDIENTE
int i,encontrado=0,a,b,c,d,exit;
char id[20],new_id[20],new_desc[30];
char codpro[10]="codpro" ,  cheqreg[10]="cheqreg" , todos[10]="todos",esizon[10]="esizon",activo[20]="activo",noactivo[20]="no activo";
float new_impor;
printf("Introduce el Id del descuento que desea modificar --> ");
fflush(stdin);
gets(id);

for(i=0;i<(*n);i++){
    if(strcmp((*vDescuento)[i].id_cod,id)==0){
        encontrado=1;// Si encotrado=1 el id estará en la base de datos
        do{
            printf("Indique que modificacion desea realiar:\n");
            puts("1 Cambiar ID del descuento ");
            puts("2 Cambiar la descripcion del descuento");
            puts("3 Cambiar el tipo de descuento");
            puts("4 Cambiar el importe del descuento");
            puts("5 Cambiar la aplicabilidad del descuento");
            puts("6 Cambiar el estado del descuento");
			do{
                printf("--> "); scanf("%d",&a);

            }while(a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6);

            puts("\n");

            //Switch con las opciones anteriores.

switch(a)
{
       case 1://Se cambiara el id del producto en la estrucutra descuentos
           printf("\nIntroduce el nuevo ID del descuento --> "); fflush(stdin);
           gets(new_id);
               strcpy((*vDescuento)[i].id_cod,new_id);//Guardamos el nuevo id en la estructura
               printf("\nLa modificacion se a realizado correctamente\n");
			   break;
       case 2:
	       printf("\nIntroduce la bueca descripcion del descuento --> "); fflush(stdin);
                gets(new_desc);
               strcpy((*vDescuento)[i].desc_desc,new_desc);
			  printf("\nLa modificacion se a realizado correctamente\n");
			  break;
       case 3:
         puts("Indique una opcion para cambiar el tipo de descuento:\n");
	      printf("Pulse 1 para codigo promocional(codpro)\n");
	      printf("Pulse 2 para cheque regalo(cheqreg)\n");
		  do{
		  printf("--> "); scanf("%d",&b);
 	        }while(b!=1&&b!=2);
		  switch(b){
		  	case 1:  strcpy((*vDescuento)[i].tipo,codpro); break;
            case 2:  strcpy((*vDescuento)[i].tipo,cheqreg); break;}
            printf("\nLa modificacion se a realizado correctamente\n");
	          break;
       case 4:  printf("\nIntroduce el nuevo importe del descuento --> "); fflush(stdin);
                scanf("%f",&new_impor);
               (*vDescuento)[i].importe=new_impor;
			  printf("\nLa modificacion se a realizado correctamente\n");
			  break;
       case 5:
	      puts("Indique una opcion para cambiar la aplicabilidad del descuento:\n");
	      printf("Pulse 1 para aplicabilidad en todos los productos\n");
	      printf("Pulse 2 para aplicabilidad en solo  productos ESIZON\n");
		  do{
		  printf("--> "); scanf("%d",&c);
	        }while(c!=1&&c!=2);
		  switch(c){
		  	case 1:  strcpy((*vDescuento)[i].aplic,todos); break;
            case 2:  strcpy((*vDescuento)[i].aplic,esizon); break;}
			printf("\nLa modificacion se a realizado correctamente\n");
			 break;


      case 6:
        puts("Indique una opcion para cambiar el del descuento:\n");
	      printf("Pulse 1 para estado activo\n");
	      printf("Pulse 2 para estado no activo\n");
		  do{
		  printf("--> "); scanf("%d",&d);
	        }while(d!=1&&d!=2);
		  switch(d){
		  	case 1:  strcpy((*vDescuento)[i].estado,activo); break;
            case 2:  strcpy((*vDescuento)[i].estado,noactivo); break;}
			printf("\nLa modificacion se a realizado correctamente\n");
			 break;

}
do{

printf("\nPulse 1 para  realizar otra modificacion en el descuento %s  \n",(*vDescuento)[i].desc_desc);
printf("Pulse 2 para salir del menu (modificar descuentos)\n");
printf("--> "); scanf("%d",&exit);
}while(exit!=1&&exit!=2);

}while(exit==1);

}

       }

  if(encontrado==0){puts("El ID introducido no se ha encontrado en la Base de datos");}

      else{puts("Los datos han sido modificados correctamente");}


}


//Cabecera:   void add_descuento(descuento**vDescuento,desclient **vDesclient,int *nd ,int *nd);
//Precondicion:todas las estrucuturas y enteros deben estar inicalizados
//Postcondicion:permite añadir un  nuevo descuento (Al añadirse tambien se añadira a todos los clientes)
void add_descuento(descuento **vDescuento,desclient **vDesclient,cliente **vClientes,int *nd ,int *ndc,int *nc){
char  activo[10]="activo", noactivo[12]="no activo",todos[10]="todos",esizon[10]="esizon", codpro[10]="codpro",cheqreg[10]="cheqreg";
char id_client[10],fecha[25],fechacad[25]="01012021",active[10]="activo";
int a,b,c,index,i;
float importe;
//PARTE 1: Vamos añadir el nuevo descuento a la estructura descuentos
*vDescuento=realloc((descuento *)(*vDescuento),((*nd)+1)*sizeof(descuento));
fflush(stdin);
printf("Introduce los nuevos datos del descuento:\n");
puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
printf("\nIntroduce el ID del desuento -->  "); scanf("%s",&(*vDescuento)[*nd].id_cod); fflush(stdin);//se pasara a la estructura desclient
printf("\nIntroduce la descripcion  del desuento -->  "); scanf("%s",&(*vDescuento)[*nd].desc_desc); fflush(stdin);

//El estado se indicara mediante un pequeño menu, de este modo evitaremos errores a la hora de introducir los datos
printf("\nIndique el estado del descuento:\n");
puts("1 Activo");
puts("2 no activo");
do{
printf("--> "); scanf("%d",&a);
}while(a!=1&&a!=2);
switch(a){
case 1: strcpy((*vDescuento)[*nd].estado,activo);break;
case 2: strcpy((*vDescuento)[*nd].estado,noactivo);break;}

//La aplicabilidad se indicara mediante un pequeño menu, de este modo evitaremos errores a la hora de introducir los datos
printf("\nIndique la aplicabilidad del descuento:\n");
puts("1 aplicable en todos los prouctos");
puts("2 aplicable en solo los productos esizon");
do{
printf("--> "); scanf("%d",&b);
}while(b!=1&&b!=2);
switch(b){
case 1: strcpy((*vDescuento)[*nd].aplic,todos);break;
case 2: strcpy((*vDescuento)[*nd].aplic,esizon);break;}

//El tipo se indicara mediante un pequeño menu, de este modo evitaremos errores a la hora de introducir los datos
printf("\nIndique el tipo del descuento:\n");
puts("1 Codigo promocional(codpro)");
puts("2 Cheque regalo(cheqreg)");
do{
printf("--> "); scanf("%d",&c);
}while(b!=1&&b!=2);
switch(c){
case 1: strcpy((*vDescuento)[*nd].tipo,codpro);break;
case 2: strcpy((*vDescuento)[*nd].tipo,cheqreg);break;}
printf("\nIntroduce el importe del descuento --> "); scanf("%f",&importe);
((*vDescuento)[*nd].importe)=importe;

puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
index=(*nd);//index tendra el valor de  la posicion de memoria dentro del vector que posee el descuento que hemos añadido
(*nd)++;//aumentamos el numero de datos en la estructura de descuentos
puts("Los datos se han guardado correctamente");


//PARTE 2 ASIGNAR EL NUEVO DESCUENTO A TODOS LOS CLIENTES
puts("<<El nuevo descuento sera asignado a todos los clientes dados de alta en esizon>>\n");
for(i=0;i<(*nc);i++){
    //almacenamos cada id de cada cliente en id_client
    strcpy(id_client,(*vClientes)[i].id);

   //Antes de almacenar en la estructura desclient necesitamos aumentar su memoria
   *vDesclient=realloc((desclient *)(*vDesclient),((*ndc)+1)*sizeof(desclient));

    //Asignamos el nuevo descuento a todos los clientes(en la estructura desclient)
    strcpy((*vDesclient)[*ndc].id_client,id_client);//Añadimos el id del cliente a la estructura desclient
    //printf("id\n");
    strcpy((*vDesclient)[*ndc].id_cod,(*vDescuento)[index].id_cod);//Añadimos el id del descuento

    //Para la fecha de asignancion llamaremos a una funcion que calcule la fecha de hoy y la introduzca en un array
    calcula_fecha(fecha);

    strcpy((*vDesclient)[*ndc].fech_asig,fecha);//Añadimos la fecha de asignaciona a la estructura desclient

    strcpy((*vDesclient)[*ndc].fech_cad,fechacad);//consideramos que todos los descuentos tendran validez hasta 1 de enero de 2021
    strcpy((*vDesclient)[*ndc].estado,active);//Añadimos el estado activo a la estructura desclient

    (*ndc)++;}

    puts("El nuevo descuento ha sido asignado a todos los clientes de ESIZON");}

//Cabecera: void calcula_fecha(char *fech)
//Precondicion: fech es un array
//Postcondicion: La funcion calcula la fecha y la introduce en el array fech
void calcula_fecha(char *fech){

time_t tiempo = time(NULL);//variables donde guardo el valor de la funcion time.
    struct tm *tlocal = localtime(&tiempo); //estructura donde obtengo el tiempo
    strftime(fech,25,"%d%m%Y",tlocal); //formato para guardar la fecha obtenido en *tlocal como dd/mm/yyyy

    //printf("La fecha de hoy es : %s\n",fech);


}

//cabecera:void remove_descuento(descuento **vDescuento,int *n);
//Precondicion:La estructura vDescuento es de tipo descuento n es de tipo entero y todad las variables deben estar inicializadas
//Postcondicion:Permite eliminar un descuento
void remove_descuento(descuento **vDescuento,int *n){
int i,aux,encontrado=0;
char remove[20];
printf("\nIntroduce el ID del descuento  que desea eliminar --> "); scanf("%s",&remove);
for(i=0;i<(*n);i++){ //Buscamos el id del producto que tiene el ID introducido por usuario
    if(strcmp((*vDescuento)[i].id_cod,remove)==0){
         aux=i;
         encontrado=1;}
}
//Desplazamos todos los productos una posicion
for(i=aux;i+1<(*n);i++){
        strcpy((*vDescuento)[i].id_cod,(*vDescuento)[i+1].id_cod);
        strcpy((*vDescuento)[i].desc_desc,(*vDescuento)[i+1].desc_desc);
        strcpy((*vDescuento)[i].tipo,(*vDescuento)[i+1].tipo);
        strcpy((*vDescuento)[i].estado,(*vDescuento)[i+1].estado);
        (*vDescuento)[i].importe=(*vDescuento)[i+1].importe;
        strcpy((*vDescuento)[i].aplic,(*vDescuento)[i+1].aplic);}
(*n)--;//Reajustamos n
*vDescuento=realloc((descuento *)(*vDescuento),((*n))*sizeof(descuento));//Reajustamos la memoria del vector para que tenga uno menos
if(encontrado==0){printf("\nEl ID introducido no se encuentra en la base de datos\n");}
else{puts("El descuento ha sido eliminado correctamente");}

        }

//Cabecera:void listar_desc_client(desclient **vDesclient,cliente **vClientes,int *ndc ,int *nc);
//Precondicion: todas las estrucuturas y enteros deben estar inicalizados
//Postcondicion: Permite hacer una lista de todos los que poseenn un descuento
void listar_desc_client(descuento **vDescuento,desclient **vDesclient,cliente **vClientes,int *nd,int *ndc ,int *nc){//PENDIENTE
int i,j=0,k;
char clientev[20];


puts("A continuacion se mostrara una lista con todos los descuentos y los datos mas importantes del  cliente que posee el descuento:\n");

for(i=0;i<(*nd);i++){//Recorremos todos los descuentos de clientes
puts("///////////////////////////////////////////////////////////");
printf("\n\n<<<ID del descuento: %s (%s) >>>\n",(*vDescuento)[i].id_cod,(*vDescuento)[i].desc_desc);//mostramos todos los descuentos que hay en la estructura descuentos
puts("------------------------------------------------------------\n");

//A continuacion comprobamos que elementos coinciden con el id del descuewnto en la estructura desclient

for(j=0;j<(*ndc);j++){
    if(strcmp((*vDesclient)[j].id_cod,(*vDescuento)[i].id_cod)==0){
       // printf("Cliente: %s\n",(*vDesclient)[j].id_client);


    //Mostramos los datos del cliente que posee el dato

    for(k=0;k<(*nc);k++){//MOstramos la informacion mas importante del cliente que posee el descuento
        if(strcmp((*vDesclient)[j].id_client,(*vClientes)[k].id)==0){
           printf("ID del cliente --> %s \n",(*vClientes)[k].id);
           printf("Nombre del cliente --> %s\n",(*vClientes)[k].nom);
           printf("Apellido del cliente --> %s\n",(*vClientes)[k].apell);
           printf("Correo electronico --> %s\n",(*vClientes)[k].email);
           puts("-----------------------------------------------------------------\n");

        }


    }

    }


}
}
}


//Cabecera: void asig_desc(descuento **vDescuento,desclient **vDesclient,cliente **vClientes,int *nd,int *ndc ,int *nc)
//Precondicion:todas las estrucuturas y enteros deben estar inicalizados
//Postcondicion:Permite asignar un descuento a un cliente
void asig_desc(descuento **vDescuento,desclient **vDesclient,cliente **vClientes,int *nd,int *ndc ,int *nc){
int i,j,encontrado=0,encon2=0;
char id[20], id_cod[20],fech1[25],fech2[25]="01-01-2020",activo[20]="activo";
printf("Introduce el ID del usuario al que desea anadir un descuento --> ");
fflush(stdin);
scanf("%s",id);

for(i=0;i<(*nc);i++){
    if(strcmp((*vClientes)[i].id,id)==0){
        encontrado=1;}}

if(encontrado==0){puts("El ID introducido no se encuentra en la base de datos de ESIZON");}
else{
    printf("El id del cliente ha sido encontrado\n");
    *vDesclient=realloc((desclient *)(*vDesclient),((*ndc)+1)*sizeof(desclient));//aumentamos la memoria de desclient
    strcpy((*vDesclient)[*ndc].id_client,id);//Introducimmos el id del cliente en la estructura

printf("Introduce el ID del descuento --> ");
fflush(stdin);
scanf("%s",id_cod);
//Comprobamos si ese ID de descuento esta en la base de datos de descuentos
for(j=0;j<(*nd);j++){
     if(strcmp((*vDescuento)[j].id_cod,id_cod)==0){
        encon2=1;}}

if(encon2==0){puts("El ID del descuento introducido no se encuentra en la base de datos de descuentos");}
else{
    printf("El descuento ha sido encontrado \n");
    strcpy((*vDesclient)[*ndc].id_cod,id_cod);

    //Para introducir la fecha de asignacion a la estrucutur desclient llamaremos a la funcion cargar fecha
     calcula_fecha(fech1);
     strcpy((*vDesclient)[*ndc].fech_asig,fech1);
     strcpy((*vDesclient)[*ndc].fech_cad,fech2);
     strcpy((*vDesclient)[*ndc].estado,activo);}



    (*ndc)++;}

puts("Se ha añadido correctamente el descuento al cliente\n");

}

//cabecera: desc_client(desclient **vDesclient,int *ndc,char *id)
//Precondicion: la estructura vDesclient es de tipo desclient, ndc es un entero , id es un array todas las variables deben estar inicializadas
//Postcondicion: Permite mostrar una lista con los descuentes que tiene asignado el cliente accede
void desc_client(desclient **vDesclient,int *ndc,char *id){
int i;
puts("A continuacion se mostraran todos sus descuentos");
for(i=0;i<(*ndc);i++){
    if(strcmp((*vDesclient)[i].id_client,id)==0){
    puts("////////////////////////////////////////////");
    printf("Descuento %i\n",i);
    printf("Identificador del descuento --> %s\n",(*vDesclient)[i].id_cod);
    printf("fecha  de asignacion  --> %s\n",(*vDesclient)[i].fech_asig);  //Si sobra tiempo ponerle barras
    printf("fecha de caducidad --> %s\n",(*vDesclient)[i].fech_cad);
    printf("Estado del descuento --> %s\n",(*vDesclient)[i].estado);

    }


}

  puts("////////////////////////////////////////////");

}

//Cabecera: void busc_desc_client(desclient **vDesclient,cliente **vClientes,int *ndc ,int *nc)
//Precondicion:todas las estrucuturas y enteros deben estar inicalizados
//Postcondicion: Permite buscar un descuento y hacer una lista con los clientes que lo poseen
void busc_desc_client(descuento **vDescuento,desclient **vDesclient,cliente **vClientes,int *nd,int *ndc ,int *nc){
int i,j,k,encontrado=0,exit;
char descuento[20];

do{
printf("\nIntroduce el ID del descuento --> ");
fflush(stdin);
scanf("%s",&descuento);


//puts("A continuacion se mostrara una lista con todos los descuentos y los datos mas importantes del  cliente que posee el descuento:\n");
for(i=0;i<(*nd);i++){//Recorremos todos los descuentos de clientes
if(strcmp((*vDescuento)[i].id_cod,descuento)==0){
encontrado=1;

puts("///////////////////////////////////////////////////////////");
printf("\n\n<<<ID del descuento: %s (%s) >>>\n",(*vDescuento)[i].id_cod,(*vDescuento)[i].desc_desc);//mostramos todos los descuentos que hay en la estructura descuentos
puts("------------------------------------------------------------\n");

//A continuacion comprobamos que elementos coinciden con el id del descuewnto en la estructura desclient

for(j=0;j<(*ndc);j++){
    if(strcmp((*vDesclient)[j].id_cod,(*vDescuento)[i].id_cod)==0){
       // printf("Cliente: %s\n",(*vDesclient)[j].id_client);


    //Mostramos los datos del cliente que posee el dato

    for(k=0;k<(*nc);k++){//MOstramos la informacion mas importante del cliente que posee el descuento
        if(strcmp((*vDesclient)[j].id_client,(*vClientes)[k].id)==0){
           printf("ID del cliente --> %s \n",(*vClientes)[k].id);
           printf("Nombre del cliente --> %s\n",(*vClientes)[k].nom);
           printf("Apellido del cliente --> %s\n",(*vClientes)[k].apell);
           printf("Correo electronico --> %s\n",(*vClientes)[k].email);
           puts("-----------------------------------------------------------------\n");

        }


    }

    }


}
}
}
if(encontrado==0){puts("El ID del descuento introducido no se encuentra en la base de datos");}
puts("\n\n1 Buscar otro descuento y generar listado");
puts("2 Salir del menu(Generar listados de descuentos por clientes)");
do{
    printf("--> "); scanf("%d",&exit);
}while(exit!=1&&exit!=2);
}while(exit==1);

}


//Cabecera: void listar_desc_client_usado(descuento **vDescuento,desclient **vDesclient,cliente **vClientes,int *nd,int *ndc ,int *nc)
//Precondicion:todas las estrucuturas y enteros deben estar inicalizados
//Postcondicion: Permite generar un listado de todos los descuentos de esizon y mostrar quienes los han usado
void listar_desc_client_usado(descuento **vDescuento,desclient **vDesclient,cliente **vClientes,int *nd,int *ndc ,int *nc){
int i,j=0,k;
char clientev[20],noactivo[20]="no activo";


puts("A continuacion se mostrara una lista con todos los descuentos y los datos mas importantes de los  clientes que ya han usado el descuento:\n");

for(i=0;i<(*nd);i++){//Recorremos todos los descuentos de clientes
puts("///////////////////////////////////////////////////////////");
printf("\n\n<<<ID del descuento: %s (%s) >>>\n",(*vDescuento)[i].id_cod,(*vDescuento)[i].desc_desc);//mostramos todos los descuentos que hay en la estructura descuentos
puts("------------------------------------------------------------\n");

//A continuacion comprobamos que elementos coinciden con el id del descuewnto en la estructura desclient

for(j=0;j<(*ndc);j++){
    if(strcmp((*vDesclient)[j].id_cod,(*vDescuento)[i].id_cod)==0){
       if(strcmp((*vDesclient)[j].estado,noactivo)==0){//Si ya ha usado el descuento


    //Mostramos los datos del cliente que posee el dato

    for(k=0;k<(*nc);k++){//MOstramos la informacion mas importante del cliente que posee el descuento
        if(strcmp((*vDesclient)[j].id_client,(*vClientes)[k].id)==0){
           printf("ID del cliente --> %s \n",(*vClientes)[k].id);
           printf("Nombre del cliente --> %s\n",(*vClientes)[k].nom);
           printf("Apellido del cliente --> %s\n",(*vClientes)[k].apell);
           printf("Correo electronico --> %s\n",(*vClientes)[k].email);
           puts("-----------------------------------------------------------------\n");

        }


    }

    }

    }
}
}



}



//Cabecera:void MenuAdminDescuentos
//Precondicion:--
//Postcondicion:Acceder al menu administrador desucentos:
void MenuAdminDescuentos(){
int a,exit,op;
puts("<<<Bienvenido al menu de Descuentos (Administrador)>>>\n");
printf("Cargando datos del fichero Descuentos.txt....\n");
cargarDescuentos(&vDescuento,&nDescuentos);
printf("Cargando datos del fichero Desclient.txt....\n");
cargarDesclient(&vDesclient,&nDesclient);
do{
do{
printf("\nElija una opcion:\n");
puts("1 Listar Descuentos");
puts("2 Listado de Descuentos por clientes");
puts("3 Anadir Descuentos");
puts("4 Eliminar Descuento");
puts("5 Buscar Descuento");
puts("6 Modificar Descuento");
puts("7 Asignar Descuento a cliente");
fflush(stdin);
printf("--> ");scanf("%d",&a);
if(a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6&&a!=7){
    printf("\nIntroduzca una opcion valida!!!\n");
}
}while(a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6&&a!=7);

switch(a){
case 1: listar_descuento(&vDescuento,&nDescuentos);break;

case 2:
    puts("\n1 Generar listado de todos los descuentos y clientes que disponen de el");
    puts("2 Buscar descuento y mostrar clientes que lo poseen");
    puts("3 Generar listado de todos los descuentos y mostrar que clientes ya han usado este descuento");
    do{
    printf("--> "); scanf("%d",&op);
    }while(op!=1&&op!=2&&op!=3);
    switch(op){
    case 1: listar_desc_client(&vDescuento,&vDesclient,&vClientes,&nDescuentos,&nDesclient,&nClientes);
             break;
    case 2: busc_desc_client(&vDescuento,&vDesclient,&vClientes,&nDescuentos,&nDesclient,&nClientes);
             break;
    case 3: listar_desc_client_usado(&vDescuento,&vDesclient,&vClientes,&nDescuentos,&nDesclient,&nClientes);
            break;
        }break;
case 3: add_descuento(&vDescuento,&vDesclient,&vClientes,&nDescuentos,&nDesclient,&nClientes);break;

case 4: remove_descuento(&vDescuento,&nDescuentos);break;

case 5: busqueda_descuento(&vDescuento,&nDescuentos);break;

case 6: modifica_descuento(&vDescuento,&nDescuentos);break;
case 7: asig_desc(&vDescuento,&vDesclient,&vClientes,&nDescuentos,&nDesclient,&nClientes);break;                                break;
}
do{
printf("\n\nPulse 1 para realizar otra operacion/Pulse 2 para salir de(Menu descuentos administrador) --> ");scanf("%d",&exit);
}while(exit!=1&&exit!=2);
}while(exit==1);
puts("\n");
imprimeDescuentos(vDescuento,nDescuentos);
imprimeDesclient(vDesclient,nDesclient);
}



//Cabecera: void MenuClientDescuentos(char *id)
//Precondicion: id es un array y debe estar inicalizado
//Postcondicion: Acceder al menu clientes descuentos
void MenuClientDescuentos(char *id){
int exit;
puts("<<<Bienvenido al menu de Descuentos (Clientes)>>>\n");
printf("Cargando datos del fichero Descuentos.txt....\n");
cargarDescuentos(&vDescuento,&nDescuentos);
printf("Cargando datos del fichero Desclient.txt....\n");
cargarDesclient(&vDesclient,&nDesclient);
do{

desc_client(&vDesclient,&nDesclient,id);







do{
printf("\n\nPulse 1 para realizar otra operacion/Pulse 2 para salir de(Menu descuentos administrador) --> ");scanf("%d",&exit);
}while(exit!=1&&exit!=2);
}while(exit==1);




}




/*LA SIGUIENTE FUNCION (MAIN) SIRVE PARA COMPROBAR QUE TODOS LOS MENUS FUNCIONAN CORRECTAMENTE
  INDEPENDIENTEMENTE DEL PROGRAMA PRONCIPAL
  SI EXISTE ALGUN FALLO EN EL PROGRAMA PRINCIPAL SE PODRA COMPROBAR EL CORRECTO FUNCIONAMIENTO
  DE LAS FUNCIONES PROGRAMADAS POR  (JOSÉ MANUEL TROYA) , UTILIZANDO LA FUNCION MAIN.*/


/*int main(){
int a;
puts("Como desea acceder:\n");
puts("1 Administador ");
puts("2 Cliente");
printf("--> "); scanf("%d",&a);
switch(a){

case 1: MenuAdminDescuentos();
//case 2: MenuClientDescuentos();
}
return 0;

}*/

