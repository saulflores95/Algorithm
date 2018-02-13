#include <stdio.h>
int factorial(int n) {
  printf("%d\n", n);
  if(n > 1) {
    return n * factorial(n-1);
  }else {
    return 1;
  }
}

void main() {
  int n = 5;
  factorial(5);
}
