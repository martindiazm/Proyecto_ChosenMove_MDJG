#include <stdio.h>
#include <stdlib.h>
#include "tdas/list.h"
#include "tdas/heap.h"
#include "tdas/extra.h"
#include "tdas/stack.h"
#include "tdas/queue.h"
#include <string.h>
#include <time.h>

// Definición de los structs 









// Definición de las funciones 





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

        printf("Ingrese su opción: ");
        scanf(" %c", &opcion);

        switch (opcion) 
        {
            case '1':
            
                break;
            case '2':
            
                break;
            case '3':
            
                break;
            case '4':
                
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

