# Les tableaux

Les tableaux de base sont de taille fixe, mais cela peut être contournée par l'*allocation dynamique*
mais depuis C99 nous pouvons utilisé un raccourci.

Un tableau une demande d'allocation de n cases mémoires contigues en RAM.

## Création de tableaux

Exemple de déclaration :

```C
int tableau[4];

tableau; // Sera donc la première adresse mémoire du tableau.
*tableau; ou tableau[0]; // seront le pointeage vers la valeur de la première case mémoire.
*(tableau + n); ou tableau[n]; // seront le pointage vers la valeur de la case n en mémoire.

// Exemples d'intégration de valeurs
tableau[0] = 10;
tableau[1] = 23;
tableau[2] = 504;
tableau[3] = 65;

// Nous aurions pu faire aussi à la déclaration
int tableau[4] = {10, 23, 504, 65};
// Si nous déclarons tel que
int tableau[4] = {45, 30}; // Les valeurs seront : 45, 30, 0, 0

int tableau[5] = {0}; // toutes les valeurs seront à 0.
```

Le typage d'un tableau donnera donc des cases mémoires du type des valeurs que nous voulons y
inscrire.

## Passage d'un tableau à une fonction

Comme un tableau une sorte d'ensemble de pointeur, nous pouvons écrire :

```C
void affiche1(int *tableau, int taileTableau); // Ici mention du tableau par un pointeur
// cette méthode est peu explicite et mérite d'être faite d'une autre manière
void affiche2(int tableau[], int tailleTableau);

int main()
{
	int tableau[4] = {1, 2 ,3 ,4};

	affiche2(tableau, 4);

	return 0;
}

void affiche2(int tableau[], int tailleTableau)
{
	for (int i = 0; i < tailleTaleau; i++)
	{
		printf("%i\n", tableau[i]);
	}
}
```

## Allocation dynamique de taille de tableau

Dans le cas de la version C99 et supérieur, nous pouvons faire :

```C
int taille = 5;
int tableau[taille];
```

*Une autre méthode plus standard sera vu ensuite via l'allocation dynamique*.

## Parcours d'un tableau

Cela s'effectue habituellement via une boucle for.

*Code vu dans [ici](./10-les-tableaux.md#Passage_d'un_tableau_à_uneàfonction).*
