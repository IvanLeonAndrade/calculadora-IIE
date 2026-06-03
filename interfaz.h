/*
  Copyright 2026 - Iván Leon Andrade Franco
  Calculadora Portatil - Libreria Interfaz Usuario

  - Divisor De Tension
  - Resistencia Paralelo [2 Resistencias]
  - Frecuencia de Corte
  - Tiempo de Crecimiento
  - Transitorio Capacitor
*/
#include <stdio.h>

void operaciones(void) {
  printf("\n***Calculadora Elemental Para Circuitos***\n\n");

  printf("Paralelo R1 || R2     [1]\n");
  printf("Divisor de Tension    [2]\n");
  printf("Frecuencia de Corte   [3]\n");
  printf("Tiemmpo Crecimiento   [4]\n");
  printf("Transitorio Capacitor [5]\n\n");
}

void guia_user_divisor_tension(void) {
  printf("\n***Divisor de Tension - Respecto R1***\n");
}

void guia_user_rp(void) {
  printf("\n***Equivalencia Paralelo- 2 Resistencias***\n\n");
}

void guia_user_frecuencia_corte(void) {
  printf("\n***Frecuencia De Corte - Circuito RC***\n");
}

void guia_user_tiempo_crecimiento(void) {
  printf("\n***Tiempo De Crecimiento - Tau***\n");
}

void guia_user_respuesta_transitoria_capacitor(void) {
  printf("\n***Calculo Tension Capacitor***\n");
}