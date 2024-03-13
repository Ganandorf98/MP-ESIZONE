

//Archivo .c Programado por --> José Manuel Troya Valero y Teodoro Sibón Jiménez

#include "admin.h"
#include "prod+categ.h"
#include "desc+dclient.h"

//////////////////////FUNCIONES DE CARGA Y ACTUALIZAR FICHERO/////////////

///////////////////////fUNCIONES DE CARGA//////////////////

//Cabecera: void cargarAdmins	(CORRECTO)
void cargarAdmins(admin **vAdmins,int *n){

FILE *fichero;
char linea[100];     // Guardará cada línea que leamos del fichero.
char *token;         // La variable token se usa para separar los datos del fichero

    *vAdmins=NULL;       //Deja en blanco todo el vector
    *n=0;

    fichero=fopen("Admin.txt","r");     //Abre el fichero en formato lectura
    if (fichero==NULL){
        puts("Error al abrir el fichero Admin.txt."); //Error de apertura
    }else{
        do{
          fgets(linea,100,fichero); //Lee la primera linea de fichero y la guarda en linea
          if (strcmp(linea,"\0")){
                *vAdmins=realloc((admin *)(*vAdmins),((*n)+1)*sizeof(admin));  //Reserva de memoria

                token=strtok(linea,"/");
                strcpy((*vAdmins)[*n].id,token);

                token=strtok(NULL,"/");
                strcpy((*vAdmins)[*n].contrasena,token);

                token=strtok(NULL,"/");
                strcpy((*vAdmins)[*n].nom,token);

                token=strtok(NULL,"\n");
                strcpy((*vAdmins)[*n].email,token);

                (*n)++;

            }

        }while(!feof(fichero));
    }
    fclose(fichero);
puts("Administradores cargados");
}

//Cabecera: void cargarClientes 	(CORRECTO)
void cargarClientes(cliente **vClientes,int *n){

FILE *fichero;
char linea[100];     // Guardará cada linea que leamos del fichero.
char *token;         // La variable token se usa para separar los datos del fichero

    *vClientes=NULL;       //Deja en blanco todo el vector
    *n=0;

    fichero=fopen("Cliente.txt","r");     //Abre el fichero en formato lectura
    if (fichero==NULL){
        puts("Error al abrir el fichero Cliente.txt."); //Error de apertura
    }else{
        do{
          fgets(linea,100,fichero); //Lee la primera linea de fichero y la guarda en linea
          if (strcmp(linea,"\0")){
                *vClientes=realloc((cliente *)(*vClientes),((*n)+1)*sizeof(cliente));  //Reserva de memoria

                token=strtok(linea,"/");
                strcpy((*vClientes)[*n].id,token);

                token=strtok(NULL,"/");
                strcpy((*vClientes)[*n].contrasena,token);

                token=strtok(NULL,"/");
                strcpy((*vClientes)[*n].nom,token);

                token=strtok(NULL,"/");
                strcpy((*vClientes)[*n].apell,token);

                token=strtok(NULL,"/");
                strcpy((*vClientes)[*n].direccion,token);

                token=strtok(NULL,"/");
                strcpy((*vClientes)[*n].localidad,token);

                token=strtok(NULL,"/");
                strcpy((*vClientes)[*n].provincia,token);

                token=strtok(NULL,"/");
                strcpy((*vClientes)[*n].email,token);

                token=strtok(NULL,"\n");
                (*vClientes)[*n].cartera=atoi(token);

                (*n)++;

            }

        }while(!feof(fichero));
    }
    fclose(fichero);
puts("Clientes cargados");
}

//Cabecera: void cargaProvs			(CORRECTO)
void cargarProvs(prov **vProvs,int *n){

FILE *fichero;
char linea[100];     // Guardará cada línea que leamos del fichero.
char *token;         // La variable token se usa para separar los datos del fichero

    *vProvs=NULL;       //Deja en blanco todo el vector
    *n=0;

    fichero=fopen("Prov.txt","r");     //Abre el fichero en formato lectura
    if (fichero==NULL){
        puts("Error al abrir el fichero Prov.txt."); //Error de apertura
    }else{
        do{
          fgets(linea,100,fichero); //Lee la primera linea de fichero y la guarda en linea
          if (strcmp(linea,"\0")){
                *vProvs=realloc((prov *)(*vProvs),((*n)+1)*sizeof(prov));  //Reserva de memoria

                token=strtok(linea,"/");
                 strcpy((*vProvs)[*n].id,token);

                token=strtok(NULL,"/");
                strcpy((*vProvs)[*n].contrasena,token);

                token=strtok(NULL,"/");
                strcpy((*vProvs)[*n].empresa,token);

                token=strtok(NULL,"/");
                strcpy((*vProvs)[*n].nom,token);

                token=strtok(NULL,"\n");
                strcpy((*vProvs)[*n].email,token);

                (*n)++;

            }

        }while(!feof(fichero));
    }
    fclose(fichero);
    puts("Proveedores cargados");
}


