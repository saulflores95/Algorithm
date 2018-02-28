#include <stdio.h>
#include <stdlib.h>
#include "./universales/menu.h" //Se incluye manejador de menus
#include "./universales/titles.h" //  Se incluye manejador de titulos
//  Declaracion de funciones de pilas estaticas utilizadas
void printArray(int A[], int size);
int popStaticStack(int arr[], int *n);
void pushStaticStack(int arr[], int*n, int size);
void StaticStackHandle();
//  declaracion de funciones de pilas dinamicas
void DynamicStackHandle();
int popDynamicStack();
void pushDynamicStack();
void impresionDynamicStack();
//estructura de pila dinamica
struct pila{
  int data;
  struct pila *next;
};

struct pila *top = NULL; //se iniciliza la estructura de pilas dinamicas

void main() {
  char options[3][WORDMAX] = {"Estaticas", "Dinamicas", "Salir"}; // se generar opciones de menu
  int menuSize = sizeof(options)/sizeof(options[0]); //se determina el tamano del arreglo de opciones
  menu staticMenu = generateMenu(menuSize, options); //se genera una estructura tipo menu
  int boolean = 1; //se delaran el tamano del arreglo el valor extracion y el boolean para el loop del menu
  while (boolean) { //while loop para el menu, si se iguala el booleano a 0 se sale del menu
    int selectedOption = printMenu(staticMenu); //impresion de menu a igual que el valor de seleccion del menu
    switch (selectedOption) {
      case 1: //caso uno - pilos estaticas
        StaticStackHandle();
        break;
      case 2: //caso dos - pilos Dinamicas
        DynamicStackHandle();
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
}
// Menu de manjeo de pilas estaticas
void StaticStackHandle() {
  int arr[] = {1, 3, 10}; // se decalra arreglo de 3 posiciones
  int val, size = sizeof(arr)/sizeof(arr[0]);
  int sizeMax = size;
  printTitle("Estaticas");
  printf("Starting Array:\n");
  printArray(arr, size);
  char options[4][WORDMAX] = {"Push", "Pop", "Impresion", "Salir"}; // se generar opciones de menu
  int menuSize = sizeof(options)/sizeof(options[0]); //se determina el tamano del arreglo de opciones
  menu Menu = generateMenu(menuSize, options); //se genera una estructura tipo menu
  int boolean = 1; //se delaran el tamano del arreglo el valor extracion y el boolean para el loop del menu
  while (boolean) { //while loop para el menu, si se iguala el booleano a 0 se sale del menu
    int selectedOption = printMenu(Menu); //impresion de menu a igual que el valor de seleccion del menu
    switch (selectedOption) {
      case 1: //caso uno - push pilas estaticas
        pushStaticStack(arr, &size, sizeMax);
        printf("Finished  Array:\n");
        printArray(arr, size);
        break;
      case 2: //caso dos - push pilas estaticas
        val = popStaticStack(arr, &size);
        printf("Extracted Value: %d\n", val);
        printf("Finished  Array:\n");
        printArray(arr, size);
        break;
      case 3:
        printArray(arr, size);
        break;
      case 4: //caso tres- salida
        printf("Salida de pilas estaticas...\n");
        boolean = 0; //cambio de valor para salir de while loop
        break;
      default: //caso default
        printf("Valor no valido, seleccione una opcion...\n");
        break;
    }
  }

}
//  funcion pop de pilas estaticas
int popStaticStack(int arr[], int *n) {
  int tmpVal;
  if(*n <= -1) {
      tmpVal = 0;
      printf("Pila vacia...\n");
  } else {
    tmpVal = arr[--(*n)];//se declaran las variables de extracion
  }
  return tmpVal; //se regresa el valor de extraido de la pila
}
//  funcion push de pilas estaticas
void pushStaticStack(int arr[], int *n, int size) {
  int value;
  printf("Ingrse un valor: \n");
  scanf("%d", &value);
  if(*n < (size)) {
    arr[++(*n)] = value;
  }
  else
    printf("%s\n", "Pila llena");
}
//  manejador de pilas dynamicas
void DynamicStackHandle() {
  printTitle("Dinamicas");
  char options[4][WORDMAX] = {"Push", "Pop", "Impresion", "Salir"}; // se generar opciones de menu
  int menuSize = sizeof(options)/sizeof(options[0]); //se determina el tamano del arreglo de opciones
  menu Menu = generateMenu(menuSize, options); //se genera una estructura tipo menu
  int boolean = 1; //se delaran el tamano del arreglo el valor extracion y el boolean para el loop del menu
  while (boolean) { //while loop para el menu, si se iguala el booleano a 0 se sale del menu
    int selectedOption = printMenu(Menu); //impresion de menu a igual que el valor de seleccion del menu
    switch (selectedOption) {
      case 1: //caso uno - push pilas dinamicas
        pushDynamicStack();
        break;
      case 2: //caso dos - pop pilas dinamicas
        popDynamicStack();
        break;
      case 3: //caso tres - impreson de pila dinamica
        impresionDynamicStack();
        break;
      case 4: //caso tres- salida
        printf("Salida de pilas dinamicas...\n");
        boolean = 0; //cambio de valor para salir de while loop
        break;
      default: //caso default
        printf("Valor no valido, seleccione una opcion...\n");
        break;
    }
  }
}
//  funcion que imprime arreglos
void printArray(int A[], int size) {
  int i; //valor inicial de iterador
  for (i=0; i < size; i++)
    printf("%d ", A[i]); //se imprime todos los valors del arreglo
  printf("\n"); //espacio para finalizacion de funcion
}
//  funcion pop de pilas dinamicas
int popDynamicStack() {
  int re_val;
  if(top == NULL) {
    printf("Pila vacia\n");
    re_val = 0;
  } else {
      struct pila *tmpPila; //  genero pila temporal
      tmpPila = top;//  igualo top a pila temporal
      top = top->next; //igual top a su valor siguente, y se elimina el valor actual
      printf("\nValor extraido: %d\n", tmpPila->data); //imprimo valor de top previo
      free(tmpPila); //libro direccion de memoria de top previo
      re_val = tmpPila -> data;
  }
  return re_val;
}
//  funcion pop de pilas estaticas
void pushDynamicStack() {
  printf("Agregue valor a agregar\n");
  int value;
  scanf("%d", &value);
  struct pila *ptr = malloc(sizeof(struct pila));
  ptr -> data = value;
  ptr -> next = top;
  top = ptr;
}
// funcion de impresion dinamica
void impresionDynamicStack() {
  struct pila *tmp;
  tmp = top;
  if(tmp == NULL)
    printf("Pila vacia\n");
  while (tmp != NULL)
  {
      printf("%d, ", tmp->data);
      tmp = tmp->next;
  }
}
