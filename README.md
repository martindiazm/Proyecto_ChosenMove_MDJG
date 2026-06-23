# Proyecto_ChosenMove_MDJG

Para ejecutar el código primero debemos compilar en PowerShell 
````
gcc main.c funciones.c tdas/*.c -o programa.exe
````

Y luego ejecutar:
````
.\programa.exe   
````
Para Realizar Cambios y Commits en Git Bash:
````
git add .                 
````
````
git commit -m "Mensaje"   
````
Para Enviar Cambios a GitHub:
````
git push origin main
````
Para agregar los cambios realizados por otros 
````
git pull
````
Si les sale un mensaje en inglés, presionan la tecla "Esc" y escriben ":wq" xd


Para visualizar la red de transporte hay que descargar "Graphviz" y añadirlo a las variables de entorno del sistema,
solo así se podran generar imágenes que representen correctamente cada grafo 


# Cosas que faltan:

## Eliminar lugar de los grafos (agregar al main)
## Mostrar lista de lugares añadidos (agregar al main)
## Eliminar conexion de los grafos (agregar al main)
## BusquedaRapidez
## BusquedaEconomica

## Mostrar red con Graphviz
Para que funcione el graficar, es necesario instalar Graphviz, y cuando pregunte por instalar 
system Path:
![Instalacion](imagenes/GraphvizEjemeplo.png)

hay que seleccionar la 2da o 3ra opcion, luego de eso funciona sin problemas.

## Problemas 
El agregar conexiones no verifica si los nombres existen, si no existen crea el nodo pero solo si el de lugar de origen si existia anteriormente,si ninguno de los ingresados o el de origen no existe, no pasa nada.

tambien se puede hacer una dobleconxion entre los dos nodos con distintos valores de tiempo y costo,
puedo poner varias conexiones en la misma dirrecion con distintos valores.

El agregar lugar no da retroalimentacion si se ingresa el mismo nombre de un lugar ya existente, solo indica que se agrego el lugar

![Ejemplo grafo](imagenes/red_caminando.png)
