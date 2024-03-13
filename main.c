//Archivo .c Programado por --> Teodoro Sibón Jiménez y José Manuel Troya Valero

#include "admin.h"


///////////////////////////////////////FUNCION INICIO/////////////////////////////////////////////////////////////

//Cabecera: void MenuInicio 	(CORRECTO)
void MenuInicio(admin *vAdmins,int nAdmins,cliente *vClientes,int nClientes,prov *vProvs,int nProvs){

int i,error;
int existe=0;
char login[10];
char pass[15];

puts("\n-------------------BIENVENIDO AL MENU DE INICIO DE ESIZONE---------------------\n");
puts("Porfavor introduzca su usuario y contraseña\n");

do{
error=0;
printf("Login: ");
fflush(stdin);
scanf("%s",login);

printf("Contrasena: ");
fflush(stdin);
scanf("%s",pass);

for(i=0;i<(nAdmins);i++){		//Busca si eres admin
	if(strcmp((vAdmins)[i].id,login)==0) {
		existe=1;
		if(strcmp((vAdmins)[i].contrasena,pass)==0){
			puts("Correctamente redirigido a MenuAdmin");
			MenuAdmin(login);
		}else{
			puts("ERROR: Contraseña incorrecta.");
			error=1;
		}
	}

}

for(i=0;i<(nClientes);i++){		//Busca si eres cliente
	if(strcmp((vClientes)[i].id,login)==0) {
		existe=1;
		if(strcmp((vClientes)[i].contrasena,pass)==0){
			puts("Correctamente redirigido a MenuClientes");
			MenuCliente(login);
		}else{
			puts("ERROR: Contraseña incorrecta.");
			error=1;
		}
    }
}

for(i=0;i<(nProvs);i++){		//Busca si eres proveedor
    if(strcmp((vProvs)[i].id,login)==0) {
        existe=1;
        if(strcmp((vProvs)[i].contrasena,pass)==0){
            puts("Correctamente redirigido a MenuProv");
            MenuProv(login);
        }else{
            puts("ERROR: Contraseña incorrecta.");
            error=1;

        }
    }
}
if(existe==0){
    puts("El usuario no esta registrado en el sistema.");
}
}while(error==1);

system("pause");
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////FUNCIONES MENU ADMIN///////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
	puts("Iniciamos ESIZONE....\n");
	cargarAdmins(&vAdmins,&nAdmins);
	cargarClientes(&vClientes,&nClientes);
	cargarProvs(&vProvs,&nProvs);

	MenuInicio(vAdmins,nAdmins,vClientes,nClientes,vProvs,nProvs);

	puts("\nEl programa ha finalizado. Guardando datos....\n");
	imprimeAdmins(vAdmins,nAdmins);
	imprimeClientes(vClientes,nClientes);
	imprimeProvs(vProvs,nProvs);
	puts("\nHasta otra ocasion");
}