//Cabecera:void cargarDescuentos(descuento **vDescuento,int *n)
//Precondicion:La estructura vDescuento es de tipo descuento y n es de tipo entero
//Postcondicion:carga la estructura vDescuento con los datos del fichero "Descuentos.txt" y devuelve el numero de datos que hay en el vector vProducto
void cargarDescuentos(descuento **vDescuento,int *n){//(CORRECTO)


FILE *fichero;

char linea[100]; //Guardara la linea que leamos del fichero

char *token;    //La variable token se usa para separar los datos del fichero

        *vDescuento=NULL;//dejamos en blanco el vector
fichero=fopen("Descuentos.txt","r"); //Abre el fichero en formato lectura
if(fichero==NULL){puts("Error al abrir el fichero Productos.txt");}
else{
*n=0;

    do{
        fgets(linea,100,fichero); //Guardamos la primera linea de fichero y la guarda en linea
        if (strcmp(linea,"\0")){
                *vDescuento=realloc((descuento *)(*vDescuento),((*n)+1)*sizeof(descuento));  //Reserva de memoria

        //Guardamos identificador del codigo promocional en la estructura
        token=strtok(linea,"/");
        strcpy((*vDescuento)[*n].id_cod,token);


         //Guardamos La descripcion del descuento en la estructura
        token=strtok(NULL,"/");
        strcpy((*vDescuento)[*n].desc_desc,token);

        //Guardamos el tipo de codigo promocional en la estructura
        token=strtok(NULL,"/");
        strcpy((*vDescuento)[*n].tipo,token);


        //Guardamos el estado del descuetno en la estructura
        token=strtok(NULL,"/");
        strcpy((*vDescuento)[*n].estado,token);

        //Guardamos el importe del descuento en euros en la estructura
        token=strtok(NULL,"/");
        (*vDescuento)[*n].importe=atof(token); //Utilizo atof para convertir la cadena a flotante(utilizar ' . '  para los numeros)


        //Guardamos el estado del descuetno en la estructura
        token=strtok(NULL,"\n");
        strcpy((*vDescuento)[*n].aplic,token);

        (*n)++;

    }


  }while(!feof(fichero));
  puts("Los datos de los Descuentos  se han cargado correctamente\n");


 }fclose(fichero);
}

//Cabecera:int cargarProductos(producto **vproducto,int *n);
//Precondicion:------------
//Postcondicion:carga la estructura vproducto con los datos del fichero "Productos.txt" y devuelve el numero de datos que hay en el vector vProducto
void cargarProductos(producto **vProducto,int *n){


FILE *fichero;

char linea[100]; //Guardara la linea que leamos del fichero

char *token;    //La variable token se usa para separar los datos del fichero

        *vProducto=NULL;//dejamos en blanco el vector
fichero=fopen("Productos.txt","r"); //Abre el fichero en formato lectura
if(fichero==NULL){puts("Error al abrir el fichero Productos.txt");}
else{
*n=0;

    do{
        fgets(linea,100,fichero); //Guardamos la primera linea de fichero y la guarda en linea
        if (strcmp(linea,"\0")){
                *vProducto=realloc((producto *)(*vProducto),((*n)+1)*sizeof(producto));  //Reserva de memoria

        //Guardamos identificador de Producto en la estructura
        token=strtok(linea,"/");
        strcpy((*vProducto)[*n].id_prod,token);


        //Guardamos La descripcion del producto en la estructura
        token=strtok(NULL,"/");
        strcpy((*vProducto)[*n].desc_prod,token);

        //Guardamos el Id de la categoria en la estructura
        token=strtok(NULL,"/");
        strcpy((*vProducto)[*n].categ,token);

        //Guardamos el Id del gestor/proveedor del producto en la estructura
        token=strtok(NULL,"/");
        strcpy((*vProducto)[*n].gest,token);

        //Guardamos el stock del producto en la estructura
         token=strtok(NULL,"/");
        (*vProducto)[*n].stock=atoi(token);
        //Guardamos el compromiso de entrega(dias) en la estructura
        token=strtok(NULL,"/");
        (*vProducto)[*n].entrega=atoi(token);



        //Guardamos el importe del producto en euros en la estructura
        token=strtok(NULL,"\n");
        (*vProducto)[*n].precio=atof(token); //Utilizo atof para convertir la cadena a flotante(utilizar ' . '  para los numeros)

        (*n)++;

    }


  }while(!feof(fichero));
  puts("Los datos de productos se han cargado correctamente\n");


 }fclose(fichero);
}


