/*
funcion que recive 8 / 2 + 5

primero se capturan los operadores y luego los numeros
y imprimer posOrder

        /  <-  + -> 5
    8<- -> 2
*/

#include <stdio.h>
#include <stdlib.h>
//Comprobar que incercion hace lo que debe de hacer
typedef struct Node {
  int data;
  struct Node *left, *right;
} Node;

void ins();
void delete();
void inOrder();
void preOrder();
void posOrder();
int main() {
  printf("Arboles binarios de busqueda\n");
  Node *tree = NULL;
  ins(&tree, 10);
  ins(&tree, 50);
  ins(&tree, 30);
  delete(&tree, 30);
  inOrder(tree);
  return 0;
}
void ins(Node **root, int val) {
  Node *act, *ant;
  act  = *root;
  ant = NULL;
  while (act != NULL) {
    printf("Still in loop\n");
    ant = act;
    if(val > act-> data)
      act = act -> right;
    else
      act = act -> left;
  }
  act = (Node*)malloc(sizeof(Node));
  act->data = val;
  act-> left = act-> right = NULL;
  if(*root == NULL)
    *root = act;
  else {
    if(act -> data < ant -> data)
      ant -> left = act;
    else
      ant -> right = act;
  }
  printf("valor insertado: %d\n", act -> data);
}
void delete(Node **raiz, int val) {
  Node *ant, *act, *tmp;
  ant = NULL;
  act = *raiz;
  while((act != NULL) && (act->data != val)) {
    ant = act;
    if(val > act -> data)
      act = act -> right;
    else
      act = act -> left;
  }
  if(act == NULL)
    printf("No se encontro\n");
  else if((act -> right != NULL) && (act -> left != NULL)) {
    tmp = act -> right;
    while(tmp -> left != NULL)
      tmp = tmp -> left;
    act -> data = tmp -> data;
    delete(&(act->right), act->data);
  }
  else if(act -> right != NULL) {
    if(ant == NULL)
      *raiz = act -> right;
    if(act -> data > ant -> data)
      ant -> right = act -> right;
    else
      ant -> left = ant -> right;
  } else if(act -> left != NULL) {
    if(act -> data > ant-> data)
      ant -> right = act -> left;
    else
      ant -> left = act -> left;
  }
}
void inOrder(Node *root) {
  if(root != NULL) {
    inOrder(root -> left);
    printf("%d\n", root -> data);
    inOrder(root -> right);
  }
}
void posOrder(Node *root) {
  if(root != NULL) {
    posOrder(root -> left);
    posOrder(root -> right);
    printf("%d\n", root -> data);
  }
}

void preOrder(Node *root) {
  if(root != NULL) {
    printf("%d\n", root -> data);
    preOrder(root -> left);
    preOrder(root -> right);
  }
}
