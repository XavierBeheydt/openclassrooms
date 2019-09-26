#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "macros.h"

#include "GUI.h"
#include "types.h"


int printMenu(char *title, char **menu, size_t size)
{
	Clear();
	int choix = -1;
	char question[] = "Choix du menu ou 0 pour quitter ?";
	size_t question_size = strlen(question) + 1;

	// Print title
	printf("%s\n", title);

	// Subline title
	for (size_t i = 0; i < strlen(title); i++)
	{
		printf("=");
	}
	
	Jumpline(2);

	// Print menu
	for (size_t i = 0; i < size; i++)
	{
		printf("%i - %s\n", i + 1, menu[i]);
	}

	Jumpline(1);

	// Print question
	printf("%s ", question);
;

	// Boucle de saisi
	do
	{
		// Retour du curseur en cas d'erreur de saisi
		if (choix != -1)
		{
			// For codes see. man console_codes
			printf("\033[1A");
			printf("\033[%zuC", question_size);
		}
		// Saisi choix
		scanf("%i", &choix);
	} while (choix < 0 || choix > size);
	return choix;
}

void menuMain()
{
	int choix = -1;
	do
	{

	} while (choix != 0);
	// Saisi des éléments
	char title[] = "Bienvenu dans les notes du langage C.";
	char *menu[] =
	{
		"Les types de base",
		"Les boucles"
	};
	
	size_t size = sizeof(menu) / 8;
	switch (printMenu(title, menu, size))
	{
	case 1:
		menuType();
		break;
	case 2:
		break;
	default:
		break;
	}
}

void menuType()
{
	char title[] = "Type simple de variables";

	char *menu[] =
	{
		"char",
		"short",
		"int",
		"float",
		"Retour au menu precedent"
	};
	
	size_t size = sizeof(menu) / 8;
	int choix = printMenu(title, menu, size);
	switch (choix)
	{
	case 0:
		break;
	case 5:
		menuMain();
		break;
	default:
		types(choix);
		break;
	}
}