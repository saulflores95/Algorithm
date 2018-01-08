#include <stdio.h>

int main() {
  int num = 5;
  int *numPointer = NULL;
  printf("Number: %d\n", num); //View value of variable num
  printf("Address of var variable: %p\n", &num); //prints address of variables

  numPointer = &num; //store address in pointer variable
  printf("numPointer: %p\n", numPointer);
  /* access the value using a pointer*/
  printf("value of stored in *numPointer: %d\n", *numPointer);
  /* modifiying a variable through a pointer*/
  *numPointer = 10;
  printf("value of stored in *numPointer: %d\n", *numPointer);
  printf("Number: %d\n", num); //View value of variable num
  return 0;
}
