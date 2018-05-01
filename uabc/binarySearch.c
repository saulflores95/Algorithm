#include <stdio.h>
#include <stdlib.h>
//Recursivo
int busquedaBinaria(int arreglo[], int inicio, int fin, int valor) {
  int resultado;
  int centro;
  if(inicio <= fin) {
    centro = (fin + inicio) / 2;
    if(arreglo[centro] == valor)
      resultado = centro;
    else if(arreglo[centro] > valor)
      resultado = busquedaBinaria(arreglo, inicio, centro-1, valor);
    else
      resultado = busquedaBinaria(arreglo, centro+1, fin, valor);
  } else
    resultado = -1;
  return resultado;
}
//No Recursivo
int busquedaBinariaNo(int arr[], int inicio, int fin, int val) {
  int resultado;
  int centro;
  int isVal;
  while(arr[isVal] != val) {
    if(inicio <= fin) {
      centro = (inicio + fin) / 2;
      if(arr[centro] == val)
        isVal = centro;
      else if(arr[centro] > val){
        fin = centro--;
      } else {
        inicio = centro + 1;
      }
    } else
      centro = -1;
  }
  return centro;
}
int main() {
  int arr[8] = { 1, 3, 4, 5, 55, 75, 111, 999 };
  printf("%d\n", busquedaBinariaNo(arr, 0, 8, 999));
  return 0;
}
