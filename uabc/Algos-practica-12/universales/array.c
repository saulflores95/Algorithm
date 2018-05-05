#include <stdio.h>
#include "./array.h" //Se incluye la libreria con las dependencias de caputure.c

void printArray(int A[], int size) {
  int i; //valor inicial de iterador
  for (i=0; i < size; i++)
    printf("%d ", A[i]); //se imprime todos los valors del arreglo
  printf("\n"); //espacio para finalizacion de funcion
}


void printFloatArray(float A[], int size) {
  int i; //valor inicial de iterador
  for (i=0; i < size; i++)
    printf("%.2f ", A[i]); //se imprime todos los valors del arreglo
  printf("\n"); //espacio para finalizacion de funcion
}

void printCharArray(char arr[], int size) {
  int i; //valor inicial de iterador
  for (i=0; i < size; i++)
    printf("%c", arr[i]);
  printf("\n"); //espacio para finalizacion de funcion
}
