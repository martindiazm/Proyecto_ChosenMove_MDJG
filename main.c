#include "funciones.h"



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

                    switch (opcion3){
                        case '1':
                            char nombre[30];
                            printf("\nIngrese nombre del lugar: ");
                            scanf(" %29s", nombre);

                            
                             char opcionRed;
                             puts("\nEn que red desea agregar el lugar?");
                             puts("1) Caminando");
                             puts("2) Metro");
                             puts("3) Micro");
                             puts("4) Colectivo");
                             printf("Ingrese su opcion: ");
                             scanf(" %c", &opcionRed);

                            switch (opcionRed) {
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
                            puts("\nLugar agregado exitosamente");
                            break;
                        case '2':
                            //Eliminar




                            break;
                        case '3':
                            //Mostrar lista





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

                            char opcionRed;
                            puts("\nTipo de transporte:");
                            puts("1) Caminando");
                            puts("2) Metro");
                            puts("3) Micro");
                            puts("4) Colectivo");
                            printf("Ingrese su opcion: ");
                            scanf(" %c", &opcionRed);

                            switch (opcionRed) {
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
                            puts("\nConexion agregada exitosamente");
                            break;
                        case '2':
                            //Eliminar




                            
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

