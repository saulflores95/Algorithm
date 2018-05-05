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

int printMenu(menu Menu) {
  int i, val;
  for(i = 0; i < Menu.numberOfOptions; i++)
    printf("\t%d) %s\n", i+1, Menu.options[i]);
  printf("Ingrese un valor:\n");
  scanf("%d", &val);
  return val;
}
