#include <stdio.h>
#include <string.h>
#include "./universales/menu.h" //  se incluye libreria de generacion eh impresion de menus
#include "./universales/titles.h"// se incluye para impresion de titulos
#define NMAX nMax;
int nMax;
// funcon
void push(char pila[nMax][WORDMAX], int * currentQueue, char * valor, int n) {
  if(*currentQueue < n - 1)
    strcpy(pila[++(*currentQueue)], valor); //  copio el valor a la posicion en la pila
  else
    printf("%s\n", "pila llena");
}

char pop(char pila[nMax][WORDMAX], int * currentQueue) {
  if(*currentQueue > -1)
      return pila[--(*currentQueue)][WORDMAX];
  else
    return -1;
}

int main() {
  int n, i; //tamano de expresion y iterador
  int currentQueue = -1;
  printTitle("Pilas-Estaticas");
  printf("Ingrese el tamanio de caracteres utilizados en la expresion: ");
  scanf("%d", &n);
  nMax = n;
  char expValue[WORDMAX];
  printf("Tamano de expresion: %d\n", n);
  char queue[n][WORDMAX];
  for(i = 0; i < n; i++) {
    printf("Ingrese valor de posicion: %d\n", i);
    scanf(" %c", expValue);
    push(queue, &currentQueue, expValue, n);
  }
  for(i = 0; i < n; i++){
    printf("%s", queue[2]);
  }
  printf("\n");
  return 0;
}
