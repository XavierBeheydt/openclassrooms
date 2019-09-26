#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// Les caractères d'échappement

	// New line
	printf("New line\n");

	// Tabulation
	printf("\tTabulation\n");

	// 
	printf("A\bdecouvrir\n");

	//
	printf("\r RR\n");

	//
	printf("\"Entre guillemet\"\n");

	//
	printf("\\ antislash\n");

	// caractère NULL le nullbyte
	printf("Fin de string\0\n");
	printf("\n");

	//
	printf("\a je ne sais pas\n");

	return 0;
}