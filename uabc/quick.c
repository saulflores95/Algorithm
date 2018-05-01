#include <stdio.h>

void printArray(int *A, int size) {
    int i;  //  valor de iterador
    for (i=0; i < size; i++)
      printf("%d ", A[i]); // se imprime cada elemento del arreglo
    printf("\n"); //  se imprime un espacio para mejor visualizacion
}

int dividir(int arr[], int inicio, int fin) {
  int valor, puntoDivision, der, izq, tmp;
  puntoDivision = inicio;
  valor = arr[inicio];
  der = inicio + 1;
  izq = fin;
  while(der < izq){
    while(arr[der] <= valor && (der < izq))
      der++;
    if((der == izq) && arr[der] <= valor)
      der++;
    while((der < izq) && arr[izq] > valor)
      izq--;
    if((der==izq) && (arr[izq] > valor))
      izq--;
    if(der < izq) {
      tmp = arr[izq];
      arr[izq] = arr[der];
      arr[der] = tmp;
      der++;
      izq--;
    }
  }
  tmp = arr[inicio];
  arr[inicio] = arr[izq];
  arr[izq] = tmp;
  puntoDivision = izq;
  return puntoDivision;
}

void ord_rapido(int arr[], int inicio, int fin) {
  int punto_div;
  if(inicio < fin) {
    punto_div = dividir(arr, inicio, fin);
    printf("%d\n", punto_div);
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
