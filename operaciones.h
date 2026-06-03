/*
  Copyright 2026 - Iván Leon Andrade Franco
  Calculadora Portatil - Libreria De Operaciones

  - Divisor De Tension
  - Resistencia Paralelo [2 Resistencias]
  - Frecuencia de Corte
  - Tiempo de Crecimiento
  - Transitorio Capacitor
*/


#include <stdio.h>
#include <math.h>
/*
  @r_x: Resistencias
  @v_i: Tension Del Divisor
  @c: Capacitancia
*/
struct parametros {
  double r_1, r_2;
  double v_i;
  double v_f;
  double tau;
  double t;
  double c;
  double resultado;
};

const double PI = 3.1415926;
const double e = 2.7182818;

/* FUNCIÓN AYUDANTE: Centraliza la lectura y variableidación.
  Retorna 1 si la lectura fue exitosa, o 0 si el usuario metió basura.
*/
int pedir_double(const char *prompt, double *destino) {
  printf("%s", prompt);
  if (scanf("%lf", destino) != 1) {
    while (getchar() != '\n')
      ;       // Limpia el búfer inmediatamente
    return 0; // Entrada inválida
  }
  return 1; // Entrada válida
}

int calcular_resistencia_paralelo(void) {
  struct parametros variable = {0};

  // Usamos corto-circuito lógico: si el primero falla, ni intenta el segundo.
  if (!pedir_double("R1? ", &variable.r_1) ||
      !pedir_double("R2? ", &variable.r_2)) {
    return -1;
  }

  if (variable.r_1 + variable.r_2 == 0) {
    printf("Error: División por cero.\n\n");
    return -1;
  }

  variable.resultado =
      (variable.r_1 * variable.r_2) / (variable.r_1 + variable.r_2);
  printf("%.3f || %.3f = %.3f\n\n", variable.r_1, variable.r_2,
         variable.resultado);
  return 0;
}

int calcular_divisor_tension(void) {
  struct parametros variable = {0};

  if (!pedir_double("R1? ", &variable.r_1) ||
      !pedir_double("R2? ", &variable.r_2) ||
      !pedir_double("V? ", &variable.v_i)) {
    return -1;
  }

  variable.resultado =
      variable.v_i * variable.r_1 / (variable.r_1 + variable.r_2);
  printf("Vout: %f V con R1 = %f; R2 = %f\n\n", variable.resultado,
         variable.r_1, variable.r_2);

  return 0;
}

int frecuencia_de_corte(void) {
  struct parametros variable = {0};

  if (!pedir_double("R? ", &variable.r_1) ||
      !pedir_double("C? ", &variable.c)) {
    return -1;
  }

  if (variable.r_1 * variable.c == 0) {
    printf("Error: Los valores deben ser mayores a cero.\n\n");
    return -1;
  }

  variable.resultado = 1 / (2 * PI * variable.r_1 * variable.c);
  printf("La FC: %f Hz de R: %f y C: %f\n", variable.resultado, variable.r_1,
         variable.c);

  return 0;
}

int tiempo_de_crecimiento(void) {
  struct parametros variable = {0};

  if (!pedir_double("R? ", &variable.r_1) ||
      !pedir_double("C? ", &variable.c)) {
    return -1;
  }

  variable.tau = variable.r_1 * variable.c;
  printf("Tau = %f\n", variable.tau);
  return 0;
}

int transitirio_capacitor(void) {
  struct parametros variable = {0};

  if (!pedir_double("vi? ", &variable.v_i) ||
      !pedir_double("vf? ", &variable.v_f) ||
      !pedir_double("tau? ", &variable.tau) ||
      !pedir_double("t? ", &variable.t)) {
    return -1;
  }

  double exponente_euler = -variable.t / variable.tau;
  variable.resultado =
      variable.v_f + (variable.v_i - variable.v_f) * pow(e, exponente_euler);

  printf("Vc(t) = %f\n", variable.resultado);
  return 0;
}