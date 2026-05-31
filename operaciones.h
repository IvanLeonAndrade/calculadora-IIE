/*
  Copyright 2026 - Iván Leon Andrade Franco
  Calculadora Portatil - Libreria De Operaciones

  - Divisor De Tension
  - Resistencia Paralelo [2 Resistencias]
  - Frecuencia de Corte
*/
#include <stdio.h>

/*
  @r_x: Resistencias
  @v_i: Tension Del Divisor
  @c: Capacitancia
*/
struct valores {
  double r_1, r_2;
  double v_i;
  double c;
  double resultado;

}val;

const int pi = 3.141592;
 
int calcular_resistencia_paralelo(void) {
  printf("R1? ");
  scanf("%lf", &val.r_1);
  printf("R2? ");
  scanf("%lf", &val.r_2);

  val.resultado = val.r_1 * val.r_2 / (val.r_1 + val.r_2);
  printf("%.3f || %.3f = %.3f\n\n", val.r_1, val.r_2, val.resultado);

  return 0;
}

int calcular_divisor_tension(void) {
  printf("R1? ");
  scanf("%lf", &val.r_1);
  printf("R2? ");
  scanf("%lf", &val.r_2);
  printf("Vi? ");
  scanf("%lf", &val.v_i);

  val.resultado = val.v_i * val.r_1 / (val.r_1 + val.r_2);
  printf("Vout: %f con R1 = %f Y R2 = %f\n\n", val.resultado, val.r_1, val.r_2);

  return 0;
}

int frecuencia_de_corte(void) {
  printf("R? ");
  scanf("%lf", &val.r_1);
  printf("C? ");
  scanf("%lf", &val.c);

  val.resultado =  1 / (2 * pi * val.r_1 * val.c);
  printf("La FC: %f de R: %f y C: %f\n", val.resultado, val.r_1, val.c);

  return 0;
}