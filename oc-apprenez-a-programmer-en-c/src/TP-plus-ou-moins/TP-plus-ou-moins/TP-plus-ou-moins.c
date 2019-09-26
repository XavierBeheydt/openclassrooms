#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mainv1()
{
	const int MIN = 1, MAX = 100;
	// Génération du nombre mystère
	srand(time(NULL));
	//int mysteryNb = (rand() % (MAX - MIN + 1)) + MIN;
	int mysteryNb = rand() % (MAX + MIN);

	int saisi = 0;
	while (saisi != mysteryNb)
	{
		printf("Veuillez entrer un chiffre entre 1 et 100 ? ");
		scanf_s("%i", &saisi);
		if (saisi < 1 || saisi > 100)
			printf("Vous avez saisi un mauvais chiffre!\n");
		else
		{
			if (saisi > mysteryNb)
				printf("Moins!\n");
			else
				printf("Plus!\n");
		}
	}

	printf("Bravo le chiffre etait %i", mysteryNb);

	return 0;
}

int main()
{
	int choix;

	printf("Choix de version ?\n");
	printf("\tVersion 1 - 1\n");
	printf("\tVersion 2 - 2\n");

	scanf_s("%i", &choix);

	system("@cls||clear");

	switch (choix)
	{
	case 1:
		mainv1();
	case 2:
		mainv2();
	default:
		return 0;
		break;
	}
}
