#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "./universales/menu.h" //  se incluye libreria de generacion eh impresion de menus
#include "./universales/titles.h"// se incluye para impresion de titulos
#include "./universales/array.h"// se incluye para impresion de titulos

/*
  COMPILACION DEL PROGRAMA:
  1. Acceder al root del projecto
  2. ejecutar siguente comando en terminal
      "gcc -o main main.c ./universales/menu.c ./universales/titles.c ./universales/array.c"
  3. Ejecutrar comando de ejecucion
      "./main"
*/
void binarySearchAnalisis();
int binarySearch();
void interSearchAnalisis();
int interSearch();
void ansImpresion();

int main() {
  printTitle("Análisis de la Algoritmos Empirico");
  int arr[20];  //se rellena arreglo de 20 posiciones
  int i = 0;
  int valToSearch = 19;
  //utilizando un ciclo rellenamos arreglo
  for(i; i < 20; i++)
    arr[i] = i;
  int size = sizeof(arr)/sizeof(arr[0]); //se calcula tamano de arreglo
  //binarySearchAnalisis(arr, size, valToSearch);
  interSearchAnalisis(arr, size, valToSearch);
  return 0; //salida de funcion
}

void binarySearchAnalisis(int arr[], int size, int val) {
  printTitle("Analisis de Binario");
  int iterationCounter = 0;
  clock_t start = clock(); //inicio la variable tipo clock
  int posDeValor = binarySearch(arr, 0, size - 1, val, &iterationCounter); //se asigna la posicion del valor que se desea buscar si no esa retorna -1
  clock_t end = clock(); //inicio variable tipo clock
  double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
  if(posDeValor == -1) //en caso que posicion de valor sea igual a menos 1 deplegar que el elemenot no esta en la lista
    printf("Valor ingresado no esta presente en la tabla...\n");
  else
    printf("arr[%d] = %d\n", posDeValor, arr[posDeValor]);
  ansImpresion(timeSpent, iterationCounter);

}

int binarySearch(int arr[], int start, int end, int val, int *iterationCounter) {
  *iterationCounter += 1;
  if(end >= start) {
    int newMiddle = start + (end - start)/2;
    if(arr[newMiddle] == val)
      return newMiddle;
    if(arr[newMiddle] > val)
      return binarySearch(arr, start, newMiddle - 1, val, iterationCounter);
    return binarySearch(arr, newMiddle + 1, end, val, iterationCounter);
  }
  return -1;  //Si el elemento no esta presente retornar -1
}

void interSearchAnalisis(int arr[], int size, int val) {
  printTitle("Analisis de Interpolado");
  int iterationCounter = 0;
  LARGE_INTEGER t_ini, t_fin;
  double secs;
  QueryPerformanceCounter(&t_ini);
  int posDeValor = interSearch(arr, 0, size - 1, val, &iterationCounter); //se asigna la posicion del valor que se desea buscar si no esa retorna -1
  QueryPerformanceCounter(&t_fin);
  secs = performancecounter_diff(&t_fin, &t_ini);
  printf("\n%.16g", secs * 1000.0);
  if(posDeValor == -1) //en caso que posicion de valor sea igual a menos 1 deplegar que el elemenot no esta en la lista
    printf("Valor ingresado no esta presente en la tabla...\n");
  else
    printf("arr[%d] = %d\n", posDeValor, arr[posDeValor]);
  //ansImpresion(timeSpent, iterationCounter);
}

int interSearch(int arr[], int start, int end, int val, int *iterationCounter) {
  *iterationCounter += 1;
  if(end >= start) {
    if((arr[end] - arr[start]) <= 0)
      return -1;
    int newMiddle = start + (end - start)*(val - arr[start]) / (arr[end] - arr[start]);
    if(arr[newMiddle] == val)
      return newMiddle;
    if(arr[newMiddle] > val)
      return interSearch(arr, start, newMiddle - 1, val, iterationCounter);
    return interSearch(arr, newMiddle + 1, end, val, iterationCounter);
  }
  return -1;  //Si el elemento no esta presente retornar -1
}

void ansImpresion(double timeSpent, int i) {
  printf("\n\n");
  printf("\tTiempo de ejecucion: %0.9f\n", timeSpent);
  printf("\tCantidad de iteraciones: %d\n", i);
}

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b) {
  LARGE_INTEGER freq;
  QueryPerformanceCounter(&freq);
  return (double)(a->QuadPart - b ->QuadPart) / (double)freq.QuadPart;
}
