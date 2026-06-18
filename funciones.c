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

void eliminarLugar (red* r, char* nombre)
{
    MapPair* pair = map_search(r->lugares, nombre);

    while (pair == NULL)
    {
         return;
    }

    lugar* l = pair->value;

    conexion* c = list_popFront(l->conexiones);

    while (c != NULL)
        {
            free(c);

            c = (conexion*) list_popFront(l->conexiones);
        }
    
    MapPair* eliminado = map_remove(r->lugares, nombre);

    free(l->conexiones);

    free(l);

    if (eliminado == NULL)
    {
        free(eliminado);
    }

    r->cantidad_actual--;
}

void mostrarLugares (red* r)
{
    MapPair* pair = map_first(r->lugares);

    while (pair != NULL)
        {
            lugar* l = (lugar*) pair->value;

            printf("%s\n", l->nombre);

            pair = map_next(r->lugares);

        }
}

void agregarConexion(red* r, char* origen, char* destino, int tiempo, int costo, int num_transporte, char* nom_transporte){
    MapPair* pair = map_search(r->lugares, origen);
    
    if (pair == NULL) return;

    lugar* l_origen = (lugar*) pair->value;

    conexion* c=(conexion*)malloc(sizeof(conexion));
    strcpy(c->origen, destino); //Origen desde la perspectiva del nodo es el destino
    c->tiempo=tiempo;
    c->costo=costo;
    c->transporte.numero=num_transporte;
    strcpy(c->transporte.nombre, nom_transporte);

    list_pushBack(l_origen->conexiones, c);
}

void eliminarConexion(red* r, char* origen, char* destino)
{
    MapPair* pair = map_search(r->lugares, origen);

    if (pair == NULL) return;
    
    lugar* l_origen= (lugar*) pair-> value;

    if(l_origen == NULL)
    {
        return;
    }

    conexion * c = list_first(l_origen->conexiones);

    while (c != NULL)
    {
            if (strcmp(c->origen, destino) == 0)
            {
                conexion* eliminada = list_popCurrent(l_origen->conexiones);
                
                free(eliminada);

                return;
            }
        
        c = next_list(l_origen->conexiones);
    }
}



