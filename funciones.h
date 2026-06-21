#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "tdas/list.h"
#include "tdas/heap.h"
#include "tdas/extra.h"
#include "tdas/stack.h"
#include "tdas/queue.h"
#include "tdas/map.h"

//Structs 
typedef struct {
    int numero;
    char nombre[20];
} tipoTransporte; 

typedef struct {
    char destino[30];
    int tiempo;
    int costo;
    tipoTransporte transporte;
} conexion;

typedef struct {
    char nombre[30];
    List* conexiones;
} lugar;

typedef struct {
    Map* lugares;
    int cantidad_actual; 
    int capacidad_maxima;
} red;

//Funciones

//Creación del mapa

red* crearRed(int capacidad_maxima);

//Funciones con respecto a lugares

void agregarLugar(red* r, char* nombre);
void eliminarLugar(red *r, char* nombre);
void mostrarLugares(red *r);

//Funciones con respecto a las conexiones

void agregarConexion(red* r, char* origen, char* destino, int tiempo, int costo, int num_transporte, char* nom_transporte);
void eliminarConexion(red* r, char* origen, char* destino);

//Busquedas por filtros

void busquedaRapidez(red* r, char* origen, char* destino, int tiempo, int costo, int num_transporte, char* nom_transporte);
void busquedaEconomica (red* r, char* origen, char* destino, int tiempo, int costo, int num_transporte, char* nom_transporte);
void busquedaMixta (red* r, char* origen, char* destino, int tiempo, int costo, int num_transporte, char* nom_transporte);

// Función para mostrar la red de transporte

void generarGraphviz(red* r, char* nombreRed);

#endif
