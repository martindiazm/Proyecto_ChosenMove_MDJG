#include "extra.h"


// Función para limpiar la pantalla
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void presioneTeclaParaContinuar() {
  puts("Presione enter para continuar...");
  int c;
  // Liampia todo el buffer de entrada hasta el salto de linea
  while ( (c = getchar()) != '\n' && c != EOF );
  getchar(); // Espera a que el usuario presione una tecla
}

