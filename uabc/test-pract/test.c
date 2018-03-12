#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *prev;
  struct node *next;
  int data;
};

struct node* head;

struct node * nodeGen(int x) {
  struct node * newNode = (struct node *)malloc(sizeof(struct node));
  newNode -> data = x;
  newNode -> prev = NULL;
  newNode -> next = NULL;
  return (newNode);
}

void insHead(int x) {
    struct node * newNode = nodeGen(x);
    if(head == NULL) {
      head = newNode;
      return;
    }
    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;
}

void insTail(int x) {
  struct node * newNode = nodeGen(x);
  struct node * tmpNode = head;
  if(head == NULL) {
    head = newNode;
    return;
  }
  while (tmpNode -> next != NULL) {
    tmpNode = tmpNode -> next;
  }
  tmpNode -> next = newNode;
  newNode -> prev = tmpNode;
}

void ins(int pos, int x) {
  int n = 0;
  struct node * newNode = nodeGen(x);
  struct node * prev, * act;
  act = head;
  while(n != pos) {
    prev = act;
    act = act -> next;
    n++;
  }
  prev -> next = newNode;
  newNode -> prev = prev;
  act -> prev = newNode;
  newNode -> next = act;
}

void foward(){
  struct node * printNode = head;

  while(printNode != NULL) {
    printf("%d, ", printNode -> data);
    printNode = printNode -> next;
  }
  printf("\n");
}

void back() {
  struct node * printNode = head;
  while(printNode -> next != NULL) {
    printNode = printNode -> next;
  }
  while (printNode != NULL) {
    printf("%d, ", printNode -> data);
    printNode = printNode -> prev;
  }
  printf("\n");
}

void delete(int data) {
  if(head == NULL) {
    printf("Lista vacia\n");
    return;
  }
  struct node * act = head;
  struct node * prev;
  while (act -> data != data && act -> next != NULL) {
    prev = act;
    act = act -> next;
  }
  if(act -> next == NULL) {
    printf("El dato no se encuentra en la lista\n");
    return;
  } else {
    int reVal = act-> data;
    act = act -> next;
    act -> prev = prev;
    prev -> next = act;
    printf("Valor elimando: %d\n", reVal);
  }
}

int main(int argc, char const *argv[]) {
  int i;
  for(i; i < 10; i++) {
    insHead(i);
  }
  ins(5, 100);
  printf("Impresion hacia adelante\n");
  foward();
  printf("Impresion hacia atras\n");
  back();
  delete(100);
  delete(33);
  printf("Impresion hacia adelante\n");
  foward();
  printf("Impresion hacia atras\n");
  back();
  return 0;
}
