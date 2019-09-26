#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

// Exercice 1
int sommeTableau(int tableau[], int tailleTableau);

// Exercice 2
double moyenneTableau(int tableau[], int tailleTableau);

// Exercice 3
void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau);

// Exercice 4
void maximumTableau(int tableau[], int tailleTableau, int valeurMax);

// Exercice 5
void ordonnerTableau(int tableau[], int tailleTableau);

int main()
{
	int tableau1[6] = { 45, 73, 25, 68, 9925, 23 };
	int tableau2[6];

	// Exercice 1
	printf("La somme du tableau est = %i\n", sommeTableau(tableau1, 6));

	// Exercice 2
	printf("La moyenne du tableau est = %f\n", moyenneTableau(tableau1, 6));

	// Exercice3
	copie(tableau1, tableau2, 6);
	printf("La copie du tableau est : ");
	for (size_t i = 0; i < 6; i++)
	{
		printf("%i,", tableau2[i]);
	}
	printf("\n");

	// Exercice 4
	maximumTableau(tableau2, 6, 67);
	printf("Mise a zero des valeur au dessus de 67 :");
	for (size_t i = 0; i < 6; i++)
	{
		printf("%i, ", tableau2[i]);
	}
	printf("\n");

	// Exercice 5
	ordonnerTableau(tableau1, 6);
	printf("Tableau ordonne : ");
	for (size_t i = 0; i < 6; i++)
	{
		printf("%i, ", tableau1[i]);
	}
	printf("\n");

	return 0;
}

// Exercice 1
int sommeTableau(int tableau[], int tailleTableau)
{
	int somme = 0;
	for (size_t i = 0; i < tailleTableau; i++)
	{
		somme += tableau[i];
	}

	return somme;
}

// Exercice 2
double moyenneTableau(int tableau[], int tailleTableau)
{
	return (double)sommeTableau(tableau, tailleTableau) / tailleTableau;
}

// Exercice 3
void copie(int tableauOriginal[], int tableauCopie[], int tailleTableau)
{
	for (size_t i = 0; i < tailleTableau; i++)
	{
		tableauCopie[i] = tableauOriginal[i];
	}
}

// Exercice 4
void maximumTableau(int tableau[], int tailleTableau, int valeurMaximum)
{
	for (size_t i = 0; i < tailleTableau; i++)
	{
		if (tableau[i] > valeurMaximum)
		{
			tableau[i] = 0;
		}
	}
}

// Exercice 5
void ordonnerTableau(int tableau[], int tailleTableau)
{
	int sauv;
	int j;
	for (size_t i = 1; i < tailleTableau; i++)
	{
		sauv = tableau[i];
		j = i - 1;
		while (j >= 0 && sauv < tableau[j])
		{
			tableau[j + 1] = tableau[j];
			j--;
		}
		tableau[j + 1] = sauv;
	}
}
