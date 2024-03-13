//Archivo .c Programado por --> Teodoro Sibón Jiménez

#include "admin.h"

////////////////////////////////////////FUNCION MENU CLIENTE///////////////////////////////////////////////
void MenuCliente(char *id){ //El char *id representa la posicion en el vector  del  que ha iniciado sesiÃ³

int z,exit;
printf("Bienvenido a su Menu de Cliente, %s",id);

do{
	printf("\nElija una opcion:\n");
	puts("(1) Perfil");
	puts("(2) Productos");
	puts("(3) Descuentos");
	puts("(4) Pedidos(NF)");
	puts("(5) Devoluciones(NF)");

	fflush(stdin);
	printf("\n--> ");
	scanf("%d",&z);

	switch(z){
		case 1:
			puts("Correctamente redirigido a MenuClientePerfil");
			MenuClientePerfil(id);
			break;

		case 2:
			puts("Correctamente redirigido a MenuClienteProductos");
			MenuClientProductos();
			break;
		case 3:
			 puts("Correctamente redirigido a MenuClienteDescuentos");
			 MenuClientDescuentos(id);
			 break;
		case 4:
			 puts("Funcion actualmente no disponible");
			 //MenuClientePedidos(&vProvs,&nProvs);
			 break;
		case 5:
			puts("Funcion actualmente no disponible");
			//MenuClienteDevoluciones(&vProvs,&nProvs);
			break;
	}

	do{
		printf("\n\nPulse 1 para realizar otra operacion en su Menu de Cliente/Pulse 2 para salir --> ");
		scanf("%d",&exit);
	}while(exit!=1&&exit!=2);

}while(exit==1);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////FUNCIONES MENU CLIENTE PERFIL//////////////////////////////////////////////

//Cabecera: void MenuClientePerfil (CORRECTO)
void MenuClientePerfil(char *id){
int z,exit;
do{
	puts("1: Consultar datos de su perfil");
	puts("2: Modificar datos de su perfil");

	fflush(stdin);
	printf("--> ");
	scanf("%d",&z);

	switch(z){
		case 1:
			puts("Correctamente redirigido a ConsultarPerfilC");
			consultaPerfilC(&vClientes,&nClientes,id);
			break;
		case 2:
			puts("Correctamente redirigido a ModificarPerfilC");
			modificaPerfilC(&vClientes,&nClientes,id);
			break;
	}

	do{
		printf("\nDesea realizar otra operacion?\nPulse 1 para realizar otra operacion/Pulse 2 para salir --> ");
		scanf("%d",&exit);
	}while(exit!=1&&exit!=2);

}while(exit==1);
}

//Cabecera: void consultaPerfilC (CORRECTO)
void consultaPerfilC(cliente **vClientes,int *n,char *id){
int i,encontrado=0;
//char id[10];
	 //  printf("Introduzca su ID --> ");
	//   fflush(stdin);
	//   scanf("%s",&id);

       for(i=0;i<(*n);i++){
        	if(strcmp((*vClientes)[i].id,id)==0){
             	puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");

            	printf("Datos del perfil:\n");
             	printf("ID: %s \n",(*vClientes)[i].id);
             	printf("Contrasena: %s \n",(*vClientes)[i].contrasena);
             	printf("Nombre: %s \n",(*vClientes)[i].nom);
             	printf("Apellido: %s \n",(*vClientes)[i].apell);
             	printf("Direccion: %s \n",(*vClientes)[i].direccion);
             	printf("Localidad: %s \n",(*vClientes)[i].localidad);
             	printf("Provincia: %s \n",(*vClientes)[i].provincia);
             	printf("Email: %s \n",(*vClientes)[i].email);
             	printf("Cartera: %d \n",(*vClientes)[i].cartera);

             	puts("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\");
             	encontrado=1;//si encontrado esta en 1 es que se habrá encontrado el producto en la base de datos
       		}
		}
        if(encontrado==0){
			printf("\nEl ID no se encuentra en la base de datos\n");
		}
}

//Cabecera: void modificaPerfilC (CORRECTO)
void modificaPerfilC(cliente **vClientes, int *n,char *id){

int i,a,encontrado=0,new_cartera;
char new_id[10],new_con[30],new_email[30];

//printf("Introduce el ID de la categoria a la que desea modificar sus datos --> ");
//fflush(stdin);
//scanf("%s",&id);

for(i=0;i<(*n);i++){
    if(strcmp((*vClientes)[i].id,id)==0){
        encontrado=1;//si encontado=1 es porque se ha encontrado el dato en la estructura
        printf("Indique la accion que desea realizar:\n");//Preguntamos que cambio desea realizar el usuario
        puts("1 Cambiar el ID");
        puts("2 Cambiar la contrasena");
        puts("3 Cambiar el saldo de la cartera");
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
            strcpy((*vClientes)[i].id,new_id);
            break;
        case 2:
            printf("Introuce la nueva contrasena --> ");
            fflush(stdin);
            scanf("%s",&new_con);
            strcpy((*vClientes)[i].contrasena,new_con);
            break;
		case 3:
            printf("Introuce el nuevo saldo --> ");
            fflush(stdin);
            scanf("%d",&new_cartera);
            (*vClientes)[i].cartera=new_cartera;
            break;
		case 4:
            printf("Introuce el nuevo email --> ");
            fflush(stdin);
            scanf("%s",&new_email);
            strcpy((*vClientes)[i].email,new_email);
            break;
		}
    }
}
if(encontrado==0){puts("El ID introducido no se ha encontrado en la Base de datos");}

else{puts("Los datos han sido modificados correctamente");}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*int main(){
	char idprueba[10]="1";
	puts("Iniciamos ESIZONE-CLIENTES....\n");
	cargarClientes(&vClientes,&nClientes);

	MenuCliente(idprueba);

	puts("\nEl programa ha finalizado. Guardando datos....\n");
	imprimeClientes(vClientes,nClientes);

	printf("Hasta otra %s",idprueba);
	return 0;
}*/
