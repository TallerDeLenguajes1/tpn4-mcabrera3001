//Ultimo trabajo 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
    int ProductoID;
    int Cantidad;
    char * TipoProducto;
    float PrecioUnitario;
}Producto;

typedef struct {
    int ClienteID;
    char * NombreCliente;
    int CantidadProductosAPedir;
    Producto * Productos; 
}Cliente;

typedef struct {
    int *TareaID;
    char *Descripcion;
    int Duracion;
}Tarea;

char * TiposProductos [] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebibas"};

//Prototipo de Funciones

float costoProducto(Producto productos);
void mostrar(Cliente ** clientela, int cantidadClientes);
Producto cargarProducto ();
void mostrarTareas(Tarea ** tRealizado, Tarea ** tPendiente, int contador, int totalTareas);
//Tarea BuscarPorId (Tarea ** busquedaPend, Tarea ** busquedaReal, int cantidadT, int cantidadR);
Tarea BuscarTarea(Tarea ** tareaRealiz, int contador);

int main () 
{
    srand(time(NULL));
    int cantTareas;
    
    /*int cantClientes;
    char nombre[20];
    int cantProducto;
    float costoParcial;
    printf("Digite la cantidad de clientes: ");
    scanf("%d", &cantClientes);
    Cliente * puntCliente = (Cliente *)malloc(sizeof(Cliente)*cantClientes);
    for (int i=0; i<cantClientes; i++) {
        //Datos del Cliente
        puntCliente[i].ClienteID = i;
        printf("Nombre Cliente: ");
        scanf("%s", &nombre);
        fflush(stdin);
        int tamaNombre = strlen(nombre);
        puntCliente[i].NombreCliente = (char *)malloc(sizeof(tamaNombre));
        strcpy(puntCliente[i].NombreCliente, nombre);
        puntCliente[i].CantidadProductosAPedir = 1 + rand()%5;
        //Datos del Producto
        puntCliente[i].Productos = (Producto *)malloc(sizeof(Producto)*puntCliente[i].CantidadProductosAPedir);
        for(int j=0; j<puntCliente[i].CantidadProductosAPedir;j++) {
            (puntCliente[i].Productos)[j] = cargarProducto();
            costoParcial = costoProducto(((puntCliente[i].Productos)[j]));
        }
    }
    mostrar(&puntCliente, cantClientes);*/

    printf("Ingrese la cantidad de tareas a cargar: ");
    scanf("%d", &cantTareas);
    int n;
    char nombreTarea[30];
    int cantPend;
    int cantRzdo;
    char respuesta;
    int contadorTareas = 0;
    Tarea *TareasPendientes = (Tarea *)malloc(sizeof(Tarea)*cantTareas);

    //se crean las tareas pendientes
    for(n=0; n<cantTareas; n++) {
        TareasPendientes[n].TareaID = (int *)malloc(sizeof(int));
        *(TareasPendientes[n].TareaID) = n;
        printf("ID Tarea: %d\n", *(TareasPendientes[n].TareaID));
        printf("Tarea a Cargar: ");
        scanf("%s", &nombreTarea);
        fflush(stdin);
        //no considera los espacios y cuenta solo hasta el espacio en blanco
        cantPend = strlen(nombreTarea);
        TareasPendientes[n].Descripcion = (char *)malloc(sizeof(cantPend));
        strcpy(TareasPendientes[n].Descripcion, nombreTarea);
        TareasPendientes[n].Duracion = 10 + rand()%90;
    }

    //se pregunta si la tarea esta realizada
    Tarea *TareasRealizadas = (Tarea *)malloc(sizeof(Tarea)*cantTareas);
    for(n=0;n<cantTareas; n++) {
        printf("Se realizo la tarea %s (Conteste y(SI) o n(NO))?\n", TareasPendientes[n].Descripcion);
        scanf("%c", &respuesta);
        fflush(stdin);
        if (respuesta == 'y') {
            TareasRealizadas[contadorTareas].TareaID = TareasPendientes[n].TareaID;
            cantRzdo = strlen(TareasPendientes[n].Descripcion);
            TareasRealizadas[contadorTareas].Descripcion = (char *)malloc(sizeof(char)*cantRzdo);
            strcpy(TareasRealizadas[contadorTareas].Descripcion, TareasPendientes[n].Descripcion);
            TareasRealizadas[contadorTareas].Duracion = TareasPendientes[n].Duracion;
            contadorTareas = contadorTareas + 1;
            TareasPendientes[n].TareaID = NULL; //aca tendria que apuntar a NULL

        }
        
    }


    //mostrarTareas (&TareasRealizadas, &TareasPendientes, contadorTareas, cantTareas);

    /*Tarea encontrado = BuscarPorId(&TareasPendientes, &TareasRealizadas, cantTareas, contadorTareas);
    printf("Tarea ID: %d\n", *(encontrado).TareaID);
    printf("Descripcion Tarea: %s\n", encontrado.Descripcion);
    printf("Duracion de Tarea: %d\n\n", encontrado.Duracion);
    
    Tarea busquedaLetra = BuscarPorPalabra(&TareasPendientes, cantTareas);
    printf("Tarea ID: %d\n", *(busquedaLetra.TareaID)); falla porque deberia enviar tambien como parametro las tareas realizadas
    printf("Descripcion Tarea: %s\n", busquedaLetra.Descripcion);*/
    
    getchar();
    return 0;
}

