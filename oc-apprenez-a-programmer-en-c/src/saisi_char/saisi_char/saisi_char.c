#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char nom[100] = "";
	printf("Veuillez saisir votre nom : ");
	scanf("%s", nom);
	printf("\nVotre nom est : %s\n", nom);
	return 0;
}
