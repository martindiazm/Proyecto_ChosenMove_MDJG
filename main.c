#include <stdio.h>
#include <stdlib.h>
#include "tdas/list.h"
#include "tdas/heap.h"
#include "tdas/extra.h"
#include "tdas/stack.h"
#include "tdas/queue.h"
#include "tdas/map.h"
#include <string.h>
#include <time.h>

// Definición de los structs 

typedef struct
{
    int numero;
    char nombre[20];
} tipoTransporte; 


typedef struct
{
    char origen[30];
    int tiempo;
    int costo;
    tipoTransporte transporte;
} conexion;

typedef struct
{
    char nombre[30];
    List* conexiones;
} lugar;

typedef struct
{
    Map* lugares;
    int cantidad_actual; 
    int capacidad_maxima;
} red;


// Definición de las funciones 

/* Para no complicarnos tanto con las conexiones del grafo podemos crear 4 grafos

red_caminando
red_metro
red_micro
red_colectivo

Así hacemos que de un punto A a un punto B haya solo una conexión y no 4 al mismo tiempo,
aunque esto tambien limita nuestro programa a solo 1 transporte por viaje, es decir no se pueden hacer combinaciones como
De punto A a punto B (caminando), de punto B a punto C (micro), de punto C a punto D (metro)
y si lo hacemos va a ser bastante más complejo xd
*\

// Definición de las funciones 

/* 
BUSCAR RUTA:
El programa le pide:
Origen: El usuario escribe el nombre del lugar de partida y presiona Enter. Si el lugar no existe en la red, el programa muestra "Lugar de origen no encontrado" y vuelve al menú.

Destino: El usuario escribe el nombre del lugar de llegada y presiona Enter. Si el lugar no existe, el programa muestra "Lugar de destino no encontrado" y vuelve al menú.

Tipo de transporte: El programa muestra las opciones disponibles (1. Caminando, 2. Metro, 3. Micro, 4. Colectivo). El usuario escribe el número del medio de transporte deseado.

Criterio de búsqueda: El programa muestra las tres opciones (1. Más rápida, 2. Más económica, 3. Mejor equilibrio). El usuario escribe el número del criterio.

El programa calcula la ruta y muestra en pantalla la secuencia de lugares a recorrer, el tiempo total estimado y el costo total. Si no existe ningún camino posible con el transporte seleccionado, muestra "No se encontró una ruta disponible entre los lugares indicados". Al terminar, se regresa automáticamente al menú principal.


GESTIONAR LUGARES:

Agregar lugar: El usuario escribe 1. El programa le pide ingresar el nombre del nuevo lugar. El usuario escribe el nombre y presiona Enter. Si el nombre ya existe en la red, muestra "El lugar ya está registrado". Si la red alcanzó su capacidad máxima, muestra "No se pueden agregar más lugares". Si todo es correcto, muestra "Lugar agregado exitosamente" y vuelve al submenú.

Eliminar lugar: El usuario escribe 2. El programa le pide el nombre del lugar a eliminar. Si el lugar no existe, muestra "Lugar no encontrado". Si existe, lo elimina junto con todas sus conexiones y muestra "Lugar eliminado correctamente", luego vuelve al submenú.

Mostrar lista de lugares: El usuario escribe 3. El programa imprime en pantalla todos los lugares actualmente registrados, uno por línea. Si no hay ninguno, muestra "La red está vacía". Luego vuelve al submenú.


GESTIONAR CONEXIONES:

Agregar conexión: El usuario escribe 1. El programa solicita en orden:

- Nombre del lugar de origen.
- Nombre del lugar de destino.
- Tiempo del viaje en minutos (número entero).
- Costo del viaje (número entero).
- Tipo de transporte (muestra el menú con las opciones numeradas).

Si alguno de los lugares no existe, muestra "Lugar no encontrado". Si ya existe una conexión entre esos dos lugares, muestra "La conexión ya existe". Si todo es correcto, muestra "Conexión agregada exitosamente" y vuelve al submenú.

Eliminar conexión: El usuario escribe 2. El programa solicita el nombre del lugar de origen y el nombre del lugar de destino. Si la conexión no existe entre ellos, muestra "Conexión no encontrada". Si existe, la elimina y muestra "Conexión eliminada correctamente", luego vuelve al submenú

    */



int main()
{
    char opcion;
    do 
    {
        
        puts("========================================");
        puts("     TRANSPORTE INTELIGENTE ");
        puts("========================================");

        puts("1) Buscar ruta");
        puts("2) Gestionar lugares");
        puts("3) Gestionar conexiones");
        puts("4) Mostrar red de transporte");
        puts("5) Salir");

        printf("Ingrese su opcion: ");
        scanf(" %c", &opcion);

        switch (opcion) 
        {
            case '1':
                printf("\n");

                char opcion2;
                do
                {
                    puts("--------BUSCAR RUTA --------");

                    puts("1) Mas rapida");
                    puts("2) Mas economica");
                    puts("3) Mejor equilibrio");
                    puts("4) Volver");
                    
                    printf("Ingrese su opcion: ");
                    scanf(" %c", &opcion2);
                    
                    switch (opcion2) 
                    {
                        case '1':

                            break;
                        case '2':

                            break;
                        case '3':

                            break;
                    }
                    if (opcion2 != '4') 
                    {
                        printf("\n");
                        presioneTeclaParaContinuar();
                        limpiarPantalla();
                    }
                } while (opcion2 != '4');
            
                break;
            case '2':
                printf("\n");

                char opcion3;
                do
                {
                    puts("--------GESTIONAR LUGARES --------");
                    
                    puts("1) Agregar lugar");
                    puts("2) Eliminar lugar");
                    puts("3) Mostrar lista de lugares");
                    puts("4) Volver");

                    printf("Ingrese su opcion: ");
                    scanf(" %c", &opcion3);

                    switch (opcion3) 
                    {
                        case '1':

                            break;
                        case '2':

                            break;
                        case '3':

                            break;
                    }
                    if (opcion3 != '4') 
                    {
                        printf("\n");
                        presioneTeclaParaContinuar();
                        limpiarPantalla();
                    }
                } while (opcion3 != '4');
                    
                break;
            case '3':
                printf("\n");

                char opcion4;
                do
                {
                    puts("--------GESTIONAR CONEXIONES --------");

                    puts("1) Agregar conexion");
                    puts("2) Eliminar conexion");
                    puts("3) Volver");

                    printf("Ingrese su opcion: ");
                    scanf(" %c", &opcion4);

                    switch (opcion4) 
                    {
                        case '1':

                            break;
                        case '2':

                            break;
    
                    }
                    if (opcion4 != '3') 
                    {
                        printf("\n");
                        presioneTeclaParaContinuar();
                        limpiarPantalla();
                    }
                } while (opcion4 != '3');

                    
                break;
            case '4':
                printf("hola \n");
                break;
        }

            
        if (opcion != '5') 
        {
            printf("\n");
            presioneTeclaParaContinuar();
            limpiarPantalla();
        }
        
    } while (opcion != '5');

  return 0;

}

