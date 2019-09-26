#define TRUE 1
#define FALSE 0

typedef struct Joueur Joueur;

struct Joueur
{
	char nom[100];
	int vie;
	short genre; // True = male, False = female
};