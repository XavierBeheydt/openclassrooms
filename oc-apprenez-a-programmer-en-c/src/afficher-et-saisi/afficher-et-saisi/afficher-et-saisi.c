#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nombreDeVie = 0;

	// Saisi utilisateur
	printf("Veuillez saisir votre vie.");
	scanf_s("%d", &nombreDeVie);
	//printf("\n");
	/*
	Ici nous utilisons un caractère spacial qui effectue la conversion puis une
	référence vers notre variable.
	l'utilisation de scanf_s est une version sécurisée de scanf permettant de faire une
	une vérification ur le dépassement de tampon.
	scanf effectue lors de la saisi un saut de ligne.
	*/

	// affichage de texte et d'une variable via le caractère spécial.
	printf("J'ai %i vie.\n", nombreDeVie);
	/*
	printf est implémenté avec une sécurisation de restriction de format comme scanf_s.
	*/
	return 0;
}
