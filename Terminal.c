#include <stdio.h>
#include <string.h>

void main() {
  char userName[25];
  int decision;
  int bucle = 1;
  int estudiando = 1;
  while (bucle == 1) {
    printf("\tBienvenido a la terminal\n");
    printf("\tIngrese el nombre de su usuario: \n");
    printf("\t");
    scanf("%s", userName);
    printf("Bienvenido %s vamos a acceder a tu seccion\n", userName);
    if (strcmp(userName, "julian") == 0) {
      while (estudiando == 1) {
        printf("Esto es PlatziTerminal Free Edition, que deseas hacer?\n");
        printf("Ingrese 1 para estudiar, 2 para leer y cualquier otro valor para salir\n");
        scanf("%d", & decision);
        if (decision == 1)
          printf("Estas en la seccion de estudio\n");
        else if (decision == 2)
          printf("Estas en el blog\n");
        else {
          printf("Goodbye\n");
          estudiando = 2;
        }
      }
    }
    else if (strcmp(userName, "paula") == 0) {
      while (estudiando == 1) {
        printf("Esto es PlatziTerminal Free Edition, que deseas hacer?\n");
        printf("Ingrese 1 para estudiar, 2 para leer, 3. Mentoria cualquier otro valor para salir\n");
        scanf("%d", & decision);
        if (decision == 1)
          printf("Estas en la seccion de estudio\n");
        else if (decision == 2)
          printf("Estas en el blog\n");
        else if (decision == 3)
          printf("Estas en la seccion de mentorias\n");
        else {
          printf("Goodbye\n");
          estudiando = 2;
        }
      }
    }
    else
       printf("No eres un usuario registrado\n");
  }
}
