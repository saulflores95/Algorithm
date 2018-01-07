#include "stdio.h"

void main() {
  int decision = 0, i = 0;
  /*
  while (decision == 1) {
    i++;
    printf("ejecusion numero #%d\n", i);
    printf("Si desea continuar presione 1 o cualquier otro valor para salir\n");
    scanf("%d", &decision);
  }
  */
  do {
    i++;
    printf("ejecusion numero #%d\n", i);
    printf("Si desea continuar presione 1 o cualquier otro valor para salir\n");
    scanf("%d", &decision);
  } while (decision == 1);
  printf("Gracias, adios\n");

}
