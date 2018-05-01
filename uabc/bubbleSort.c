#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int size) {
  int i; //valor inicial de iterador
  for (i=0; i < size; i++)
    printf("%d ", A[i]); //se imprime todos los valors del arreglo
  printf("\n"); //espacio para finalizacion de funcion
}

void BubbleSort(int arr[], int n) {
  int i, j, tmp;
  for(i = 0; i < n; i++)
    for(j=n; j > i; j--) {
      if(arr[j] < arr[j - 1]) {
        tmp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = tmp;
      }
    }
}

void BubbleSortMod(int arr[], int n) {
  int i, j, tmp, flag;
  flag = 1;
  if(flag)
    printf("I entered\n");
    for(i = 0; i < n; i++) {
      flag = 0;
      for(j=n; j > i; j--) {
        if(arr[j] < arr[j - 1]) {
          flag = 1;
          tmp = arr[j];
          arr[j] = arr[j - 1];
          arr[j - 1] = tmp;
        }
      }
      printArray(arr, n);
    }
}

int main(int argc, char const *argv[]) {
  int n = 5;
  int arr[] = {10, 3, 2, 3, 10};
  printArray(arr, n);
  BubbleSortMod(arr, n);
  printArray(arr, n);
  printf("Done...\n");
  return 0;
}
