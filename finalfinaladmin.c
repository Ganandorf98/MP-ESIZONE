//Archivo .c Programado por --> Teodoro Sibón Jiménez
#include "admin.h"

//Cabecera: void MenuAdmin	(CORRECTO)
void MenuAdmin(char *id){
int z,exit;
puts("\nBienvenido al menu de Administradores, ¿En que te podemos ayudar?\n");
do{
    printf("1: Perfil\n");
    printf("2: Clientes\n");
    printf("3: Proveedores\n");
    printf("4: Productos\n");
    printf("5: Categorias\n");
    printf("6: Pedidos(NF)\n");
    printf("7: Transportistas(NF)\n");
    printf("8: Descuentos\n");
    printf("9: Devoluciones(NF)\n");

	printf("-->");
	fflush(stdin);
    scanf(" %d",&z);

    switch( z ){
          case 1 :
				puts("Correctamente redirigido a MenuAdminPerfil\n");
				MenuAdminPerfil(id);break;
          case 2 :
		  		puts("Correctamente redirigido a MenuAdminClientes\n");
				MenuAdminClientes();break;
          case 3 :
		  		puts("Correctamente redirigido a MenuAdminProveedores\n");
				MenuAdminProveedores();break;
          case 4 :
		  		MenuAdminProductos();
		  		puts("Correctamente redirigido a MenuAdminProductos\n");break;
          case 5 :
		  		MenuAdminCategorias();
		  		puts("Correctamente redirigido a MenuAdminCategorias\n");break;
          case 6 :
		  		//MenuAdminPedidos(id);
		  		puts("Funcion actualmente no disponible");break;
          case 7 :
		  		//MenuAdminTransportistas(id);
		  		puts("Funcion actualmente no disponible");break;
          case 8 :
		 	 	MenuAdminDescuentos();
		 	 	puts("Correctamente redirigido a MenuAdminDescuentos\n");break;
          case 9 :
		  		//MenuAdminDevoluciones(id);
		  		puts("Funcion actualmente no disponible");break;
        }
       	do{
			printf("\nDesea salir del menu de Administradores?\nPulse 1 para seguir en el Menu/Pulse 2 para salir --> ");
			scanf("%d",&exit);
		}while(exit!=1&&exit!=2);

 	}while(exit==1);
}

////////////////////////////////MENU ADMIN PERFIL/////////////////////////////////////////////////////////////////

//Cabecera: void MenuAdminPerfil (CORRECTO)
void MenuAdminPerfil(char *id){
int z,exit;
do{
	puts("1: Consultar datos de su perfil");
	puts("2: Modificar datos de su perfil");

	fflush(stdin);
	printf("--> ");
	scanf("%d",&z);

	switch(z){
		case 1:
			puts("Correctamente redirigido a ConsultarPerfil");
			consultaPerfil(&vAdmins,&nAdmins,id);
			break;
		case 2:
			puts("Correctamente redirigido a ModificarPerfil");
			modificaPerfil(&vAdmins,&nAdmins,id);
			break;
	}

	do{
		printf("\nDesea realizar otra operacion?\nPulse 1 para realizar otra operacion/Pulse 2 para salir --> ");
		scanf("%d",&exit);
	}while(exit!=1&&exit!=2);

}while(exit==1);
}

//Cabecera: void consultaPerfil (CORRECTO)
void consultaPerfil(admin **vAdmins,int *n,char *id){
int i,encontrado=0;
//char id[10];
	 //  printf("Introduzca su ID --> ");
	//   fflush(stdin);
	//   scanf("%s",&id);

       for(i=0;i<(*n);i++){
        	if(strcmp((*vAdmins)[i].id,id)==0){
             	puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");

            	printf("Datos del perfil:\n");
             	printf("ID: %s \n",(*vAdmins)[i].id);
             	printf("Contrasena: %s \n",(*vAdmins)[i].contrasena);
             	printf("Nombre: %s \n",(*vAdmins)[i].nom);
             	printf("Email: %s \n",(*vAdmins)[i].email);

             	puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
             	encontrado=1;//si encontrado esta en 1 es que se habrá encontrado el producto en la base de datos
       		}
		}
        if(encontrado==0){
			printf("\nEl ID no se encuentra en la base de datos\n");
		}
}

