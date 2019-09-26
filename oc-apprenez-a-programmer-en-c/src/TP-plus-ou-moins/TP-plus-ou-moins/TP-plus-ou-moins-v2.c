#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mainv2()
{
	int compteur = 0;
	int saisi = 0;
	int question;
	int nbJoueur;
	int niveau;
	const int min = 1;
	int max;
	int mysteryNb;

	// Boucle de rejeu
	do
	{
		// Menus
		printf("Nombre de joureur :\n");
		printf("\t1 joureur\n");
		printf("\t2 joueurs\n");
		scanf_s("%i", &nbJoueur);

		switch (nbJoueur)
		{
		case 1:
			printf("Choix du niveau de difficulté :\n");
			printf("\tNiveau 1 - entre 1 et 100\n");
			printf("\tNiveau 2 - entre 1 et 1000\n");
			printf("\tNiveau 3 - entre 1 et 10000\n");
			scanf_s("%i", &niveau);

			switch (niveau)
			{
			case 1:
				max = 100;
				break;
			case 2:
				max = 1000;
				break;
			case 3:
				max = 10000;
				break;
			default:
				printf("Erreur!");
				return 0;
				break;
			}
			// Génération du nombre mystère
			srand(time(NULL));
			//int mysteryNb = (rand() % (MAX - MIN + 1)) + MIN;
			mysteryNb = rand() % (max + min);
			break;
		case 2:
			system("@cls||clear");
			printf("Joueur 1 veuillez entrer un nombre ?\n");
			scanf_s("%i", &mysteryNb);
			max = mysteryNb;
			break;
		default:
			printf("Erreur!\n");
			return 0;
			break;
		}

		system("@cls||clear");

		// Boucle de jeu
		while (saisi != mysteryNb)
		{
			printf("Veuillez entrer un chiffre entre 1 et %i ? ", max);
			scanf_s("%i", &saisi);
			if (saisi < min || saisi > max)
				printf("Vous avez saisi un mauvais chiffre!\n");
			else
			{
				compteur++;
				if (saisi > mysteryNb)
					printf("Moins!\n");
				else
					printf("Plus!\n");
			}
		}

		printf("Bravo le chiffre etait %i et vous avez trouez en %i coups\n", mysteryNb, compteur);

		// Question de rejeu
		printf("Voulez vous rejouer ? 0/1\n");
		scanf_s("%i", &question);

		system("@cls||clear");
	} while (question == 1);

	return 0;
}