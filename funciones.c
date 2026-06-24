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
    if(map_search(r->lugares, nombre) != NULL)
    {
        printf("\nEl lugar \"%s\" ya existe en la red, no se puede agregar nuevamente.\n", nombre);
        return;
    }

    lugar* l=(lugar*)malloc(sizeof(lugar));
    strcpy(l->nombre, nombre);
    l->conexiones=list_create();

    map_insert(r->lugares, l->nombre, l);
    r->cantidad_actual++;
    puts("\nLugar agregado exitosamente");
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

    printf("\n");
    while (pair != NULL)
        {
            lugar* l = (lugar*) pair->value;

            printf("%s\n", l->nombre);

            pair = map_next(r->lugares);

        }
}

void agregarConexion(red* r, char* origen, char* destino, int tiempo, int costo, int num_transporte, char* nom_transporte){
    MapPair* pair = map_search(r->lugares, origen);
    MapPair* destinoPair = map_search(r->lugares, destino);
    if (pair == NULL) 
    {
        printf("\nLugar de origen no encontrado en la red\n");
        return;
    }

    if (destinoPair == NULL)
    {
        printf("\nLugar de destino no encontrado en la red\n");
        return;
    }

    if (strcmp(origen, destino) == 0)
    {
        printf("\nNo se puede agregar una conexion hacia el mismo lugar\n");
        return;
    }

    lugar* l_origen = (lugar*) pair->value;

    conexion* c=(conexion*)malloc(sizeof(conexion));
    strcpy(c->destino, destino); 
    c->tiempo=tiempo;
    c->costo=costo;
    c->transporte.numero=num_transporte;
    strcpy(c->transporte.nombre, nom_transporte);
    conexion* aux = list_first(l_origen->conexiones);
    for(int i=0; i<list_size(l_origen->conexiones); i++){
        if(strcmp(aux->destino, destino)==0){
            printf("\nYa existe una conexion desde %s hacia %s\n", origen, destino);
            return;
        }
        aux = list_next(l_origen->conexiones);
    }
    list_pushBack(l_origen->conexiones, c);
    puts("\nConexion agregada exitosamente");

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
            if (strcmp(c->destino, destino) == 0)
            {
                conexion* eliminada = list_popCurrent(l_origen->conexiones);
                
                free(eliminada);

                return;
            }
        
        c = list_next(l_origen->conexiones);
    }
}

void busquedaRapidez(red* r, char* origen, char* destino)
{

}

void busquedaEconomica (red* r, char* origen, char* destino)
{

}

void busquedaEquilibrada (red* r, char* origen, char* destino, double alpha)
{
    int maxTiempo = 0;
    int maxCosto = 0;

    // Recorrer todas las conexiones del grafo para encontrar el tiempo máximo y el costo máximo.
    
    MapPair* pair = map_first(r->lugares);

    while(pair != NULL)
    {
        lugar* l = (lugar*) pair->value;

        conexion* c = (conexion*) list_first(l->conexiones);

        while(c != NULL)
        {
            if(c->tiempo > maxTiempo)
            {
                maxTiempo = c->tiempo;
            }

            if(c->costo > maxCosto)
            {
                maxCosto = c->costo;
            }
            c = (conexion*) list_next(l->conexiones);
        }

        pair = map_next(r->lugares);
    }

    // Inicializar los valores de distancia, visitado y anterior para cada lugar en la red. 

    pair = map_first(r->lugares);

    while(pair != NULL)
    {
        lugar* l = (lugar*) pair->value;

        l->distancia = 999999999.0;
        l->visitado = 0;

        strcpy(l->anterior, "");

        pair = map_next(r->lugares);
    }

    MapPair* origenPair = map_search(r->lugares, origen);

    MapPair* destinoPair = map_search(r->lugares, destino);

    lugar* inicio = (lugar*) origenPair->value;

    inicio->distancia = 0;

    Heap* colaPrio = heap_create();

    heap_push(colaPrio, inicio, 0);

    // Para cada conexión calcular tiempo_norm y costo_norm, 
    // luego calcular el peso de la conexión usando la fórmula: peso = alpha * tiempo_norm + (1 - alpha) * costo_norm. 


    while(heap_top(colaPrio) != NULL)
    {
        lugar* actual = (lugar*) heap_top(colaPrio);

        heap_pop(colaPrio);

        if(actual->visitado == 1)
        {
            continue;
        }
        actual->visitado = 1;

        conexion* c = (conexion*) list_first(actual->conexiones);

        while(c != NULL)
        {
            MapPair* vecinoPair = map_search(r->lugares, c->destino);

            if(vecinoPair != NULL)
            {
                lugar* vecino = (lugar*) vecinoPair->value;

                double tiempoNorm = (double)c->tiempo / maxTiempo;

                double costoNorm = (double)c->costo / maxCosto;

                double peso = alpha * tiempoNorm + (1.0 - alpha) * costoNorm;

                double nuevaDist = actual->distancia + peso;

                if (nuevaDist < vecino->distancia)
                {
                    vecino->distancia = nuevaDist;

                    strcpy(vecino->anterior, actual->nombre);

                    heap_push(colaPrio, vecino, nuevaDist);
                }
            }

            c = (conexion*) list_next(actual->conexiones);
        }
    }

    // Destino final y verificación de si se encontró una ruta válida.

    lugar* fin = (lugar*) destinoPair->value;

    if(fin->distancia >= 999999999.0)
    {
        printf("\nNo existe ruta disponible\n");
        return;
    }

    int tiempoTotal = 0;
    int costoTotal = 0;

    // Muestra la ruta desde el destino hasta el origen usando la información de los lugares visitados y sus anteriores
    // Se usa una pila para almacenar la ruta y luego se imprime en orden desde el origen hasta el destino.

    Stack* ruta = stack_create(NULL);

    char actualNombre[30];

    strcpy(actualNombre, destino);

    while(strlen(actualNombre) > 0)
    {
        char* copia = (char*) malloc(30);

        strcpy(copia, actualNombre);

        stack_push(ruta, copia);

        MapPair* p = map_search(r->lugares, actualNombre);

        lugar* l = (lugar*) p->value;

        strcpy(actualNombre, l->anterior);
    }

    // Mostrar ruta encontrada y calcular tiempo total y costo total de la ruta.

    Stack* copiaRuta = stack_create(NULL);

    printf("\n===== RUTA ENCONTRADA =====\n");

    char* anterior = NULL;

    while(stack_top(ruta) != NULL)
    {
        char* nombre = (char*) stack_top(ruta);

        printf("%s", nombre);

        stack_push(copiaRuta, nombre);

        if(anterior != NULL)
        {
            MapPair* pair = map_search(r->lugares, anterior);

            if(pair != NULL)
            {
                lugar* l = (lugar*) pair->value;

                conexion* c = (conexion*) list_first(l->conexiones);

                while(c != NULL)
                {
                    if(strcmp(c->destino, nombre) == 0)
                    {
                        tiempoTotal += c->tiempo;
                        costoTotal += c->costo;
                        break;
                    }

                    c = (conexion*) list_next(l->conexiones);
                }
            }
        }

        anterior = nombre;

        stack_pop(ruta);

        if(stack_top(ruta) != NULL)
        {
            printf(" -> ");
        }
    }

    printf("\n");

    printf("\nTiempo total: %d minutos\n", tiempoTotal);

    printf("Costo total: $%d\n", costoTotal);

}

