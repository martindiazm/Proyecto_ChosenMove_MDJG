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
## BusquedaMixta
## Mostrar red con Graphviz