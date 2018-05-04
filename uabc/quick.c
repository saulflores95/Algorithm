#include <stdio.h>

void printArray(int *A, int size) {
    int i;  //  valor de iterador
    for (i=0; i < size; i++)
      printf("%d ", A[i]); // se imprime cada elemento del arreglo
    printf("\n"); //  se imprime un espacio para mejor visualizacion
}

int dividir(int arr[], int inicio, int fin) {
  int valor = arr[fin];
  int i = inicio - 1;
  int j, tmp;
  for (j = inicio; j < fin; j++)
    if(arr[j] <= valor) {
      i++;
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;
    }
  tmp = arr[i+1];
  arr[i+1] = arr[fin];
  arr[fin] = tmp;
  return i++;
}

void ord_rapido(int arr[], int inicio, int fin) {
  int punto_div;
  if(inicio < fin) {
    punto_div = dividir(arr, inicio, fin);
    ord_rapido(arr, inicio, punto_div - 1);
    ord_rapido(arr, punto_div + 1, fin);
  }
}

int main() {
  int arr[] = { 9, 8, 6, 10, 14, 20, 60, 11 };
  int size = sizeof(arr)/sizeof(arr[0]);
  printf("Before quick-sort\n");
  printArray(arr, size);
  ord_rapido(arr, 0, size);
  printf("After quick-sort\n");
  printArray(arr, size);
}