void generarGraphviz(red* r, char* nombreRed)
{
    if(r==NULL)return;
    if(r->cantidad_actual==0){
        printf("\nLa red \"%s\" esta vacia, no hay nada que graficar.\n", nombreRed);
        return;
        }

    /*Nombres de los archivos a generar, se sobreescriben en cada llamada,
    por lo que el grafo siempre refleja el estado actual de la red*/
    char archivoDot[100];
    char archivoPng[100];
    sprintf(archivoDot, "imagenes/%s.dot", nombreRed);
    sprintf(archivoPng, "imagenes/%s.png", nombreRed);

    FILE* f=fopen(archivoDot, "w");
    if(f==NULL){
        printf("\nNo se pudo crear el archivo %s\n", archivoDot);
        return;
        }

    fprintf(f, "digraph %s {\n", nombreRed);
    fprintf(f, "rankdir=LR;\n");
    fprintf(f, "node [shape=ellipse, style=filled, fillcolor=\"#cfe8ff\", fontname=\"Helvetica\"];\n");
    fprintf(f, "edge [fontname=\"Helvetica\", fontsize=10];\n\n");

//Se declaran todos los lugares como nodos
    MapPair* pair=map_first(r->lugares);
    while(pair != NULL){
        lugar* l=(lugar*)pair->value;
        fprintf(f, "\"%s\";\n", l->nombre);
        pair=map_next(r->lugares);
    }
    fprintf(f, "\n");

//Se recorren las conexiones de cada lugar y se generan las aristas
    pair=map_first(r->lugares);
    while(pair != NULL){
        lugar* l=(lugar*)pair->value;
        conexion* c=list_first(l->conexiones);
        while(c != NULL){
            fprintf(f, "\"%s\" -> \"%s\" [label=\"%d min\\n$%d\"];\n", l->nombre, c->destino, c->tiempo, c->costo);
            c=list_next(l->conexiones);
        }
        pair=map_next(r->lugares);
    }

    fprintf(f, "}\n");
    fclose(f);

//Se llama Graphviz para renderizar el .dot como imagen .png
    char comando[250];
    sprintf(comando, "dot -Tpng %s -o %s", archivoDot, archivoPng);

    int resultado=system(comando);

    if(resultado != 0){
        printf("\nNo se pudo generar la imagen. Verifica que Graphviz este instalado\n");
        printf("y agregado a las variables de entorno (PATH) del sistema.\n");
        return;
        }

 //Se abre automaticamente la imagen generada
    char comandoAbrir[250];
    sprintf(comandoAbrir, "start %s", archivoPng);
    int resultadoAbrir=system(comandoAbrir);
    if(resultadoAbrir != 0){
        printf("\nRed \"%s\" graficada correctamente, pero no se pudo abrir automaticamente.\n", nombreRed);
        printf("Puedes abrir el archivo manualmente: %s\n", archivoPng);
        }
    else printf("\nRed \"%s\" graficada correctamente (%s)\n", nombreRed, archivoPng);
}

