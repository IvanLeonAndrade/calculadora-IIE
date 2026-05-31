/*
  Copyright 2026 - Iván Leon Andrade Franco
  Calculadora Portatil - Libreria Interfaz Usuario

  - Divisor De Tension
  - Resistencia Paralelo [2 Resistencias]
  - Frecuencia de Corte
*/
#include <stdio.h>

void guia_user_rp(void) {
  printf(
      "\n***Calculadora Resistencia Paralelo - Solo para 2 Resistores***\n\n");
}

void operaciones(void) {
  printf("\nEquivalencia R Paralelo [1]\n");
  printf("Divisor de Tension [2]\n");
  printf("Frecuencia de Corte [3]\n");
}

void comandos(void) {
  printf("Exit [x]\n");
  printf("clear [cls]\n\n");
}

void guia_user_divisor_tension(void) {
  printf("\n***Calculadora Divisor de Tension - Respecto R1***\n");
}

void start_calculadora(void) {
  printf("\n***Calculadora De Operaciones Basicas Para Electronica***\n");
  printf("- Operaciones [o]\n");
  printf("- Comandos [c]\n");
}

void guia_frecuencia_corte(void) {
   printf("\n***Calculadora Frecuencia De Corte - RC***\n");
}
