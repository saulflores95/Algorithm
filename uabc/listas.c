#include <stdio.h>
#include <stdlib.h>

struct nodoLista {
  int dato;
  struct nodoLista *sig;
};

typedef struct nodoLista nodoLista;

void ins(nodoLista **lista, int valor, int pos) {
  int i = 0;
  nodoLista *ant, *act, *nodoNuevo;
  ant = NULL;
  act = (*lista);
  nodoNuevo = (nodoLista*)malloc(sizeof(nodoLista));
  nodoNuevo -> dato = valor;
  while(i < pos && act != NULL) {
    ant = act;
    act = act -> sig;
    i++;
  }
  if(ant == NULL)
    *lista = nodoNuevo;
  else {
    ant -> sig = nodoNuevo;
    nodoNuevo -> sig = act;
  }
}

void eliminarNodo(nodoLista **lista, int pos) {
  nodoLista *ant, *act;
  int i = 0;
  ant = NULL;
  act = *lista;
  while(i < pos && (act = NULL)) {
    ant = act;
    act = act ->  sig;
    i++;
  }
  if(ant == NULL)
    *lista = (*lista) -> sig;
  else
    *ant -> sig = *act -> sig;
  free(act);
}

void impresion(nodoLista *lista) {
  int i = 0;
  while(lista != NULL) {
    printf("%d\n", lista -> dato);
    lista = lista -> sig;
  }
  if(lista == NULL) {
    printf("Lista terminada\n");
  }
}

void main() {
  nodoLista *lista = NULL;
  ins(&lista, 77, 0);
  ins(&lista, 42, 1);
  ins(&lista, 35, 1);
  impresion(lista);
  eliminarNodo(&lista, 1);
  impresion(lista);
}
