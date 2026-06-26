#include "funciones.h"


int main(){

    red* red_caminando=crearRed(100);
    red* red_metro=crearRed(100);
    red* red_micro=crearRed(100);
    red* red_colectivo=crearRed(100);


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
                char origen[30];
                printf("\nIngrese nombre del origen de la ruta: ");
                scanf(" %29s", origen);

                char destino[30];
                printf("\nIngrese nombre del destino de la ruta: ");
                scanf(" %29s", destino);

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
                            char opcionRed1;
                             puts("\nEn que red desea buscar ruta?");
                             puts("1) Caminando");
                             puts("2) Metro");
                             puts("3) Micro");
                             puts("4) Colectivo");
                             printf("Ingrese su opcion: ");
                             scanf(" %c", &opcionRed1);

                            switch (opcionRed1) 
                            {
                                case '1':

                                    if(map_search(red_caminando->lugares, origen) == NULL)
                                    {
                                        printf("\nLugar de origen no encontrado en la red caminando\n");
                                        break;
                                    }

                                    if(map_search(red_caminando->lugares, destino) == NULL)
                                    {
                                        printf("\nLugar de destino no encontrado en la red caminando\n");
                                        break;
                                    }

                                    busquedaRapidez(red_caminando, origen, destino);
                                    break;
                                
                                case '2':
                                    
                                    if(map_search(red_metro->lugares, origen) == NULL)
                                    {
                                        printf("\nLugar de origen no encontrado en la red metro\n");
                                        break;
                                    }

                                    if(map_search(red_metro->lugares, destino) == NULL)
                                    {
                                        printf("\nLugar de destino no encontrado en la red metro\n");
                                        break;
                                    }

                                    busquedaRapidez(red_metro, origen, destino);
                                    break;
                                
                                case '3':

                                    if(map_search(red_micro->lugares, origen) == NULL)
                                    {
                                        printf("\nLugar de origen no encontrado en la red micro\n");
                                        break;
                                    }

                                    if(map_search(red_micro->lugares, destino) == NULL)
                                    {
                                        printf("\nLugar de destino no encontrado en la red micro\n");
                                        break;
                                    }

                                    busquedaRapidez(red_micro, origen, destino);
                                    break;
                                
                                case '4':

                                    if(map_search(red_colectivo->lugares, origen) == NULL)
                                    {
                                        printf("\nLugar de origen no encontrado en la red colectivo\n");
                                        break;
                                    }

                                    if(map_search(red_colectivo->lugares, destino) == NULL)
                                    {
                                        printf("\nLugar de destino no encontrado en la red colectivo\n");
                                        break;
                                    }

                                    busquedaRapidez(red_colectivo, origen, destino);
                                    break;
                                
                                default:
                                    puts("\nOpcion invalida");
                                    break;
                            }
                            break;
                        case '2':
                            char opcionRed2;
                             puts("\nEn que red desea buscar ruta?");
                             puts("1) Caminando");
                             puts("2) Metro");
                             puts("3) Micro");
                             puts("4) Colectivo");
                             printf("Ingrese su opcion: ");
                             scanf(" %c", &opcionRed2);

                            switch (opcionRed2) 
                            {
                                case '1':

                                    if(map_search(red_caminando->lugares, origen) == NULL)
                                    {
                                        printf("\nLugar de origen no encontrado en la red caminando\n");
                                        break;
                                    }

                                    if(map_search(red_caminando->lugares, destino) == NULL)
                                    {
                                        printf("\nLugar de destino no encontrado en la red caminando\n");
                                        break;
                                    }

                                    busquedaEconomica(red_caminando, origen, destino);
                                    break;
                                
                                case '2':
                                    if(map_search(red_metro->lugares, origen) == NULL)
                                    {
                                        printf("\nLugar de origen no encontrado en la red metro\n");
                                        break;
                                    }

                                    if(map_search(red_metro->lugares, destino) == NULL)
                                    {
                                        printf("\nLugar de destino no encontrado en la red metro\n");
                                        break;
                                    }
                                    busquedaEconomica(red_metro, origen, destino);
                                    break;
                                
                                case '3':
                                    if(map_search(red_micro->lugares, origen) == NULL)
                                    {
                                        printf("\nLugar de origen no encontrado en la red micro\n");
                                        break;
                                    }

                                    if(map_search(red_micro->lugares, destino) == NULL)
                                    {
                                        printf("\nLugar de destino no encontrado en la red micro\n");
                                        break;
                                    }
                                    busquedaEconomica(red_micro, origen, destino);
                                    break;
                                
                                case '4':
                                    if(map_search(red_colectivo->lugares, origen) == NULL)
                                    {
                                        printf("\nLugar de origen no encontrado en la red colectivo\n");
                                        break;
                                    }

                                    if(map_search(red_colectivo->lugares, destino) == NULL)
                                    {
                                        printf("\nLugar de destino no encontrado en la red colectivo\n");
                                        break;
                                    }
                                    busquedaEconomica(red_colectivo, origen, destino);
                                    break;
                                
                                default:
                                    puts("\nOpcion invalida");
                                    break;
                            }
                            break;
                        case '3':
                            char opcionRed3;
                            double alpha = 0.5; // Valor por defecto para la búsqueda equilibrada
                             puts("\nEn que red desea buscar ruta?");
                             puts("1) Caminando");
                             puts("2) Metro");
                             puts("3) Micro");
                             puts("4) Colectivo");
                             printf("Ingrese su opcion: ");
                             scanf(" %c", &opcionRed3);


                            switch (opcionRed3) 
                            {
                                case '1':
                                    if(map_search(red_caminando->lugares, origen) == NULL)
                                    {
                                        printf("\nLugar de origen no encontrado en la red caminando\n");
                                        break;
                                    }

                                    if(map_search(red_caminando->lugares, destino) == NULL)
                                    {
                                        printf("Lugar de destino no encontrado en la red caminando\n");
                                        break;
                                    }
                                    busquedaEquilibrada(red_caminando, origen, destino, alpha);
                                    break;
                                
                                case '2':
                                    if(map_search(red_metro->lugares, origen) == NULL)
                                    {
                                        printf("\nLugar de origen no encontrado en la red metro\n");
                                        break;
                                    }

                                    if(map_search(red_metro->lugares, destino) == NULL)
                                    {
                                        printf("\nLugar de destino no encontrado en la red metro\n");
                                        break;
                                    }
                                    busquedaEquilibrada(red_metro, origen, destino, alpha);
                                    break;
                                
                                case '3':
                                    if(map_search(red_micro->lugares, origen) == NULL)
                                    {
                                        printf("\nLugar de origen no encontrado en la red micro\n");
                                        break;
                                    }

                                    if(map_search(red_micro->lugares, destino) == NULL)
                                    {
                                        printf("\nLugar de destino no encontrado en la red micro\n");
                                        break;
                                    }
                                    busquedaEquilibrada(red_micro, origen, destino, alpha);
                                    break;
                                
                                case '4':
                                    if(map_search(red_colectivo->lugares, origen) == NULL)
                                    {
                                        printf("\nLugar de origen no encontrado en la red colectivo\n");
                                        break;
                                    }

                                    if(map_search(red_colectivo->lugares, destino) == NULL)
                                    {
                                        printf("\nLugar de destino no encontrado en la red colectivo\n");
                                        break;
                                    }
                                    busquedaEquilibrada(red_colectivo, origen, destino, alpha);
                                    break;
                                
                                default:
                                    puts("\nOpcion invalida");
                                    break;
                            }
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

                    switch (opcion3){
                        case '1':
                            char nombre[30];
                            printf("\nIngrese nombre del lugar: ");
                            scanf(" %29s", nombre);

                            
                             char opcionRed4;
                             puts("\nEn que red desea agregar el lugar?");
                             puts("1) Caminando");
                             puts("2) Metro");
                             puts("3) Micro");
                             puts("4) Colectivo");
                             printf("Ingrese su opcion: ");
                             scanf(" %c", &opcionRed4);

                            switch (opcionRed4) 
                            {
                                case '1':
                                    agregarLugar(red_caminando, nombre);
                                    break;
                                
                                case '2':
                                    agregarLugar(red_metro, nombre);
                                    break;
                                
                                case '3':
                                    agregarLugar(red_micro, nombre);
                                    break;
                                
                                case '4':
                                    agregarLugar(red_colectivo, nombre);
                                    break;
                                
                                default:
                                    puts("\nOpcion invalida");
                                    break;
                            }
                            
                            break;
                        case '2':
                            char nombre2[30];
                            printf("\nIngrese nombre del lugar a eliminar: ");
                            scanf(" %29s", nombre2);

                            char opcionRed5;
                            puts("\nEn que red desea eliminar el lugar?");
                            puts("1) Caminando");
                            puts("2) Metro");
                            puts("3) Micro");
                            puts("4) Colectivo");
                            printf("Ingrese su opcion: ");
                            scanf(" %c", &opcionRed5);

                            switch (opcionRed5) {
                                case '1':
                                    eliminarLugar(red_caminando, nombre2);
                                    break;
                                case '2':
                                    eliminarLugar(red_metro, nombre2);
                                    break;
                                case '3':
                                    eliminarLugar(red_micro, nombre2);
                                    break;
                                case '4':
                                    eliminarLugar(red_colectivo, nombre2);
                                    break;
                                default:
                                    puts("\nOpcion invalida");
                                    break;
                            }
                            break;
                        case '3':
                            
                            char opcionRed6;
                            puts("\nEn que red desea ver la lista de lugares?");
                            puts("1) Caminando");
                            puts("2) Metro");
                            puts("3) Micro");
                            puts("4) Colectivo");
                            printf("Ingrese su opcion: ");
                            scanf(" %c", &opcionRed6);
                            switch (opcionRed6) 
                            {
                                case '1':
                                    mostrarLugares(red_caminando);
                                    break;
                                
                                case '2':
                                    mostrarLugares(red_metro);
                                    break;
                                
                                case '3':
                                    mostrarLugares(red_micro);
                                    break;
                                
                                case '4':
                                    mostrarLugares(red_colectivo);
                                    break;
                                
                                default:
                                    puts("\nOpcion invalida");
                                    break;
                            }
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

                    switch (opcion4){
                        case '1':
                            char origen[30];
                            char destino[30];
                            int tiempo;
                            int costo;
                            printf("Lugar de origen: ");
                            scanf(" %29s", origen);
                            printf("Lugar de destino: ");
                            scanf(" %29s", destino);
                            printf("Tiempo (minutos): ");
                            scanf("%d", &tiempo);
                            printf("Costo: ");
                            scanf("%d", &costo);

                            char opcionRed7;
                            puts("\nTipo de transporte:");
                            puts("1) Caminando");
                            puts("2) Metro");
                            puts("3) Micro");
                            puts("4) Colectivo");
                            printf("Ingrese su opcion: ");
                            scanf(" %c", &opcionRed7);

                            switch (opcionRed7) 
                            {
                                case '1':
                                    agregarConexion(red_caminando, origen, destino, tiempo, costo, 1, "Caminando");
                                    break;
                                
                                case '2':
                                    agregarConexion(red_metro, origen, destino, tiempo, costo, 2, "Metro");
                                    break;
                                
                                case '3':
                                    agregarConexion(red_micro, origen, destino, tiempo, costo, 3, "Micro");
                                    break;
                                
                                case '4':
                                    agregarConexion(red_colectivo, origen, destino, tiempo, costo, 4, "Colectivo");
                                    break;
                                
                                default:
                                    puts("Opcion invalida");
                                    break;
                            }   
                        
                            break;
                        case '2':
                            char origen2[30], destino2[30];
                            printf("Ingrese lugar de origen: ");
                            scanf(" %29s", origen2);
                            printf("Ingrese lugar de destino: ");
                            scanf(" %29s", destino2);

                            char opcionRed8;
                            puts("\nTipo de transporte:");
                            puts("1) Caminando");
                            puts("2) Metro");
                            puts("3) Micro");
                            puts("4) Colectivo");
                            printf("Ingrese su opcion: ");
                            scanf(" %c", &opcionRed8);

                            switch (opcionRed8) {
                                case '1':
                                    eliminarConexion(red_caminando, origen2, destino2);
                                    break;
                                case '2':
                                    eliminarConexion(red_metro, origen2, destino2);
                                    break;
                                case '3':
                                    eliminarConexion(red_micro, origen2, destino2);
                                    break;
                                case '4':
                                    eliminarConexion(red_colectivo, origen2, destino2);
                                    break;
                                default:
                                    puts("\nOpcion invalida");
                                    break;
                            }
                            break;
                    }
                    break;
                    if (opcion4 != '3') 
                    {
                        printf("\n");
                        presioneTeclaParaContinuar();
                        limpiarPantalla();
                    }
                } while (opcion4 != '3');

                    
                break;
            case '4':
                puts("Generando grafos...");

                generarGraphviz(red_caminando, "red_caminando");
                generarGraphviz(red_metro, "red_metro");
                generarGraphviz(red_micro, "red_micro");
                generarGraphviz(red_colectivo, "red_colectivo");
                
                break;
        }

            
        if (opcion != '5') 
        {
            printf("\n");
            presioneTeclaParaContinuar();
            limpiarPantalla();
        }
        
    } while (opcion != '5');

    puts("\nCerrando ChosenMove...\n");

  return 0;

}

