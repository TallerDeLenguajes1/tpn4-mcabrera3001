#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Tareas {
    int TareaID;
    char *Descripcion;
    int Duracion;
}Tarea;

typedef struct TNodo {
    Tarea actividades;
    TNodo *siguiente;
}Nodo;

void menu (Nodo * inicioPendientes, Nodo * inicioRealizadas, int id);
Nodo * crearLista();
Nodo * insertar(Nodo ** inicioLista, int id);
void mostrar(Nodo ** inicioPendientes, Nodo ** inicioRealizadas);
void modificar(Nodo ** inicioPendientes, Nodo ** inicioRealizadas);
void borrar(Nodo ** inicioLista);

int main () {
    int cant_actividades = 0;
    int identificador = 0;
    Nodo *TareasPendientes = crearLista(); //se crea una lista vacia...
    Nodo *TareasRealizadas = crearLista();

    menu(TareasPendientes, TareasRealizadas, identificador);

    getchar();
    return 0;
}

void menu (Nodo * inicioPendientes, Nodo * inicioRealizadas, int id) {
    int opcion;
    //Nodo *inicioTareasPendientes = inicioPendientes;
    //Nodo *inicioTareasRealizadas = inicioRealizadas;

    do{
        printf("\n\t...Listado de Tareas...\n");
		printf("1.Agregar Tarea\n");
        printf("2.Mostrar Tareas Realizadas y Pendientes\n");
		printf("3.Modificar Tarea\n");
		printf("4.Borrar Tarea\n");
		printf("5.Salir\n");
        printf("Opcion: ");
		scanf("%d", &opcion);
        fflush(stdin);

        switch(opcion) {
            case 1: {
                Nodo * nuevoNodo = insertar(&inicioPendientes, id);
                id = id+1;
                break;
            }
            case 2: {
                mostrar(&inicioPendientes, &inicioRealizadas);
                break;
            }
            case 3: {
                modificar(&inicioPendientes, &inicioRealizadas);
            }
        }
    }while(opcion != 5);
}

Nodo * crearLista() {
    Nodo *L = NULL;
    return L;
}

Nodo * insertar(Nodo ** inicioLista, int id) {
    char nombreTarea[20];
    int cantLetras;
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->actividades.TareaID = id;//cant_actividades + 1;

    printf("Ingrese la tarea a cargar: ");
    gets(nombreTarea);
    fflush(stdin);
    cantLetras = strlen(nombreTarea);
    nuevo->actividades.Descripcion = (char *)malloc(sizeof(char)*cantLetras);
    strcpy(nuevo->actividades.Descripcion, nombreTarea);
    nuevo->actividades.Duracion = 10 + rand()%90;

    nuevo->siguiente = *inicioLista;
    *inicioLista = nuevo;

    return nuevo;
}

void mostrar(Nodo ** inicioPendientes, Nodo ** inicioRealizadas) {
    Nodo *mostrarRealizadas = *inicioRealizadas;
    Nodo *mostrarPendientes = *inicioPendientes; 
    printf("\nInicio Pendientes: %p\n", inicioPendientes);
    printf("mostrarPendientes: %p\n", mostrarPendientes);

        while(mostrarRealizadas) {
            printf("\n\tTareas Realizadas\n");
            printf("Tarea ID: %d\n", mostrarRealizadas->actividades.TareaID);
            printf("Descripcion Tarea: %s\n", mostrarRealizadas->actividades.Descripcion);
            printf("Duracion de Tarea: %d\n\n", mostrarRealizadas->actividades.Duracion);
            mostrarRealizadas = mostrarRealizadas->siguiente;
        }
        
        while(mostrarPendientes) {
            printf("\n\tTareas Pendientes\n");
            printf("Tarea ID: %d\n", mostrarPendientes->actividades.TareaID);
            printf("Descripcion Tarea: %s\n", mostrarPendientes->actividades.Descripcion);
            printf("Duracion de Tarea: %d\n", mostrarPendientes->actividades.Duracion);
            mostrarPendientes = mostrarPendientes->siguiente;
        }
}

void borrar(Nodo ** inicioPendientes) {
    Nodo *Aux = *inicioPendientes;
    Nodo *AuxAnterior;

    while (Aux  ) { // serviria para borrar un nodo de la lista
        AuxAnterior = Aux;
        Aux = Aux->siguiente;
    }
    if(Aux){
        AuxAnterior->siguiente = Aux->siguiente;
        free(Aux);
        Aux = NULL;
    } 
}

void modificar(Nodo ** inicioPendientes, Nodo ** inicioRealizadas) {

    Nodo *AuxPend = *inicioPendientes;
    Nodo *AuxAnteriorPend;
    
    Nodo *AuxRealizada = *inicioRealizadas;
    Nodo *AuxAnteriorRealizada;

    char modificarTarea[20];
    printf("Tarea a modificar: "); //modificar significa convertirla en tarea realizada
    gets(modificarTarea);

    while (AuxPend && (strcmp(AuxPend->actividades.Descripcion, modificarTarea) != 0)) { //si comparo tipos INT si funciona pero no con CHAR
        AuxAnteriorPend = AuxPend;
        AuxPend = AuxPend->siguiente;
    }
    if(AuxPend) {
        while (AuxRealizada) { //busco el ultimo nodo para copiar la tarea pendiente en la tarea realizada.
            AuxAnteriorRealizada = AuxRealizada;
            AuxRealizada = AuxRealizada->siguiente;
        }
        if(AuxRealizada == NULL) {
            int cantLetras; 
            AuxRealizada = (Nodo *)malloc(sizeof(Nodo));
            AuxRealizada->actividades.TareaID = AuxPend->actividades.TareaID;

            cantLetras = strlen(AuxPend->actividades.Descripcion);
            AuxRealizada->actividades.Descripcion = (char *)malloc(sizeof(char)*cantLetras);
            strcpy(AuxRealizada->actividades.Descripcion, AuxPend->actividades.Descripcion);
            AuxRealizada->actividades.Duracion = AuxPend->actividades.Duracion;

            
            AuxRealizada->siguiente = *inicioRealizadas;
            *inicioRealizadas = AuxRealizada;

            AuxAnteriorPend->siguiente = AuxPend->siguiente;

            free(AuxPend);
            AuxPend = NULL;
        }
        
    } else {
        printf("No existe la tarea solicitada");
    }
}

