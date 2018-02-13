/*
  Problema de la mochila
  - Lista de objetos
      Contiene:
        1. Tamano - Si - (int)
        2. Valor - Vi
  - Tamano de mochila - S
  - Se neceista la suma maxima de un
    subconjunto de objetos del tamano total
    de la mochila

    por: Saul Ivan Flores
    matricula: 01217102
    Universidad Autonoma de Baja California
    contacto: flores.saul@uabc.edu.mx
*/
#include <stdio.h>
//funcion que determina que valor es mayor
int max(int a, int b) {
  return (a > b) ? a : b; //Si caso es verdadero retorna a
}

int backpack(int maxWeight, int itemWight[], int itemVal[], int n) {
  //Base del algoritmo
  if(n == 0 || maxWeight == 0)
    return 0;
  if(itemWight[n - 1] > maxWeight)
    return backpack(maxWeight, itemWight, itemVal, n - 1);
  //Se compara el maximo utilzando el resultado de la misma funcion tomando en cuenta
  //el penultimo valor y otro sin y el mayor es el que se regresa
  else {
    return max( itemVal[n-1] + backpack(maxWeight-itemWight[n-1], itemWight, itemVal, n-1), backpack(maxWeight, itemWight, itemVal, n-1));
  }
}

int main() {
  int i, size, maxWeight = 50; //peso maximo que puede contener la mochila
  int arr_values[] = { 60, 100, 120 }; //array de valores
  int arr_weight[] = { 10, 20, 30 }; //Array de pesos
  //Ambos arrays tienen que tener el orden y tamano igual
  size = sizeof(arr_weight)/sizeof(arr_weight[0]); //tamano de array
  printf("%d\n", backpack(maxWeight, arr_weight, arr_values, size)); //se imprime el total de valores sumado dependienod del peso
  return 0;
}
