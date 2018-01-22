#include <stdio.h>
#include "arrayfunc.h"

void selectionSort(int *arr, int size) {
  int i, j, minIndex, tempVar;
  for(i = 0; i < size; i++){
    minIndex = i;
    for(j = i + 1; j < size; j++) {
      if(arr[minIndex] > arr[j]) {
        minIndex = j;
      }
    }
    if(minIndex != i){
      tempVar = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = tempVar;
    }
  }
}

void main() {
  int arr[] = {10, 11, 50, 3, 2, 40, 1, -1};
  int size = sizeof(arr)/sizeof(arr[0]);
  printArray(arr, size);
  selectionSort(arr, size);
  printArray(arr, size);
}
