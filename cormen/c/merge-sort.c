#include <stdlib.h>
#include <stdio.h>

void printArray(int *A, int size) {
    int i;
    for (i=0; i < size; i++)
      printf("%d ", A[i]);
    printf("\n");
}

void merge(int * arr, int p, int q, int r) {
  int i, j, k;
  int n1 = q - p + 1;
  int n2 = r - q;
  int left[n1 + 1], right[n2 + 1];

  left[n1] = right[n2] = 999999;
  for(i = 0; i < n1; i++)
   left[i] = arr[p + i];
  for(j = 0; j < n2; j++)
    right[j] = arr[q + j + 1];

  i = j = 0;
  k = p;
  
  do {
    if(left[i] <= right[j]){
      arr[k] = left[i++];
    } else {
      arr[k] = right[j++];
    }
    k++;
  } while (k <= r);

  /*Same step but with a for
    for(k = p; k <= r; k++){
      if(left[i] <= right[j]){
        arr[k] = left[i];
        i++;
      } else {
        arr[k] = right[j];
        j++;
      }
    }
  */
}

int merge_sort(int arr[], int p, int r) {
  if(p < r) {
    int q = (p + r) / 2;
    merge_sort(arr, p, q);
    merge_sort(arr, q + 1, r);
    merge(arr, p, q, r);
  }
  return 0;
}

int main() {
  int arr[] = {1, 4, 3, 100, 50, 52, 10, 55, 8};
  int arrTwo[] = {10, 22, 11, 30, 400, 509};
  int size = sizeof(arr)/sizeof(arr[0]);
  int middle = size / 2;
  printArray(arr, size);
  merge_sort(arr, 1, size);
  printArray(arr, size);
  return 0;
}