//Cabecera:int cargarCategorias(categoria **vCategoria,int *n);
//Precondicion:------------
//Postcondicion:carga la estructura vCategoria con los datos del fichero "Categorias.txt" y devuelve el numero de datos que hay en el vector vCategoria
void cargarCategorias(categoria **vCategoria,int *n){
    FILE *fichero;

char linea[100]; //Guardara la linea que leamos del fichero

char *token;    //La variable token se usa para separar los datos del fichero

        *vCategoria=NULL;//dejamos en blanco el vector
fichero=fopen("Categorias.txt","r"); //Abre el fichero en formato lectura
if(fichero==NULL){puts("Error en la apertura del fichero Categorias.txt ");}
else{
*n=0;

    do{
        fgets(linea,100,fichero); //Guardamos la primera linea de fichero y la guarda en linea
        if (strcmp(linea,"\0")){
                *vCategoria=realloc((categoria *)(*vCategoria),((*n)+1)*sizeof(categoria));  //Reserva de memoria

            //Guardamos el identificador de categoria en la estructura
             token=strtok(linea,"/");
             strcpy((*vCategoria)[*n].id_categ,token);

             //Guardamos la descripción de categoria en la estructura
             token=strtok(NULL,"\n");
             strcpy((*vCategoria)[*n].des_categ,token);

             (*n)++;}

}while(!feof(fichero));
printf("Los datos de categorias se han cargado  correctamente\n");
}fclose(fichero);}
 //Cabecera: void cargarDesclient(desclient *vDesclient, int *n)
