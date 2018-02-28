#include <stdio.h>
#include <stdlib.h>
#include "./universales/menu.h"   //  Se incluye manejador de menus
#include "./universales/titles.h" //  Se incluye manejador de titulos

int extColaCircular(int cola[], int *inicio, int *fin, int n);
void insColaCircular(int cola[], int *inicio, int *fin, int valor, int n);

void printArray(int *A, int size) {
    int i;  //  valor de iterador
    for (i=0; i < size; i++)
      printf("%d ", A[i]); // se imprime cada elemento del arreglo
    printf("\n"); //  se imprime un espacio para mejor visualizacion
}

void handleCircular() {
  int inicio, fin, size = 5; // declaracion de inicion, fin, y tamano de arreglo
  int cola[size];//  declaracion de arreglo
  inicio = fin = -1;
  printTitle("Colas Circulares"); // funcion de impresion de titulo de libreria de titulos
  char options[4][WORDMAX] = {"Push", "Pop", "Imprimir", "Salir"}; // se generar opciones de menu
  int menuSize = sizeof(options)/sizeof(options[0]); //se determina el tamano del arreglo de opciones
  menu staticMenu = generateMenu(menuSize, options); //se genera una estructura tipo menu
  int boolean = 1; //se delaran el tamano del arreglo el valor extracion y el boolean para el loop del menu
  while (boolean) { //while loop para el menu, si se iguala el booleano a 0 se sale del menu
    int selectedOption = printMenu(staticMenu); //impresion de menu a igual que el valor de seleccion del menu
    switch (selectedOption) {
      case 1: //caso uno - push colas circulares
        insColaCircular(cola, &inicio, &fin, 15, size);
        break;
      case 2: //caso dos - pop colas ciruclares
        extColaCircular(cola, &inicio, &fin, size);
        break;
      case 3: //caso tres- Impresion
        printArray(cola, size);
        break;
      case 4: //caso tres- salida
        printf("Bye bye...\n");
        boolean = 0; //cambio de valor para salir de while loop
        break;
      default: //caso default
        printf("Valor no valido...\n");
        break;
    }
  }
}

void insColaCircular(int cola[], int *inicio, int *fin, int valor, int n) {
  int pos;
  pos = (++(*fin) % n);
  if(pos == (*inicio))
    printf("Cola llena\n");
  else {
    if(*inicio == -1)
      *inicio = pos;
    *fin = pos;
    cola[pos] = valor;
  }
}

int extColaCircular(int cola[], int *inicio, int *fin, int n) {
  int re_val, pos;
  if(*inicio == -1) {
    printf("Cola vacia\n");
    re_val = -1;
  } else {
    pos = *inicio;
    if(*inicio == *fin)
      *inicio = *fin = -1;
    else {
      *inicio = ((*inicio)++) % n;
    }
    re_val = cola[pos];
  }
  printf("Poped value: %d\n", re_val);
  return re_val;
}
