#include <stdio.h>
#include "./capture.h" //Se incluye la libreria con las dependencias de caputure.c

//Funcion capturadora de tipo float
float captureFloat() {
  float cap;
  scanf("%f", &cap);
  return cap;
}
//Funcion capturadora de tipo INT
int captureInt() {
  int cap;
  scanf("%d", &cap);
  return cap;
}
//Funcion seleccionadora de tipos
float capture(char *type) { //se utiliza un apuntador para poder comparar el string
  if (type == "f") { //Se compara si la variable tipo es igual a f
    printf("\n\t%s\n", "Ingrese el valor tipo float");
    return captureFloat(); //se retorna el float capturado por la funcion capureFloat
  } else {
    printf("\n\t%s\n", "Ingrese el valor tipo int");
    return (int)captureInt(); //Se convierte el valor float y regresa tipo int
  }
}

void main() {
  int ans = capture("i");
  printf("%d\n", ans);
  float ansF = capture("f");
  printf("%f\n", ansF);
}
