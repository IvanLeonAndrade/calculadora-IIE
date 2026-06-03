/*
  Copyright 2026 - Iván Leon Andrade Franco
  Calculadora Portatil - Principal

  - Divisor De Tension
  - Resistencia Paralelo [2 Resistencias]
  - Frecuencia de Corte
  - Tiempo de Crecimiento
  - Transitorio Capacitor
*/

#include <string.h>

#include "interfaz.h"
#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>

const char *opciones[] = {"1", "2", "3", "4", "5", "cls", "exit"};
int total_opciones = sizeof(opciones) / sizeof(opciones[0]);

int main(void) {
  operaciones();

  char buffer[20];

  while (fgets(buffer, sizeof(buffer), stdin)) {
    buffer[strcspn(buffer, "\n")] = '\0';

    if (buffer[0] == '\0') {
      continue;
    }

    int valida = 0;
    for (int i = 0; i < total_opciones; i++) {
      if (strcmp(buffer, opciones[i]) == 0) {
        valida = 1;
        break;
      }
    }

    if (valida == 0) {
      fprintf(stderr, "Error: Opcion no valida. Intente de nuevo.\n");
      continue;
    }

    if (strcmp(buffer, "o") == 0) {
      operaciones();
    } else if (strcmp(buffer, "exit") == 0) {
      printf("Exit\n");
      break;
    } else if (strcmp(buffer, "1") == 0) {
      guia_user_rp();
      calcular_resistencia_paralelo();
      operaciones();
    } else if (strcmp(buffer, "2") == 0) {
      guia_user_divisor_tension();
      calcular_divisor_tension();
      operaciones();
    } else if (strcmp(buffer, "3") == 0) {
      guia_user_frecuencia_corte();
      frecuencia_de_corte();
      operaciones();
    } else if (strcmp(buffer, "4") == 0) {
      guia_user_tiempo_crecimiento();
      tiempo_de_crecimiento();
      operaciones();
    } else if (strcmp(buffer, "5") == 0) {
      guia_user_respuesta_transitoria_capacitor();
      transitirio_capacitor();
      operaciones();
    }

    else if (strcmp(buffer, "cls") == 0) {
      system("cls");
      operaciones();
    }
  }

  return 0;
}
