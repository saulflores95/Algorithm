/*
    Colas estaticas y dinamicas
    por: Saul Ivan Flores
    matricula: 01217102
    Universidad Autonoma de Baja California
    contacto: flores.saul@uabc.edu.mx

    comando de compilacion: 'gcc -o main colas.c  ./universales/menu.c ./universales/titles.c'
    comando de ejecucion: './main'
*/

#include <stdio.h>
#include <stdlib.h>
#include "./universales/menu.h"   //  Se incluye manejador de menus
#include "./universales/titles.h" //  Se incluye manejador de titulos
//  Inicio de declaraciones implicitas
void printArray(int *A, int size);
void ins_cola(int cola[], int *fin, int valor, int n);
int pop(int cola[], int *tope, int n);
void insColaCircular(int cola[], int *inicio, int *fin, int valor, int n);
int extColaCircular(int cola[], int *inicio, int *fin, int n);
void handleStatic();
void handleCircular();
//  Fin de declaraciones implicitas

int main() {
  printTitle("Colas Circulares y Estaticas"); // funcion de impresion de titulo de libreria de titulos
  char options[3][WORDMAX] = {"Estaticas", "Circulares", "Salir"}; // se generar opciones de menu
  int menuSize = sizeof(options)/sizeof(options[0]); //se determina el tamano del arreglo de opciones
  menu staticMenu = generateMenu(menuSize, options); //se genera una estructura tipo menu
  int boolean = 1; //se delaran el tamano del arreglo el valor extracion y el boolean para el loop del menu
  while (boolean) { //while loop para el menu, si se iguala el booleano a 0 se sale del menu
    int selectedOption = printMenu(staticMenu); //impresion de menu a igual que el valor de seleccion del menu
    switch (selectedOption) {
      case 1: //caso uno - Colas Estaticas
        handleStatic();
        break;
      case 2: //caso dos - Colas Circular
        handleCircular();
        break;
      case 3: //caso tres- salida
        printf("Bye bye...\n");
        boolean = 0; //cambio de valor para salir de while loop
        break;
      default: //caso default
        printf("Valor no valido...\n");
        break;
    }
  }
  return 0;
}
//  impresion de un arreglo de enteros
void printArray(int *A, int size) {
    int i;  //  valor de iterador
    for (i=0; i < size; i++)
      printf("%d ", A[i]); // se imprime cada elemento del arreglo
    printf("\n"); //  se imprime un espacio para mejor visualizacion
}
//  insertar valor entero a cola estatica
void ins_cola(int cola[], int *fin, int valor, int n) {
  if(*fin < (n - 1)) // si el fin de la cola es menor al tamano total del arreglo
    cola[++(*fin)] = valor; // se agrega el valor al arreglo y se icrementa el fin
  else
    printf("%s\n", "Cola llena"); // si el fin es valor al tamno del arreglo la cola esta llena
}
//  extraer primer valor entero en cola estatica
int pop(int cola[], int *tope, int n) {
  int tmp, i; //  declaracion de variable temporal eh iterador
  if(*tope == -1) { //  si el valor del tope es -1 la cola se considera vacia
    printf("%s\n", "La cola esta vacia");
    return -1;
  } else {
    tmp = cola[0]; // se iguala tmp a el primer valor de la cola para extraer
    for(i = 0; i < n ; i++) {
      cola[i] = cola[(i+1)]; // se recoren todos los valores hacia la izquierda de la pila
    } //  y se pierde el primer valor de la cola
    (*tope)--; // se decrementa el fin de la pila

  }
  printf("Valor Pop:%d\n", tmp); // impresion de valor extraido
  return tmp; //  se retorna el valor extraido
}
//  insertar valor entero a cola circular
void insColaCircular(int cola[], int *inicio, int *fin, int valor, int n) {
  int pos; //declaracion de posicion actual
  pos = (++(*fin) % n); // si el resdiduo va ser diffrente a inicio
  if(pos == (*inicio)) //si pos es iugal a inicio la cola esta llena
    printf("Cola llena\n");
  else {  //en el caso que no sea igual
    if(*inicio == -1)   //inicio se iguala pos
      *inicio = pos;
    *fin = pos;   //el fin a la posicion actual a si poder avansar en los espacios de memoria de la cola
    cola[pos] = valor; //se ingresa el valor a la posicion actual de la cola
  }
}
//  extrar valor entero de cola cicular
int extColaCircular(int cola[], int *inicio, int *fin, int n) {
  int re_val, pos; // se decalra valor a regresar y posicion
  if(*inicio == -1) { //  si incio es iguala menos uno la cola esta vacia
    printf("Cola vacia\n");
    re_val = -1; // valor a regresar es -1
  } else { // en el caso que no sea
    pos = *inicio; // el posicion es la mimma que inicio
    if(*inicio == *fin) //  en el caso que sea el mismo se iugala inicio y fin
      *inicio = *fin = -1;//  esto para indicar que la cola se vacio
    else {
      *inicio = ((*inicio)++) % n; //si la cola no se a vaciado se incrementa inicio
    }
    re_val = cola[pos]; //se iguala extacion a la posicion actual de la cola
  }
  printf("Poped value: %d\n", re_val); //impresion de valor extraido
  return re_val; //se regresa valor
}
//  manejador de colas estaticas
void handleStatic() {
  printTitle("Colas Estaticas"); // funcion de impresion de titulo de libreria de titulos
  int i, n = 4; //  decclaracion de iterador y tamano del arreglo
  int arr[n]; //  declaracion de arreglo
  int fin = -1;
  char options[4][WORDMAX] = {"Push", "Pop", "Imprimir", "Salir"}; // se generar opciones de menu
  int menuSize = sizeof(options)/sizeof(options[0]); //se determina el tamano del arreglo de opciones
  menu staticMenu = generateMenu(menuSize, options); //se genera una estructura tipo menu
  int boolean = 1; //se delaran el tamano del arreglo el valor extracion y el boolean para el loop del menu
  while (boolean) { //while loop para el menu, si se iguala el booleano a 0 se sale del menu
    int selectedOption = printMenu(staticMenu); //impresion de menu a igual que el valor de seleccion del menu
    switch (selectedOption) {
      case 1: //caso uno - push colas estaticas
        ins_cola(arr, &fin, 10, n);
        break;
      case 2: //caso dos - pop colas estaica
        pop(arr, &fin, n);
        break;
      case 3: //caso tres- Impresion
        printArray(arr, n);
        break;
      case 4: //caso tres- salida
        printf("Bye bye...\n");
        boolean = 0; //cambio de valor para salir de while loop
        break;
      default: //caso default
        printf("Valor no valido...\n");
        break;
    }
  }
}
// manejador de colas circulares
void handleCircular() {
  int inicio, fin, size = 5; // declaracion de inicion, fin, y tamano de arreglo
  int cola[size];//  declaracion de arreglo
  inicio = fin = -1;
  printTitle("Colas Circulares"); // funcion de impresion de titulo de libreria de titulos
  char options[4][WORDMAX] = {"Push", "Pop", "Imprimir", "Salir"}; // se generar opciones de menu
  int menuSize = sizeof(options)/sizeof(options[0]); //se determina el tamano del arreglo de opciones
  menu staticMenu = generateMenu(menuSize, options); //se genera una estructura tipo menu
  int boolean = 1; //se delaran el tamano del arreglo el valor extracion y el boolean para el loop del menu
  while (boolean) { //while loop para el menu, si se iguala el booleano a 0 se sale del menu
    int selectedOption = printMenu(staticMenu); //impresion de menu a igual que el valor de seleccion del menu
    switch (selectedOption) {
      case 1: //caso uno - push colas circulares
        insColaCircular(cola, &inicio, &fin, 15, size);
        break;
      case 2: //caso dos - pop colas ciruclares
        extColaCircular(cola, &inicio, &fin, size);
        break;
      case 3: //caso tres- Impresion
        printArray(cola, size);
        break;
      case 4: //caso tres- salida
        printf("Bye bye...\n");
        boolean = 0; //cambio de valor para salir de while loop
        break;
      default: //caso default
        printf("Valor no valido...\n");
        break;
    }
  }
}