//Cabecera: void modificaPerfil (CORRECTO)
void modificaPerfil(admin **vAdmins, int *n,char *id){

int i,a,encontrado=0;
char new_id[10],new_con[30],new_nom[10],new_email[30];

//printf("Introduce el ID de la categoria a la que desea modificar sus datos --> ");
//fflush(stdin);
//scanf("%s",&id);

for(i=0;i<(*n);i++){
    if(strcmp((*vAdmins)[i].id,id)==0){
        encontrado=1;//si encontado=1 es porque se ha encontrado el dato en la estructura
        printf("Indique la accion que desea realizar:\n");//Preguntamos que cambio desea realizar el usuario
        puts("1 Cambiar el ID");
        puts("2 Cambiar la contrasena");
        puts("3 Cambiar el nombre");
        puts("4 Cambiar el email");
        do{
        	printf("--> ");
			scanf("%d",&a);
        }while(a<1&&a>4);

        //Creamos un switch para modificar el dato que hay escogido el usuario
        switch(a){
        case 1:
            printf("Introduce el nuevo ID --> ");
            fflush(stdin);
            scanf("%s",&new_id);
            strcpy((*vAdmins)[i].id,new_id);//Se copiara el nuevo id en la poscion de memoria i de la estructura Vcategoria
            break;
        case 2:
            printf("Introuce la nueva contrasena --> ");
            fflush(stdin);
            scanf("%s",&new_con);
            strcpy((*vAdmins)[i].contrasena,new_con);//Se copiara la nueva descripcion de categoria en la poscion de memoria i de la estructura Vcategoria
            break;
		case 3:
            printf("Introuce el nuevo nombre --> ");
            fflush(stdin);
            scanf("%s",&new_nom);
            strcpy((*vAdmins)[i].nom,new_nom);//Se copiara la nueva descripcion de categoria en la poscion de memoria i de la estructura Vcategoria
            break;
		case 4:
            printf("Introuce el nuevo email --> ");
            fflush(stdin);
            scanf("%s",&new_email);
            strcpy((*vAdmins)[i].email,new_email);//Se copiara la nueva descripcion de categoria en la poscion de memoria i de la estructura Vcategoria
            break;


		}
    }



}
if(encontrado==0){puts("El ID introducido no se ha encontrado en la Base de datos");}

else{puts("Los datos han sido modificados correctamente");}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////MENU ADMIN CLIENTES///////////////////////////////////////////////

//Cabecera: void MenuClientes (CORRECTO)

void MenuAdminClientes(){
int z,exit;
puts("Ha elegido la opcion de Clientes");
puts("Cargando los datos de Cliente.txt.....");
cargarClientes(&vClientes,&nClientes);

do{
	printf("\nElija una opcion:\n");
	puts("(1) Listar Clientes");
	puts("(2) Buscar Cliente");
	puts("(3) Anadir Cliente");
	puts("(4) Eliminar Cliente");
	puts("(5) Modificar Cliente");

	fflush(stdin);
	printf("\n--> ");
	scanf("%d",&z);

	switch(z){
		case 1:
		puts("Correctamente redirido a ListarClientes");
		listarCliente(&vClientes,&nClientes);
		break;
		case 2:
		puts("Correctamente redirido a BuscarClientes");
		busquedaCliente(&vClientes,&nClientes);
		break;
		case 3:
		puts("Correctamente redirido a AnadirClientes");
		addCliente(&vClientes,&nClientes);
		break;
		case 4:
		puts("Correctamente redirido a QuitarClientes");
		removeCliente(&vClientes,&nClientes);
		break;
		case 5:
		puts("Correctamente redirido a ModificarClientes");
		modificaCliente(&vClientes,&nClientes);
		break;
	}

	do{
		printf("\n\nPulse 1 para continuar en Menu Clientes/Pulse 2 para salir --> ");
		scanf("%d",&exit);
	}while(exit!=1&&exit!=2);

}while(exit==1);
}

//Cabecera: void listarClientes (CORRECTO)

void listarCliente(cliente **vCliente, int *n){
int i;
puts("A continuacion se mostraran todos los datos de todos los clientes de ESIZON:\n\n");
puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
for(i=0;i<(*n);i++){

    printf("ID del Cliente: %s \n",(*vCliente)[i].id);
    printf("Contrasena: %s \n",(*vCliente)[i].contrasena);
    printf("Nombre: %s \n",(*vCliente)[i].nom);
    printf("Apellido:  %s\n",(*vCliente)[i].apell);
    printf("Direccion: %s\n",(*vCliente)[i].direccion);
    printf("Localidad: %s\n",(*vCliente)[i].localidad);
    printf("Provincia: %s\n",(*vCliente)[i].provincia);
    printf("Email: %s \n",(*vCliente)[i].email);
    printf("Dinero en la cartera: %d euros\n",(*vCliente)[i].cartera);

puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
    }
}

//Cabecera: void busquedaCliente (CORRECTO)

void busquedaCliente(cliente **vCliente, int *n){
int i,z,j,encontrado=0,encontrado1=0,exit;
char name[15],id[10];

printf("Pulse 1 para realizar la busqueda mediante ID del cliente\n");
printf("Pulse 2 para realizar la busqueda mediante el nombre del cliente --> ");
scanf("%d",&z);

do{
switch(z){
  case 1:
        printf("Introduzca el id del cliente --> ");
	    fflush(stdin);
		scanf("%s",&id);

    	for(i=0;i<(*n);i++){
        	if(strcmp((*vCliente)[i].id,id)==0){
    			printf("ID del Cliente: %s \n",(*vCliente)[i].id);
   				printf("Contrasena: %s \n",(*vCliente)[i].contrasena);
    			printf("Nombre: %s \n",(*vCliente)[i].nom);
    			printf("Apellido:  %s\n",(*vCliente)[i].apell);
    			printf("Direccion: %s\n",(*vCliente)[i].direccion);
    			printf("Localidad: %s\n",(*vCliente)[i].localidad);
    			printf("Provincia: %s\n",(*vCliente)[i].provincia);
    			printf("Email: %s \n",(*vCliente)[i].email);
    			printf("Dinero en la cartera: %d euros\n",(*vCliente)[i].cartera);
             	puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
             	encontrado=1;//si encontrado esta en 1 es que se habrá encontrado el producto en la base de datos
       		}
		}
        if(encontrado==0){
			printf("\nEl Id introducido no se encuentra en la base de datos\n");
		}
        break;

  case 2:
    printf("Introduzca el nombre del cliente --> ");
    fflush(stdin);
    fgets(name,15,stdin);

    for(j=0;j<(*n);j++){
        if(strcmp((*vCliente)[j].nom,name)==0){//Si ambas cadenas son iguales:

    			printf("ID del Cliente: %s \n",(*vCliente)[i].id);
   				printf("Contrasena: %s \n",(*vCliente)[i].contrasena);
    			printf("Nombre: %s \n",(*vCliente)[i].nom);
    			printf("Apellido:  %s\n",(*vCliente)[i].apell);
    			printf("Direccion: %s\n",(*vCliente)[i].direccion);
    			printf("Localidad: %s\n",(*vCliente)[i].localidad);
    			printf("Provincia: %s\n",(*vCliente)[i].provincia);
    			printf("Email: %s \n",(*vCliente)[i].email);
    			printf("Dinero en la cartera: %d euros\n",(*vCliente)[i].cartera);
             	encontrado1=1;
		}
    }
    if(encontrado==0){
		printf("\nEl nombre introducido no se encuentra en la base de datos\n");
	}
    break;
}
do{
    printf("Pulse 1 para buscar otro cliente/Pulse 2 para salir -->  ");
	scanf("%d",&exit);
}while(exit!=1&&exit!=2);

}while(exit==1);
}

//Cabecera: void addCliente (CORRECTO)
void addCliente(cliente **vCliente,int *n){
    *vCliente=realloc((cliente *)(*vCliente),((*n)+1)*sizeof(cliente));

	fflush(stdin);
    printf("\nIntroduce el ID del Cliente --> ");
	scanf("%s",&(*vCliente)[*n].id); fflush(stdin);

    printf("\nIntroduce la contrasena del Cliente --> ");
	scanf("%s",&(*vCliente)[*n].contrasena);fflush(stdin);

    printf("\nIntroduce el nombre del Cliente --> ");
	scanf("%s",&(*vCliente)[*n].nom);fflush(stdin);

    printf("\nIntroduce el apellido de la Cliente --> ");
	scanf("%s",&(*vCliente)[*n].apell);fflush(stdin);

    printf("\nIntroduce la direccion del Cliente --> ");
	scanf("%s",&(*vCliente)[*n].direccion);fflush(stdin);

    printf("\nIntroduce la localidad del Cliente --> ");
	scanf("%s",&(*vCliente)[*n].localidad);fflush(stdin);

    printf("\nIntroduce la provincia del Cliente --> ");
	scanf("%s",&(*vCliente)[*n].provincia);fflush(stdin);

    printf("\nIntroduce el email del Cliente --> ");
	scanf("%s",&(*vCliente)[*n].email);fflush(stdin);

    printf("\nIntroduce dinero en la cartera del Cliente --> ");
	scanf("%d",&(*vCliente)[*n].cartera);fflush(stdin);
    (*n)++;
    puts("correctamente añadido");
}



//Cabecera: void removeCliente (CORRECTO)
void removeCliente(cliente **vClientes,int *n){
    int i,aux;
char remove[10];
printf("Introduce el ID del cliente que desea eliminar --> "); scanf("%s",&remove);
for(i=0;i<(*n);i++){ //Buscamos el id del producto que tiene el ID introducido por usuario
    if(strcmp((*vClientes)[i].id,remove)==0){
         aux=i;}
}
//Desplazamos todos los productos una posicion
for(i=aux;i+1<(*n);i++){
        strcpy((*vClientes)[i].id,(*vClientes)[i+1].id);//Desplazamos elementos una posicion
        strcpy((*vClientes)[i].contrasena,(*vClientes)[i+1].contrasena);}//Desplazamos elementos una posicion
        strcpy((*vClientes)[i].nom,(*vClientes)[i+1].nom);
        strcpy((*vClientes)[i].apell,(*vClientes)[i+1].apell);
        strcpy((*vClientes)[i].direccion,(*vClientes)[i+1].direccion);
        strcpy((*vClientes)[i].localidad,(*vClientes)[i+1].localidad);
        strcpy((*vClientes)[i].provincia,(*vClientes)[i+1].provincia);
        strcpy((*vClientes)[i].email,(*vClientes)[i+1].email);
        (*vClientes)[i].cartera=(*vClientes)[i+1].cartera;
        (*n)--;//Reajustamos n
        *vClientes=realloc((cliente *)(*vClientes),((*n))*sizeof(cliente));//Reajustamos la memoria del vector para que tenga uno menos
   printf("\nEl cliente se elimino correctamente\n");
}


//Cabecera: void modificarCliente (CORRECTO)
void modificaCliente(cliente **vClientes, int *n){
int i,a,encontrado=0,new_cartera;
char id[10],new_id[10],new_con[30],new_nom[10],new_apell[15],new_direccion[15],new_localidad[15],new_provincia[15],new_email[30];

printf("Introduce el ID del cliente al que desea modificar sus datos --> ");
fflush(stdin);
scanf("%s",&id);

for(i=0;i<(*n);i++){
    if(strcmp((*vClientes)[i].id,id)==0){
        encontrado=1;//si encontado=1 es porque se ha encontrado el dato en la estructura
        printf("Indique la accion que desea realizar:\n");//Preguntamos que cambio desea realizar el usuario
        puts("1 Cambiar el ID");
        puts("2 Cambiar la contrasena");
        puts("3 Cambiar el nombre");
        puts("4 Cambiar el apellido");
        puts("5 Cambiar la direccion");
        puts("6 Cambiar la localidad");
        puts("7 Cambiar la provincia");
        puts("8 Cambiar el email");
        puts("9 Cambiar la cartera");
        do{
        	printf("--> ");
			scanf("%d",&a);
        }while(a<1&&a>9);

        //Creamos un switch para modificar el dato que hay escogido el usuario
        switch(a){
        case 1:
            printf("Introduce el nuevo ID --> ");
            fflush(stdin);
            scanf("%s",&new_id);
            strcpy((*vClientes)[i].id,new_id);
            break;

        case 2:
            printf("Introduce la nueva contrasena --> ");
            fflush(stdin);
            scanf("%s",&new_con);
            strcpy((*vClientes)[i].contrasena,new_con);
            break;

		case 3:
            printf("Introduce el nuevo nombre --> ");
            fflush(stdin);
            scanf("%s",&new_nom);
            strcpy((*vClientes)[i].nom,new_nom);
            break;

        case 4:
            printf("Introduce el nuevo apellido --> ");
            fflush(stdin);
            scanf("%s",&new_apell);
            strcpy((*vClientes)[i].nom,new_apell);
            break;

        case 5:
            printf("Introduce la nueva direccion --> ");
            fflush(stdin);
            scanf("%s",&new_direccion);
            strcpy((*vClientes)[i].nom,new_direccion);
            break;

        case 6:
            printf("Introduce la nueva localidad --> ");
            fflush(stdin);
            scanf("%s",&new_localidad);
            strcpy((*vClientes)[i].nom,new_localidad);
            break;

        case 7:
            printf("Introduce la nueva provincia --> ");
            fflush(stdin);
            scanf("%s",&new_provincia);
            strcpy((*vClientes)[i].nom,new_provincia);
            break;

		case 8:
            printf("Introduce el nuevo email --> ");
            fflush(stdin);
            scanf("%s",&new_email);
            strcpy((*vClientes)[i].email,new_email);
            break;

		case 9:
            printf("Introduce la nueva cantidad --> ");
            fflush(stdin);
            scanf("%d",&new_cartera);
            (*vClientes)[i].cartera=new_cartera;
            break;


		}
    }



}
if(encontrado==0){puts("El ID introducido no se ha encontrado en la Base de datos");}

else{puts("Los datos han sido modificados correctamente");}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////FUNCIONES MENU ADMIN PROV/////////////////////////////////////////////////////

//Cabecera: void MenuAdminProv (CORRECTO)
void MenuAdminProveedores(){
int z,exit;
puts("Ha elegido la opcion de Proveedores");
do{
	printf("\nElija una opcion:\n");
	puts("(1) Listar Proveedores");
	puts("(2) Buscar Proveedor");
	puts("(3) Anadir Proveedor");
	puts("(4) Eliminar Proveedor");
	puts("(5) Modificar Proveedor");

	fflush(stdin);
	printf("\n--> ");
	scanf("%d",&z);

	switch(z){
		case 1:

		puts("Correctamente redirigido a listarProveedor");
		listarProveedor(&vProvs,&nProvs);break;

		case 2:
			puts("Correctamente redirigido a busquedaProveedor");
			busquedaProveedor(&vProvs,&nProvs);break;
		case 3:
			 puts("Correctamente redirigido a anadirProveedor");
			 addProveedor(&vProvs,&nProvs);break;
		case 4:
			 puts("Correctamente redirigido a eliminarProveedor");
			 removeProveedor(&vProvs,&nProvs);break;
		case 5:
			puts("Correctamente redirigido a modificarProveedor");
			modificaProveedor(&vProvs,&nProvs);break;
	}

	do{
		printf("\n\nPulse 1 para realizar otra operacion en el menu de Proveedores/Pulse 2 para salir --> ");
		scanf("%d",&exit);
	}while(exit!=1&&exit!=2);

}while(exit==1);
}

//Cabecera: void listarProveedores (CORRECTO)
void listarProveedor(prov **vProvs, int *n){
int i;
puts("A continuacion se mostraran todos los datos de todos los proveedores de ESIZON:\n\n");
puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
for(i=0;i<(*n);i++){

    printf("ID del Proveedor: %s \n",(*vProvs)[i].id);
    printf("Contrasena: %s \n",(*vProvs)[i].contrasena);
    printf("Empresa:  %s\n",(*vProvs)[i].empresa);
	printf("Nombre: %s \n",(*vProvs)[i].nom);
    printf("Email: %s \n",(*vProvs)[i].email);

puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" );
    }
}

//Cabecera: void busquedaProveedor (CORRECTO)
void busquedaProveedor(prov **vProvs, int *n){
int i,z,j,encontrado=0,encontrado1=0,exit;
char name[15],id[10];

printf("Pulse 1 para realizar la busqueda mediante ID del proveedor\n");
printf("Pulse 2 para realizar la busqueda mediante el nombre del proveedor\n --> ");
scanf("%d",&z);

do{
switch(z){
  case 1:
        printf("Introduzca el id del proveedor --> ");
	    fflush(stdin);
		scanf("%s",&id);

    	for(i=0;i<(*n);i++){
        	if(strcmp((*vProvs)[i].id,id)==0){
    			printf("ID del Cliente: %s \n",(*vProvs)[i].id);
   				printf("Contrasena: %s \n",(*vProvs)[i].contrasena);
    			printf("Empresa:  %s\n",(*vProvs)[i].empresa);
				printf("Nombre: %s \n",(*vProvs)[i].nom);
    			printf("Email: %s \n",(*vProvs)[i].email);

             	puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
             	encontrado=1;//si encontrado esta en 1 es que se habrá encontrado el producto en la base de datos
       		}
		}
        if(encontrado==0){
			printf("\nEl Id introducido no se encuentra en la base de datos\n");
		}
        break;

  case 2:
    printf("Introduzca el nombre del proveedor --> ");
    fflush(stdin);
    fgets(name,15,stdin);

    for(j=0;j<(*n);j++){
        if(strcmp((*vProvs)[j].nom,name)==0){//Si ambas cadenas son iguales:

    			printf("ID del Cliente: %s \n",(*vProvs)[i].id);
   				printf("Contrasena: %s \n",(*vProvs)[i].contrasena);
    			printf("Empresa:  %s\n",(*vProvs)[i].empresa);
				printf("Nombre: %s \n",(*vProvs)[i].nom);
    			printf("Email: %s \n",(*vProvs)[i].email);

             	encontrado1=1;
		}
    }
    if(encontrado==0){
		printf("\nEl nombre introducido no se encuentra en la base de datos\n");
	}
    break;
}
do{
    printf("Pulse 1 para buscar otro proveedor/Pulse 2 para salir -->  ");
	scanf("%d",&exit);
}while(exit!=1&&exit!=2);

}while(exit==1);
}

//Cabecera: void addProveedor (CORRECTO)
void addProveedor(prov **vProvs,int *n){
    *vProvs=realloc((prov *)(*vProvs),((*n)+1)*sizeof(prov));

	fflush(stdin);
    printf("\nIntroduce el ID del Proveedor --> ");
	scanf("%s",&(*vProvs)[*n].id); fflush(stdin);

    printf("\nIntroduce la contrasena del Proveedor --> ");
	scanf("%s",&(*vProvs)[*n].contrasena);fflush(stdin);

	printf("\nIntroduce el empresa del Proveedor --> ");
	scanf("%s",&(*vProvs)[*n].empresa);fflush(stdin);

    printf("\nIntroduce el nombre del Proveedor --> ");
	scanf("%s",&(*vProvs)[*n].nom);fflush(stdin);

    printf("\nIntroduce el email del Proveedor --> ");
	scanf("%s",&(*vProvs)[*n].email);fflush(stdin);

    (*n)++;
    puts("correctamente añadido");
}


//Cabecera: void removeProveedor (CORRECTO)
void removeProveedor(prov **vProvs,int *n){
    int i,aux;
char remove[10];
printf("Introduce el ID del proveedor que desea eliminar --> "); scanf("%s",&remove);
for(i=0;i<(*n);i++){ //Buscamos el id del producto que tiene el ID introducido por usuario
    if(strcmp((*vProvs)[i].id,remove)==0){
         aux=i;}
}
//Desplazamos todos los productos una posicion
for(i=aux;i+1<(*n);i++){
        strcpy((*vProvs)[i].id,(*vProvs)[i+1].id);//Desplazamos elementos una posicion
        strcpy((*vProvs)[i].contrasena,(*vProvs)[i+1].contrasena);}//Desplazamos elementos una posicion
        strcpy((*vProvs)[i].empresa,(*vProvs)[i+1].empresa);
		strcpy((*vProvs)[i].nom,(*vProvs)[i+1].nom);
        strcpy((*vProvs)[i].email,(*vProvs)[i+1].email);

        (*n)--;//Reajustamos n
        *vProvs=realloc((prov *)(*vProvs),((*n))*sizeof(prov));//Reajustamos la memoria del vector para que tenga uno menos
   printf("\nEl proveedor se elimino correctamente\n");
}

//Cabecera: void modificaProveedor (CORRECTO)
void modificaProveedor(prov **vProvs, int *n){
int i,a,encontrado=0;
char id[10],new_id[10],new_con[30],new_empresa[15],new_nom[15],new_email[30];

printf("Introduce el ID del proveedor al que desea modificar sus datos --> ");
fflush(stdin);
scanf("%s",&id);

for(i=0;i<(*n);i++){
    if(strcmp((*vProvs)[i].id,id)==0){
        encontrado=1;//si encontado=1 es porque se ha encontrado el dato en la estructura
        printf("Indique la accion que desea realizar:\n");//Preguntamos que cambio desea realizar el usuario
        puts("1 Cambiar el ID");
        puts("2 Cambiar la contrasena");
        puts("3 Cambiar la empresa");
		puts("4 Cambiar el nombre");
        puts("5 Cambiar el email");

        do{
        	printf("--> ");
			scanf("%d",&a);
        }while(a<1&&a>5);

        //Creamos un switch para modificar el dato que hay escogido el usuario
        switch(a){
        case 1:
            printf("Introduce el nuevo ID --> ");
            fflush(stdin);
            scanf("%s",&new_id);
            strcpy((*vProvs)[i].id,new_id);
            break;

        case 2:
            printf("Introduce la nueva contrasena --> ");
            fflush(stdin);
            scanf("%s",&new_con);
            strcpy((*vProvs)[i].contrasena,new_con);
            break;

        case 3:
            printf("Introduce la nueva empresa --> ");
            fflush(stdin);
            scanf("%s",&new_empresa);
            strcpy((*vProvs)[i].nom,new_empresa);
            break;

		case 4:
            printf("Introduce el nuevo nombre --> ");
            fflush(stdin);
            scanf("%s",&new_nom);
            strcpy((*vProvs)[i].nom,new_nom);
            break;

		case 5:
            printf("Introduce el nuevo email --> ");
            fflush(stdin);
            scanf("%s",&new_email);
            strcpy((*vProvs)[i].email,new_email);
            break;
		}
    }



}
if(encontrado==0){puts("El ID introducido no se ha encontrado en la Base de datos");}

else{puts("Los datos han sido modificados correctamente");}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

