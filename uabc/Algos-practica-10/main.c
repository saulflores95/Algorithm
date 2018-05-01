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

void insertionSort();
void insertionCharSort();
void ansImpresion();

int main() {
  printTitle("Análisis de la eficiencia");
  char charArrBest[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";   //best case
  char charArrWorst[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";   //worst case
  int sizeofBest = sizeof(charArrBest)/sizeof(charArrBest[0]); //tamano de arreglo peor de los casos
  int sizeofWorst = sizeof(charArrWorst)/sizeof(charArrWorst[0]); //tamano arreglo de mejor de los casos
  printf("Mejor de los casos\n");
  insertionCharSort(charArrBest, sizeofBest); //insertion sort mejor de los casos con arreglo de candenas
  printf("Peor de los casos\n");
  insertionCharSort(charArrWorst, sizeofWorst);//inserstion sort pero de los casos arreglo de cadenas
  //verificar cambio con float
  float arr[sizeofBest];  //defino arreglo de flotantes con el mismo tamano que el arreglo de caracteres
  int i, j, k = 0;  //declaro las variables utilizadas para el relleno del arreglo
  printf("Mejor de los casos\n");
  for(i = 0; i < sizeofBest; i++) { //relleno el arreglo con los valors 0 -> 26
    arr[i] = i;
  }
  insertionSort(arr, sizeofBest); ///mando a llamar insertion sort modificada para recibir flotantes y ordenar el arreglo
  printf("Peor de los casos\n");
  for(j = i; j > 0; j--) { //relleno el mismo rreglo empezando de 26 -> 0 para verificar el peor de los casos
    arr[j] = k;//remplazo el valor ubicado en el arreglo por el valor en K
    k++; //aumento el valor de k
  }
  insertionSort(arr, sizeofBest); //mando a llamar insertion sort modificada para recibir flotantes y ordenar el arreglo
  return 0; //salida de funcion
}
//  Funcion que ordenadora de flotantes
void insertionSort(float arr[], int n) {
  printFloatArray(arr, n); //impresion de arreglo antes de ser ordenada
  clock_t start = clock(); //inicio la variable tipo clock
  int i, j, p;
  i = 0;
  float tmp;
  for(p = 1; p < n; p++) { //n + 2
    tmp = arr[p];          //n + 1
    for(j = p; j > 0 && tmp < arr[j -1 ]; j--) { //(n^2 + 3n)
      arr[j] = arr[j-1]; //n+2
    }
    arr[j] = tmp; //n+1
    i++;
  }
  clock_t end = clock(); //inicio variable tipo clock
  // (n + 2) + (n + 1) + (n^2 + 3n) + (n + 2) + (n + 1) = n^2 + 7n + 6
  double timeSpent = (double)(end - start) / CLOCKS_PER_SEC; //utilizo variables tipo clock para determinar el tiempo transcurrido por la funcion
  printFloatArray(arr, n); //imprimo resultado de arreglo despues de ser ordenada
  ansImpresion(timeSpent, i); //mando valores obtenidos a funcion impresora de rsultados
}
//  Funcion que ordena caracteres
void insertionCharSort(char arr[], int n) {
  printCharArray(arr, n);   //Impresion de arreglo de cadenas antes de ser ordenadas
  clock_t start = clock();
  int i, j, p;
  i = 0;
  int tmp;
  for(p = 1; p < n; p++) { //n + 2
    tmp = arr[p];          //n + 1
    for(j = p; j > 0 && tmp < arr[j -1 ]; j--) { //(n^2 + 3n)
      arr[j] = arr[j-1]; //n+2
    }
    arr[j] = tmp; //n+1
    i++;
  }
  clock_t end = clock();
  // (n + 2) + (n + 1) + (n^2 + 3n) + (n + 2) + (n + 1) = n^2 + 7n + 6
  double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;
  printCharArray(arr, n); //imprimo resultado de arreglo despues de ser ordenada
  ansImpresion(timeSpent, i);  //mando valores obtenidos a funcion impresora de rsultado
}
//  Funcion que imprime los resultados
void ansImpresion(double timeSpent, int i) {
  printf("\tTiempo de ejecucion: %f\n", timeSpent);
  printf("\tCantidad de iteraciones: %d\n", i);
  printf("\n\n");
}
