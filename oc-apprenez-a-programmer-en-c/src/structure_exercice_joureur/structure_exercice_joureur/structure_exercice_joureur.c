#include "pch.h"
#include "joueur.h"
#include <stdio.h>
#include <stdlib.h>

#define AFFICHE(message)	printf("%s\n", message);

void initJoueur(Joueur *leJoueur);

int main()
{
	Joueur lesJoueurs[2];

	// Initialisation des joueurs
	/*for (size_t i = 0; i < 2; i++)
	{
		initJoueur(&lesJoueurs[i]);
	}*/

	for (size_t i = 0; i < 2; i++)
	{
		// Demande de saisi du nom de joueur
		AFFICHE("Veuillez saisir le nom du joueur ?");
		scanf_s("%s", *(lesJoueurs +i)->nom);
		
		// Demande de saisi du niveau de vie avec controle de valeur.
		AFFICHE("Veuillez entrer le niveau de vie entre 1 et 100 ?");
		do
		{
			scanf_s("%i", &lesJoueurs[i].vie);
		} while (lesJoueurs[i].vie < 1 || lesJoueurs[i].vie > 100);

		// Saisi du genre avec controle de valeur 0 ou 1
		AFFICHE("Etes vous un garcon (=0) ou une fille(=1) ?");
		do
		{
			scanf_s("%d", &lesJoueurs[i].genre);
		} while (lesJoueurs[i].genre < 0 && lesJoueurs[i].genre > 1);
	}

	// Affichage des résultats
	for (size_t i = 0; i < 2; i++)
	{
		switch (lesJoueurs[i].genre)
		{
		case 0:
			printf("Le nom du joueur n%i est %s, il a %d de vie et %s.\n", (i + 1), lesJoueurs[i].nom, lesJoueurs[i].vie, "un garcon");
			break;
		case 1:
			printf("Le nom du joueur n%i est %s, il a %d de vie et %s.\n", (i + 1), lesJoueurs[i].nom, lesJoueurs[i].vie, "une fille");
			break;
		default:
			return 1;
			break;
		}
	}
	return 0;
}

void initJoueur(Joueur *leJoueur)
{
	// Avec les deux méthodes d'écriture de pointage
	leJoueur->vie = 0;
	leJoueur->genre = 0;
}
