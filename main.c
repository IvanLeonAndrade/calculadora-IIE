
#include <string.h>

#include "interfaz.h"
#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>


const char *opciones []= {"o", "c", "x", "1", "2", "3", "cls"};
int total_opciones = sizeof(opciones) / sizeof(opciones[0]);

int main(void) {
  start_calculadora();

  char buffer[20];

  while (fgets(buffer, sizeof(buffer), stdin)) {
    buffer[strcspn(buffer, "\n")] = '\0';
    if (buffer[0] == '\0') {
        continue; 
    }
    int valida = 0;
    for(int i = 0; i < total_opciones; i++) {
      if(strcmp(buffer, opciones[i]) == 0) {
        valida = 1;
        break;
      }
    }
    if(valida == 0) {
      fprintf(stderr, "Error: Opcion no valida. Intente de nuevo.\n");
      continue;
    }

    if (strcmp(buffer, "o") == 0) {
      operaciones();
    } else if (strcmp(buffer, "c") == 0) {
      comandos();
    } else if (strcmp(buffer, "x") == 0) {
      printf("Exit\n");
      break;
    } else if (strcmp(buffer, "1") == 0) {
      guia_user_rp();
      calcular_resistencia_paralelo();
      start_calculadora();
    } else if (strcmp(buffer, "2") == 0) {
      guia_user_divisor_tension();
      calcular_divisor_tension();
      start_calculadora();
    } else if (strcmp(buffer, "3") == 0) {
      guia_frecuencia_corte();
      frecuencia_de_corte();
      start_calculadora();
    } else if (strcmp(buffer, "cls") == 0) {
      system("cls");
      start_calculadora();
    }
  }

  return 0;
}
