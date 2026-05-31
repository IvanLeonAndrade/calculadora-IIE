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
struct parametros {
  double r_1, r_2;
  double v_i;
  double c;
  double resultado;
};

const double PI = 3.141592;
 
int calcular_resistencia_paralelo(void) {
  struct parametros variable = {0};

  printf("R1? ");
  scanf("%lf", &variable.r_1);
  printf("R2? ");
  scanf("%lf", &variable.r_2);

  variable.resultado = variable.r_1 * variable.r_2 / (variable.r_1 + variable.r_2);
  printf("%.3f || %.3f = %.3f\n\n", variable.r_1, variable.r_2, variable.resultado);

  return 0;
}

int calcular_divisor_tension(void) {
  struct parametros variable = {0};

  printf("R1? ");
  scanf("%lf", &variable.r_1);
  printf("R2? ");
  scanf("%lf", &variable.r_2);
  printf("Vi? ");
  scanf("%lf", &variable.v_i);

  variable.resultado = variable.v_i * variable.r_1 / (variable.r_1 + variable.r_2);
  printf("Vout: %f con R1 = %f Y R2 = %f\n\n", variable.resultado, variable.r_1, variable.r_2);

  return 0;
}

int frecuencia_de_corte(void) {
  struct parametros variable = {0};

  printf("R? ");
  scanf("%lf", &variable.r_1);
  printf("C? ");
  scanf("%lf", &variable.c);

  variable.resultado =  1 / (2 * PI * variable.r_1 * variable.c);
  printf("La FC: %f de R: %f y C: %f\n", variable.resultado, variable.r_1, variable.c);

  return 0;
}