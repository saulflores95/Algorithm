#ifndef _menu_h
#define _menu_h
#define WORDMAX 10
#define OPTIONMAX 10

typedef struct {
  int numberOfOptions;
  char options[OPTIONMAX][WORDMAX];
} menu;

menu generarMenu(int numberOfOptions, char arr_opt[OPTIONMAX][WORDMAX]);

void printMenu(menu Menu);

#endif
