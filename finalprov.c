//Archivo .c Programado por --> Teodoro Sibón Jiménez

#include "admin.h"



////////////////////////////FUNCION MENU PROV//////////////////////////

void MenuProv(char *id){ //El char *id representa la posicion en el vector  del  que ha iniciado sesiÃ³

int z,exit;
printf("Bienvenido a su Menu de Proveedor, %s",id);

do{
	printf("\nElija una opcion:\n");
	puts("(1) Perfil");
	puts("(2) Productos");
	puts("(3) Pedidos(NF)");

	fflush(stdin);
	printf("\n--> ");
	scanf("%d",&z);

	switch(z){
		case 1:
			puts("Correctamente redirigido a MenuProveedorPerfil");
			MenuProvPerfil(id);
			break;

		case 2:
			puts("Correctamente redirigido a MenuProveedorProductos");
			MenuProvProductos(id);
			break;
		case 3:
			puts("Funcion actualmente no disponible");
			 //MenuProvPedidos(&vProvs,&nProvs);
			 break;
	}

	do{
		printf("\n\nPulse 1 para realizar otra operacion en su Menu de Proveedor/Pulse 2 para salir --> ");
		scanf("%d",&exit);
	}while(exit!=1&&exit!=2);

}while(exit==1);
}


//////////////////////////////////////////////////////////////////////
//////////////////////////FUNCIONES MENU PROV PERFIL/////////////////////

//Cabecera: void MenuProvPerfil (CORRECTO)
void MenuProvPerfil(char *id){
int z,exit;
do{
	puts("1: Consultar datos de su perfil");
	puts("2: Modificar datos de su perfil");

	fflush(stdin);
	printf("--> ");
	scanf("%d",&z);

	switch(z){
		case 1:
			puts("Correctamente redirigido a ConsultarPerfilP");
			consultaPerfilP(&vProvs,&nProvs,id);
			break;
		case 2:
			puts("Correctamente redirigido a ModificarPerfilP");
			modificaPerfilP(&vProvs,&nProvs,id);
			break;
	}

	do{
		printf("\nDesea realizar otra operacion?\nPulse 1 para realizar otra operacion/Pulse 2 para salir --> ");
		scanf("%d",&exit);
	}while(exit!=1&&exit!=2);

}while(exit==1);
}

//Cabecera: void consultaPerfilP (CORRECTO)
void consultaPerfilP(prov **vProvs,int *n,char *id){
int i,encontrado=0;
//char id[10];
	 //  printf("Introduzca su ID --> ");
	//   fflush(stdin);
	//   scanf("%s",&id);

       for(i=0;i<(*n);i++){
        	if(strcmp((*vProvs)[i].id,id)==0){
             	puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");

            	printf("Datos del perfil:\n");
             	printf("ID: %s \n",(*vProvs)[i].id);
             	printf("Contrasena: %s \n",(*vProvs)[i].contrasena);
             	printf("Empresa: %s \n",(*vProvs)[i].empresa);
				printf("Nombre: %s \n",(*vProvs)[i].nom);
             	printf("Email: %s \n",(*vProvs)[i].email);


             	puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
             	encontrado=1;//si encontrado esta en 1 es que se habrá encontrado el producto en la base de datos
       		}
		}
        if(encontrado==0){
			printf("\nEl ID no se encuentra en la base de datos\n");
		}
}

//Cabecera: void modificaPerfilP (CORRECTO)
void modificaPerfilP(prov **vProvs, int *n,char *id){

int i,a,encontrado=0;
char new_id[10],new_con[30],new_empresa[15],new_email[30];

//printf("Introduce el ID de la categoria a la que desea modificar sus datos --> ");
//fflush(stdin);
//scanf("%s",&id);

for(i=0;i<(*n);i++){
    if(strcmp((*vProvs)[i].id,id)==0){
        encontrado=1;//si encontado=1 es porque se ha encontrado el dato en la estructura
        printf("Indique la accion que desea realizar:\n");//Preguntamos que cambio desea realizar el usuario
        puts("1 Cambiar el ID");
        puts("2 Cambiar la contrasena");
        puts("3 Cambiar la empresa");
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
            strcpy((*vProvs)[i].id,new_id);
            break;
        case 2:
            printf("Introuce la nueva contrasena --> ");
            fflush(stdin);
            scanf("%s",&new_con);
            strcpy((*vProvs)[i].contrasena,new_con);
            break;
		case 3:
            printf("Introuce la nueva empresa --> ");
            fflush(stdin);
            scanf("%s",&new_empresa);
            strcpy((*vProvs)[i].empresa,new_empresa);
            break;
		case 4:
            printf("Introuce el nuevo email --> ");
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

////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
/*int main(){
		char idprueba[10]="2";
	puts("Iniciamos ESIZONE-PROVEEDORES....\n");
	cargarProvs(&vProvs,&nProvs);

	MenuProv(idprueba);

	puts("\nEl programa ha finalizado. Guardando datos....\n");
	imprimeProvs(vProvs,nProvs);

	printf("Hasta otra %s",idprueba);
	return 0;
}*/
