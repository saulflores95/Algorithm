#include <stdio.h>
#include <string.h>
#include <time.h>
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

void shellShort();
void ansImpresion();
int main() {
  printTitle("Análisis de la Shell Sort");
  //int arr[] = {9, 7, 5, 2, 1, 4, 3, 6};   //base case
  //int arr[] = {1, 2, 3, 4, 5, 6, 7, 9};   //best case
  //int arr[] = {9, 7, 6, 5, 4, 3, 2, 1};   //worst case
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 9, 10};   //best case odd
  //int arr[] = {10, 9, 7, 6, 5, 4, 3, 2, 1};   //worst case odd

  int size = sizeof(arr)/sizeof(arr[0]);    //tamano del arreglo
  shellShort(arr, size);                    //se manda a llamar metodo de ordenamieto shellSort
  printf("\tTamano de arreglo:  %d\n", size); //impresion del tamano del arreglo
  return 0; //salida de funcion
}
//Funcion que ejecuta el metodo de ordenamieto shell sort
void shellShort(int arr[], int size) {
  printArray(arr, size);  //funcion impresion de arreglo declarada en lib array.c
  int i, j, middle, iterationCounter; //declaracion de funcion
  clock_t start = clock(); //inicio la variable tipo clock
  middle = size / 2 ;    //Se obtiene el punto medio de arreglo; si arreglo es impar ej. n = 7; n/2 = 3.5 se considera solo el 3 del resultado obtenido
  iterationCounter = 0; //contador de iteraciones
  for(middle; middle > 0; middle /= 2) { //ciclo for mientras middle sea mayor a cero al final de cada iteracion dividelo por 2
    for(i = middle; i < size; i++) { //mientras i sea menor al tamano total del arreglo incrementa i
      int tmp = arr[i]; //variable temporal almacena el valor en al posicion indicda, esto se utiliza para itercambiar valores en el arreglo
      for(j = i; j >= middle && arr[j - middle] > tmp; j -= middle) {
        arr[j] = arr[j - middle];
        printArray(arr, size); //impresion de arreglo en su estado actual
        iterationCounter++; //cantidad total de iteracion en el 3r for anidado
      }
      arr[j]  = tmp; // se le asigna el valor de tmp a la posicion j;
    }
  }
  clock_t end = clock(); //inicio variable tipo clock
  double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
  ansImpresion(timeSpent, iterationCounter);  //mando valores obtenidos a funcion impresora de rsultado
}

void ansImpresion(double timeSpent, int i) {
  printf("\n\n");
  printf("\tTiempo de ejecucion: %f\n", timeSpent);
  printf("\tCantidad de iteraciones: %d\n", i);
}
