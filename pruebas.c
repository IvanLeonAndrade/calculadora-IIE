#include <stdio.h>

struct valores {
  double r_1, r_2;
  double v_i;
  double c;
  double resultado;
};

const double PI = 3.141592653589793;

/* FUNCIÓN AYUDANTE: Centraliza la lectura y validación.
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
  struct valores val = {0};

  // Usamos corto-circuito lógico: si el primero falla, ni intenta el segundo.
  if (!pedir_double("R1? ", &val.r_1) || !pedir_double("R2? ", &val.r_2)) {
    return -1;
  }

  if (val.r_1 + val.r_2 == 0) {
    printf("Error: División por cero.\n\n");
    return -1;
  }

  val.resultado = (val.r_1 * val.r_2) / (val.r_1 + val.r_2);
  printf("%.3f || %.3f = %.3f\n\n", val.r_1, val.r_2, val.resultado);
  return 0;
}

int main(void) {
  return  calcular_resistencia_paralelo();
  
}