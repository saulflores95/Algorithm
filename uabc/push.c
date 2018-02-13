#include <stdio.h>
void push(int pila[], int * tope, int valor, int n) {
  if(*tope < n - 1)
    pila[++(*tope)] = valor;
  else
    printf("%s\n", "pila llena");
}

void popImpresion(int pila[], int * tope) {
  if(*tope > -1) {
    printf("Valor a quitar: %d\n", pila[(*tope)]);
    pila[(*tope)] = -1;
    --(*tope);
  }
  else
    printf("Pila Vacia...\n");
}

int popFuncional(int pila[], int * tope) {
  if(*tope > -1)
    return pila[(*tope)--];
  else
    return -1;
}

int main(int argc, char const *argv[]) {
  int n = 8, pila[n];
  int tope = -1;
  int i, j;
  for(i = 0; i < n; i++) {
    push(pila, &tope, i+3, n);
  }
  popImpresion(pila, &tope);
  popImpresion(pila, &tope);
  popImpresion(pila, &tope);
  for(j; j < n; j++) {
    printf("%d\n", pila[j]);
  }
  return 0;
}
