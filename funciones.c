#include "funciones.h"

red* crearRed(int capacidad_maxima){
    red* r=(red*)malloc(sizeof(red));
    r->lugares=map_create(is_equal_string);
    r->cantidad_actual=0;
    r->capacidad_maxima=capacidad_maxima;
    return r;
}

void agregarLugar(red* r, char* nombre){
    if(r->cantidad_actual>=r->capacidad_maxima)return;
    if(map_search(r->lugares, nombre) != NULL)return;

    lugar* l=(lugar*)malloc(sizeof(lugar));
    strcpy(l->nombre, nombre);
    l->conexiones=list_create();

    map_insert(r->lugares, l->nombre, l);
    r->cantidad_actual++;
}

void agregarConexion(red* r, char* origen, char* destino, int tiempo, int costo, int num_transporte, char* nom_transporte){
    lugar* l_origen=(lugar*)map_search(r->lugares, origen);
    if(l_origen==NULL)return;

    conexion* c=(conexion*)malloc(sizeof(conexion));
    strcpy(c->origen, destino); //Origen desde la perspectiva del nodo es el destino
    c->tiempo=tiempo;
    c->costo=costo;
    c->transporte.numero=num_transporte;
    strcpy(c->transporte.nombre, nom_transporte);

    list_pushBack(l_origen->conexiones, c);
}



