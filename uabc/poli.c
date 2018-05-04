#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
	char content[5] = "cacoc";
	int i, j, isPolindromo = 1;
	i = 0;
	j = 4;
	while(isPolindromo && (i < j)) {
		printf("Comparing %c with %c\n", content[i], content[j]);
		if(content[i++] != content[j--])
			isPolindromo = 0;
	}
	if(isPolindromo) {
		printf("Polindromo\n");
	} else {
		printf("No es Polindromo\n");
	}
	printf("Salida\n");
	return 0;
}