//Calcula el costo de cada producto
float costoProducto(Producto productos) {
    float Total= 0;
     return Total = (productos.PrecioUnitario * productos.Cantidad);
}

void mostrar(Cliente ** clientela, int cantidadClientes) {
    Cliente * cliente = * clientela;
    float costoParcial;
    float suma;
    for(int i=0; i<cantidadClientes;i++) {
        printf("\nID Cliente: %d\n", cliente[i].ClienteID);
        printf("Nombre del Cliente: %s\n", cliente[i].NombreCliente);
        printf("Cantidad de Productos a Pedir: %d\n\n", cliente[i].CantidadProductosAPedir);
            for(int j=0; j<cliente[i].CantidadProductosAPedir;j++) {
                printf("ID Producto: %d\n", (cliente[i].Productos)[j].ProductoID);
                printf("Cantidad a Pedir: %d\n", (cliente[i].Productos)[j].Cantidad);
                printf("Tipo Producto: %s\n", (cliente[i].Productos)[j].TipoProducto);
                printf("Precio Unitario: %.2f\n", (cliente[i].Productos)[j].PrecioUnitario);
                costoParcial = costoProducto(((cliente[i].Productos)[j]));
                printf("Costo del Producto: %.2f\n\n", costoParcial);
                suma = suma + ((cliente[i].Productos)[j].PrecioUnitario * (cliente[i].Productos)[j].Cantidad);
            }
    }
    printf("Total a Pagar: %.2f", suma);
}

Producto cargarProducto () {
    
    Producto nuevoProducto;
    nuevoProducto.ProductoID = rand()%5;
    nuevoProducto.Cantidad = 1 + rand()%9;
    int cantCaractProd = strlen(TiposProductos[nuevoProducto.ProductoID]);
    nuevoProducto.TipoProducto = (char *)malloc(sizeof(char)*cantCaractProd);
    strcpy(nuevoProducto.TipoProducto, TiposProductos[nuevoProducto.ProductoID]);
    nuevoProducto.PrecioUnitario = 1+rand()%99;

    return nuevoProducto;
}

void mostrarTareas(Tarea ** tRealizado, Tarea ** tPendiente, int contador, int totalTareas) {
    Tarea * tareaReal = *tRealizado;
    Tarea * tareaPend = *tPendiente;
    int i = 0;
    printf("\r###Tareas Realizadas###\n");
    for( i=0; i<contador;i++){
        printf("ID tarea: %d\n", tareaReal[i].TareaID);
        printf("Descripcion Tarea: %s\n", tareaReal[i].Descripcion);
    }

    printf("\n\r###Tareas Pendientes###\n");
    for(i=0; i<totalTareas; i++) {
        if(tareaPend[i].TareaID = NULL) {
            printf("ID Tarea Pendiente: %d\n", tareaPend[i].TareaID);
            printf("Descripcion Tarea Pendiente: %s\n", tareaPend[i].Descripcion);
        }
    }
}

Tarea BuscarTarea(Tarea ** tareaRealiz, int contador) { //contador contiene la cantidad total de tareas
    Tarea * tarReal = (Tarea *)malloc(sizeof(Tarea));
    tarReal = *tareaRealiz;
    char letra;
    printf("Ingrese una letra: ");
    scanf("%c", &letra);
    fflush(stdin);
    for (int i = 0; i < contador; i++){
        int cantLetras = strlen(tarReal[i].Descripcion);
        for(int j=0;j<cantLetras; j++) {
            if((tarReal[i].Descripcion)[j] == letra) {
                return tarReal[i]; //TAREA REALIZADA [i]
            }
        }
    }
}