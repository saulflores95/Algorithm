#include <stdio.h>
#include <string.h>

void main() {
  char opcion[10];
  int gorras, totalGorras, seguirComprando;
  while (seguirComprando = 1) {
    printf("Elije el producto que buscara\n");
    printf("Ingrese gorra para comprar una\n");
    printf("Ingrese termo para comprar uno\n");
    printf("Ingrese playera para comprar una\n");
    printf("Ingrese taza para comprar una\n");
    scanf("%s", opcion);
    if(strcmp(opcion, "gorra") == 0) {
      printf("Cada gorra cuesta o vale 5 dlls, cuantas quires\n");
      scanf("%d", &gorras);
      totalGorras += gorras * 5;
      printf("El total de gorras es: %d\n", totalGorras);
    }
    else if(strcmp(opcion, "termo") == 0) {

    }
    else if(strcmp(opcion, "playera") == 0) {

    }
    else if (strcmp(opcion, "taza")) {
    }
    else  {
      printf("el problema especificado no existe, prueba otra opcion\n");
      printf("en caso de querer otro producto presion 1 para salir presione cualquier num\n");
      scanf("%d", &seguirComprando);
    }
  }
}