//Precondicion: La estructura vDesclient es de tipo  desclient y n es de tipo entero
//Postcondicion: carga en la estructura los datos del fichero Desclient.txt
void cargarDesclient(desclient **vDesclient, int *n){//(CORRECTO)
FILE *fichero;

char linea[100]; //Guardara la linea que leamos del fichero

char *token;    //La variable token se usa para separar los datos del fichero

        *vDesclient=NULL;//dejamos en blanco el vector
fichero=fopen("Desclient.txt","r"); //Abre el fichero en formato lectura
if(fichero==NULL){puts("\nError al abrir el fichero Desclient.txt");}
else{
*n=0;

    do{
        fgets(linea,100,fichero); //Guardamos la primera linea de fichero y la guarda en linea
        if (strcmp(linea,"\0")){
                *vDesclient=realloc((desclient *)(*vDesclient),((*n)+1)*sizeof(desclient));  //Reserva de memoria

        //Guardamos identificador del cliente en la estructura
        token=strtok(linea,"/");
        strcpy((*vDesclient)[*n].id_client,token);


         //Guardamos el id del codigo promocional
        token=strtok(NULL,"/");
        strcpy((*vDesclient)[*n].id_cod,token);

        //Guardamos la fecha de asignacion(sin formato)  *Se lo daremos cuando lo mostremos por pantalla*
        token=strtok(NULL,"/");
        strcpy((*vDesclient)[*n].fech_asig,token);


        //Guardamos la fecha de caducidad(sin formato)  *Se lo daremos cuando lo mostremos por pantalla*
        token=strtok(NULL,"/");
        strcpy((*vDesclient)[*n].fech_cad,token);

        //Guardamos el estado (activo/no activo)
        token=strtok(NULL,"\n");
        strcpy((*vDesclient)[*n].estado,token); //Utilizo atof para convertir la cadena a flotante(utilizar ' . '  para los numeros)


        (*n)++;

    }


  }while(!feof(fichero));
  puts("Los datos de los Descuentos de clientes  se han cargado correctamente\n");


 }fclose(fichero);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////FUNCIONES IMPRIME////////////////////////////////////////////////////////////////////

//Cabecera: void imprimeAdmins 	(CORRECTO)
void imprimeAdmins(admin *vAdmins, size_t tam){
    FILE *fichero;
    int i;

    //Escribe en el fichero toda la ristra de usuario

    fichero=fopen("Admin.txt","w+");
    i=0;
    if (fichero==NULL)
            puts("Error al abrir el fichero Admin.txt");
        else{
            while(i<tam-1){                                    // recorremos el vector de productos
                fprintf( fichero,"%s/%s/%s/%s\n", vAdmins[i].id, vAdmins[i].contrasena, vAdmins[i].nom, vAdmins[i].email);          // impr en el fichero linea por linea
                i++;}
            fprintf(fichero, "%s/%s/%s/%s", vAdmins[i].id, vAdmins[i].contrasena, vAdmins[i].nom, vAdmins[i].email);
        puts("Los Administradores se han guardado correctamente en el fichero");}
        fclose(fichero);

}

//Cabecera: void imprimeClientes (CORRECTO)
void imprimeClientes(cliente *vClientes,size_t tam){

FILE *fichero;
int i;
//Escribe en el fichero todos los datos que se encuentran en la estructura
fichero=fopen("Cliente.txt","w+");
i=0;

	if (fichero==NULL){
		puts("Error en la apertura del fichero Cliente.txt ");
	}
    else{
        while(i<tam-1){                                    // recorremos el vector de productos
            fprintf( fichero,"%s/%s/%s/%s/%s/%s/%s/%s/%d\n", vClientes[i].id, vClientes[i].contrasena, vClientes[i].nom, vClientes[i].apell, vClientes[i].direccion, vClientes[i].localidad, vClientes[i].provincia, vClientes[i].email ,vClientes[i].cartera);   // imprimo en el fichero linea por linea
            i++;
		}
        fprintf( fichero,"%s/%s/%s/%s/%s/%s/%s/%s/%d", vClientes[i].id, vClientes[i].contrasena, vClientes[i].nom, vClientes[i].apell, vClientes[i].direccion, vClientes[i].localidad, vClientes[i].provincia, vClientes[i].email ,vClientes[i].cartera);//La ultima linea se guarda fuera del bucle
        puts("Los Clientes se han guardado correctamente en el fichero");
	}
	fclose(fichero);
}

//Cabecera: void imprimeProvs	(CORRECTO)
void imprimeProvs(prov *vProvs,size_t tam){
FILE *fichero;
int i;
//Escribe en el fichero todos los datos que se encuentran en la estructura
fichero=fopen("Prov.txt","w+");
i=0;

	if (fichero==NULL){
		puts("Error en la apertura del fichero Prov.txt ");
	}
    else{
        while(i<tam-1){                                    // recorremos el vector de productos
            fprintf( fichero,"%s/%s/%s/%s/%s\n", vProvs[i].id, vProvs[i].contrasena, vProvs[i].empresa, vProvs[i].nom, vProvs[i].email);   // imprimo en el fichero linea por linea
            i++;
		}
        fprintf( fichero,"%s/%s/%s/%s/%s", vProvs[i].id, vProvs[i].contrasena, vProvs[i].empresa, vProvs[i].nom, vProvs[i].email);//La ultima linea se guarda fuera del bucle
        puts("Los Proveedores se han guardado correctamente en el fichero");
	}
	fclose(fichero);
}

//Cabecera: void imprimeDesclient(desclient *vDesclient,  size_t n)
//Precondicion: La estructura vDesclient es de tipo  desclient y n es de tipo size_t y ambas deben estar inicalizadas
//Postcondicion: devuelve los datos de la estructura al fichero
void imprimeDesclient(desclient *vDesclient,  size_t tam){//(CORRECTO)
FILE *fichero;
int i;
//Escribe en el fichero todos los datos que se encuentran en la estructura
fichero=fopen("Desclient.txt","w+");
i=0;
if (fichero==NULL){puts("Error en la apertura del fichero Descuentos.txt ");}
        else{
            while(i<tam-1){                                    // recorremos el vector de productos
               fprintf( fichero,"%s/%s/%s/%s/%s\n", vDesclient[i].id_client, vDesclient[i].id_cod,vDesclient[i].fech_asig,vDesclient[i].fech_cad,vDesclient[i].estado);   // imprimo en el fichero linea por linea
                 i++;}
            fprintf( fichero,"%s/%s/%s/%s/%s", vDesclient[i].id_client, vDesclient[i].id_cod,vDesclient[i].fech_asig,vDesclient[i].fech_cad,vDesclient[i].estado);  //La ultima linea se guarda fuera del bucle
        puts("Los datos se han guardado correctamente en el fichero Desclient.txt");}


fclose(fichero);
}

//Cabecera:void imprimeDescuentos(descuento *vDescuento,size_t tam)
//Precondicion: La estructura vDescuento es de tipo descuento y tam es de tipo size_t ambas deben estar inicializadas
//Postcondicion:Devuelve el contenido de la estructura en el fichero
void imprimeDescuentos(descuento *vDescuento,size_t tam){//(CORRECTO)
FILE *fichero;
int i;

    //Escribe en el fichero todos los datos que se encuentran en la estructura
fichero=fopen("Descuentos.txt","w+");
i=0;
if (fichero==NULL){puts("Error en la apertura del fichero Descuentos.txt ");}
        else{
            while(i<tam-1){                                    // recorremos el vector de productos
               fprintf( fichero,"%s/%s/%s/%s/%f/%s\n", vDescuento[i].id_cod, vDescuento[i].desc_desc,vDescuento[i].tipo,vDescuento[i].estado,vDescuento[i].importe,vDescuento[i].aplic);   // imprimo en el fichero linea por linea
                 i++;}
            fprintf( fichero,"%s/%s/%s/%s/%f/%s", vDescuento[i].id_cod, vDescuento[i].desc_desc,vDescuento[i].tipo,vDescuento[i].estado,vDescuento[i].importe,vDescuento[i].aplic); //La ultima linea se guarda fuera del bucle
        puts("Los datos se han guardado correctamente en el fichero Descuentos.txt");}
fclose(fichero);
}


//Cabecera:void imprimeCategorias(categoria **vCategoria,int *n)
//Precondicion: La estructura vCategoria es de tipo categoria y tam es de tipo size_t ambas deben estar inicializadas
//Postcondicion:Devuelve el contenido de la estructura en el fichero
void imprimeCategorias(categoria *vCategoria,size_t tam){
FILE *fichero;
int i;

    //Escribe en el fichero todos los datos que se encuentran en la estructura
fichero=fopen("Categorias.txt","w+");
i=0;
if (fichero==NULL){puts("Error en la apertura del fichero Categorias.txt ");}
        else{
            while(i<tam-1){                                    // recorremos el vector de productos
                fprintf( fichero,"%s/%s\n", vCategoria[i].id_categ, vCategoria[i].des_categ);   // imprimo en el fichero linea por linea
                 i++;}
            fprintf( fichero,"%s/%s", vCategoria[i].id_categ, vCategoria[i].des_categ);//La ultima linea se guarda fuera del bucle
        puts("Las categorias se han guardado correctamente en el fichero");}
        fclose(fichero);
}

//Cabecera:void imprimeProducros(producto **vproducto,int *n)
//Precondicion: La estructura vproducto es de tipo producto y el entero n deben estar inicializados
//Postcondicion:Devuelve el contenido de la estructura en el fichero
void imprimeProductos(producto *vProducto, size_t tam){
    FILE *fichero;
    int i;

    //Escribe en el fichero toda la ristra de usuario

    fichero=fopen("Productos.txt","w+");
    i=0;
    if (fichero==NULL)
            puts("No se ha podido modificar el fichero");
        else{
            while(i<tam-1){                                    // recorremos el vector de productos
                fprintf( fichero,"%s/%s/%s/%s/%d/%d/%.2f\n", vProducto[i].id_prod, vProducto[i].desc_prod, vProducto[i].categ, vProducto[i].gest, vProducto[i].stock, vProducto[i].entrega, vProducto[i].precio );          // impr en el fichero linea por linea
                i++;}
            fprintf(fichero, "%s/%s/%s/%s/%d/%d/%.2f", vProducto[i].id_prod, vProducto[i].desc_prod, vProducto[i].categ, vProducto[i].gest, vProducto[i].stock, vProducto[i].entrega, vProducto[i].precio );
        puts("Los productos se han guardado correctamente en el fichero");}
        fclose(fichero);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////







///////////////////////////////////////////////////////////////////////////
