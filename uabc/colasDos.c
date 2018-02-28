#include <stdio.h>
#include "./universales/menu.h" //Se incluye manejador de menus
/*
  typedef struct nodoPila{
    int dato;
    nodoPila *sig;
  };

  void push(nodoPila **tope, int valor) {
    nodoPila *nodoNuevo;
    nodoNuevo = (nodoPila*)malloc(sizeof(nodoPila));
    nodoNuevo -> dato = valor
    nodoNuevo -> sig = (*tope)
    (*tope) = nodoNuevo;
  }
*/

//funcion que imprime titulos
void printTitle(char *string) {
  printf("**************************\n");
  printf("********%s********\n", string);
  printf("**************************\n");
}
//funcion que imprime arreglos
void printArray(int A[], int size) {
  int i; //valor inicial de iterador
  for (i=0; i < size; i++)
    printf("%d ", A[i]); //se imprime todos los valors del arreglo
  printf("\n"); //espacio para finalizacion de funcion
}
//funcion de colas estaticas
int StaticQueue(int arr[], int *n) {
  int i, tmpVal = arr[0]; //se declaran las variables: iteradora y de extracion
  for(i = 0; i < *n; i++) {
    arr[i] = arr[(i+1)];  //se iguala valor actual con el valor siguente
    printf("arr[%d] = %d\n", i , arr[i]); //impresion de pasos que toman el algoritmos
  }
  (*n)--; //se disminuye el tope del arreglo
  return tmpVal; //se regresa el valor de extraido de la pila
}
//funcion de colas dynamicas
int DynamicQueue() {
  int i, tmpVal = 0; //se declaran las variables: iteradora y de extracion
  return tmpVal;  //se regresa el valor de extracion de la pila
}

void main() {
  char options[3][WORDMAX] = {"Estaticas", "Dinamicas", "Salir"}; // se generar opciones de menu
  int menuSize = sizeof(options)/sizeof(options[0]); //se determina el tamano del arreglo de opciones
  menu staticMenu = generateMenu(menuSize, options); //se genera una estructura tipo menu
  int size, val, boolean = 1; //se delaran el tamano del arreglo el valor extracion y el boolean para el loop del menu
  int arr[] = {1, 3, 10}; // se decalra arreglo de 3 posiciones
  while (boolean) { //while loop para el menu, si se iguala el booleano a 0 se sale del menu
    int selectedOption = printMenu(staticMenu); //impresion de menu a igual que el valor de seleccion del menu
    switch (selectedOption) {
      case 1: //caso uno - pilos estaticas
        size = sizeof(arr)/sizeof(arr[0]);
        printTitle("Estaticas");
        printf("Starting Array:\n");
        printArray(arr, size);
        val = StaticQueue(arr, &size);
        printf("Extracted Value: %d\n", val);
        printf("Finished  Array:\n");
        printArray(arr, size);
        break;
      case 2: //caso dos - pilos Dinamicas
        printTitle("Dinamicas");
        char dyOptions[3][WORDMAX] = {"Agregar", "Quitar", "Salir"}; //generar opciones de menu para colas dinamicas
        int dyMenuSize = sizeof(dyOptions)/sizeof(dyOptions[0]); //determinar tamano de menu
        menu dynamicMenu = generateMenu(dyMenuSize, dyOptions); //generar menu para colas dinamicas
        int selectedOption = printMenu(dynamicMenu); //impresion de menu y seleccion de opcion
        break;
      case 3: //caso tres- salida
        printf("Bye bye...\n");
        boolean = 0; //cambio de valor para salir de while loop
        break;
      default: //caso default
        printf("Default value...\n");
        break;
    }
  }
}
