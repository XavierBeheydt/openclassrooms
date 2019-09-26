#include <stdio.h>
#include <stdlib.h>

// Include in GUI_H
#include <string.h>

#ifndef TYPES_H
#define TYPE_H

#include <limits.h>

#endif // !TYPES_H


#ifndef GUI_H
#define GUI_H

#define NB_ITEMS	9

#define Clear()				printf("\033[H\033[J");
#define JumpLine(nbLine)	for (size_t i = 0; i < nbLine; i++) \
								printf("\n");
#define debug(value)				printf("Level = %i\n", value);

#endif // !GUI_H

typedef struct Message
{
	char *title;
	char *items[NB_ITEMS];
	char *question;
} Message;

typedef enum Menu
{
	MAIN = 1,

	TYPES = 10,
	CHAR = 11,

	SHORT = 12,
	INT = 13,
	LONG = 14,
	LLONG = 15,

	LOOPS = 20,
	FOR = 21,
	WHILE = 22,
	DO_WHILE = 23

	// TODO: Ajout des numérations de menus
} Menu;

typedef enum Bool
{
	false,
	true
} Bool;

Menu printTypes(Menu types);
void subLiner(size_t nb, char c);
void printMenu(Message msg);
Menu saisi(Menu level);
void pressEnter(void);
void menu(void);
void allocationMemoire(void);


Menu printTypes(Menu types)
{
	/*
		TODO:
			Mise en commun de la fonction d'affichage de cours.
	*/
	Clear();
	switch (types)
	{
	case CHAR:
		printf("signed or unsigned char = %d byte(s)\n", CHAR_BIT);
		printf("min char		= %+d\n", CHAR_MIN);
		printf("max char		= %+d\n", CHAR_MAX);
		printf("min signed char		= %+d\n", SCHAR_MIN);
		printf("max signed char		= %+d\n", SCHAR_MAX);
		printf("min unsigned char	= %+d\n", 0);
		printf("mac unsigned char	= %+d\n", UCHAR_MAX);
		// Maintient et retour de valeur
		pressEnter();
		return TYPES;
	case SHORT:
		puts("A remplir");
		pressEnter();
		return TYPES;
	case INT:
		puts("A remplir");
		pressEnter();
		return TYPES;
	case LONG:
		puts("A remplir");
		pressEnter();
		return TYPES;
	default:
		break;
	}
}
void subLiner(size_t nb, char c)
{
	for (size_t i = 0; i < nb; i++)
	{
		printf("%c", c);
	}
}


void printMenu(Message msg)
{
	/*
		Procédure permettant d'afficher et de formatter 
		le texte des menus.
	*/
	Clear();

	// Printing title
	printf("%s\n", msg.title);

	// Printing subliner for title
	size_t width = strlen(msg.title);
	subLiner(width, '=');
	JumpLine(2);

	size_t i = 0;
	for (i = 0; i < NB_ITEMS; i++)
	{
		if (msg.items[i] == NULL)
		{
			break;
		}
		printf("%d - %s\n", i + 1, msg.items[i]);
	}

	JumpLine(1);
	subLiner(width, '=');
	JumpLine(1);
	printf("%s ", msg.question);
}

Menu saisi(Menu level)
{
	/*
		TODO:
			Retouche des conditions au fur et à mesure
	*/
	int choix;
	scanf("%i", &choix);

	if (level < 10)
	{
		return choix * 10;
	}
	else if (level >= 10 && choix == 0)
	{
		return 1;
	}
	else
	{
		return choix + level;
	}
}

void pressEnter(void)
{
	do
	{
		puts("\nAppuyer sur Entree ...");
		getchar();
	} while (getchar() != '\n');
}

void menu(void)
{
	Menu level = MAIN;

	/* Créer des fonction d'init
		ex:
			Message Main;
			initMain(&Main); // Via l'adresse

		void initMain(Message *Main)
		{
			Main->title = "";
			Main->items =
			{
				"item1",
				"item2"
			};
			Main->question = "";
	*/
	Message Main =
		{
			"Bienvenu dans le programme de memo du langage C.",
			{
				"Les types standards",
				"Les boucles"
			},
			"Quel item voulez vous voir ? (0 pour quitter)"
		};

	Message Types =
		{
			"Les types de base en C.",
			{
				"char",
				"short",
				"int",
				"long",
				"long long",
				"double",
				"decimal",
				"float"
			},
			"Quel type voulez vous voir ? (0 pour revenir) "
		};
	Message Loops =
	{
		"Les boucles en C.",
		{
			"La boucle for",
			"La boucle while",
			"La boucle do ... while"
		},
		"Quelle boucle voulez vous voir ? (0 pour revenir) "
	};

	// Boucle de choix des menus
	/*
		TODO:
			Ajouter des controls de valeurs
	*/
	do
	{
		if (level == MAIN)
		{
			printMenu(Main);
			level = saisi(level);
		}
		if (level == TYPES)
		{
			printMenu(Types);
			level = saisi(level);
			level = printTypes(level);
		}
		if (level == LOOPS)
		{
			printMenu(Loops);
			level = saisi(level);
		}
	} while (level != 0);
	Clear();
}

void ioFile(void)
{
	FILE* monFichier = NULL; // Init du pointeur sur fichier à NULL, comme touts pointeurs.
	monFichier = fopen("monfichier.txt", "w+");
	/*
		Fonction fopen
			prototype :
				FILE* fopen(const char* FileName, const char* mode);
			Modes :
				- "r"   : lecture seule,
				- "w"   : écriture seule,
				- "a"   : ajout en partant de la fin du fichier sans lecture,
				- "r+"  : lecture et écriture, sans effacer le fichier et doit exister.
				- "w+"  : lecture et écriture, efface le contenu et créer le fichier s'il n'existe pas,
				- "a+"  : ajout en partant de la fin du fichier et peut lire, si le fichier n'existe pas il est crée.
				les mêmes mode en ajout b (avant le +) en mode bytes.
	*/

	// Test si le fichier a bien été ouvert ou créé.
	if (monFichier != NULL)
	{
		// Méthode écriture #1 - écriture d'un caractère
		fputc('1', monFichier);
		fputc('\n', monFichier);

		// Méthode écriture #2 - écriture d'une chaîne non formatée
		fputs("Essais de chaine non formatee.\n", monFichier);

		// Méthode d'écriture #3 - écriture d'une chaîne formatée
		fprintf(monFichier, "Je peux formate avec des int par exemple %i.\n", 45);

		// Visualisation de la position dans le fichier
		printf("Je suis a la position %zu\n", ftell(monFichier));

		fclose(monFichier); // 0 si fermeture ok sinon EOF(-1)
	}
	else
	{
		puts("Erreur d\'ouverture du fichier.");
	}

	monFichier = fopen("monfichier.txt", "r");
	if (monFichier != NULL)
	{
		int c = 0;
		do
		{
			c = fgetc(monFichier);
			printf("%c", c);
		} while (c != EOF);
		fclose(monFichier);
	}
}

void allocationMemoire(void)
{
	
}

int main(int argc, char *argv[])
{
	// Clear();
	//menu();
	ioFile();
	return EXIT_SUCCESS;
}