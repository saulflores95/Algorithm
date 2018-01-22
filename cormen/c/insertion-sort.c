#include <stdio.h>
#include "arrayfunc.h"

void insertionSort(int *arr, int size) {
  int i, j;
  for(i = 1; i < size; i++) {
    int key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j -= 1;
    }
    arr[j + 1] = key;
    printArray(arr, size);
  }
}

int main() {
  int arr[] = {3, 5, 1, 10, 2};
  int arrSize = sizeof(arr)/sizeof(arr[0]);
  printArray(arr, arrSize);
  insertionSort(arr, arrSize);
  printArray(arr, arrSize);
  return 0;
}
