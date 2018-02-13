#include <stdio.h>
#include <string.h>
#include "./menu.h"

menu generateMenu(int numberOfOptions, char arr_opt[OPTIONMAX][WORDMAX]) {
  menu Menu;
  int i = 0;
  Menu.numberOfOptions = numberOfOptions;
  for(i = 0; i < numberOfOptions; i++) {
    strcpy(Menu.options[i], arr_opt[i]);
  }
  return Menu;
}

void printMenu(menu Menu) {
  int i;
  for(i = 0; i < Menu.numberOfOptions; i++)
    printf("\t%d) %s\n", i+1, Menu.options[i]);
}

void main() {
  char options[3][WORDMAX] = {"Capturar", "Preguntas", "Salir"};
  int size = sizeof(options)/sizeof(options[0]);
  menu staticMenu = generateMenu(size, options);
  printMenu(staticMenu);
  //menu(menu, size);
}
