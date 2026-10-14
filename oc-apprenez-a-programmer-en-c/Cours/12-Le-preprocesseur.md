# Le préprocesseur

Les directives de préprocesseur sont des instructions s'exécutant juste avant la compilation du programme.

Cela permet de faire des inclusions d'autres fichiers, ou bien des macros et des définitions.

Ces directives sont toujours précédées par le signe `#`.

## Les include

La directive include permet d'inclure un ou plusieurs fichiers au sein du fichier courant. Dans le cas d'inclusion de fichiers au sein du dossier courant ou d'inclure des fichiers bibliothèques, il faut faire comme cela :

```c
#include <stdio.h> // Utilisation des chevrons pour l'inclusions d'une bibliothèque
#include "my_header.h" // Utilisation des double quotes pour des fichiers du répertoire courant
```

La directive #include permet en faite au moment de la compilation d'assemblé les fichiers comme si il y en avait qu'un.

*Pour rappel les fichier `.h` permet l'inscription des prototypes des fonctions.*

## Les define

Ce mot clef lui permet de définir des constante de préprocesseur. Cela a pour incidence de remplacer le nom de la constante définit par la valeur saisi.

Cela permet d'éviter l'allocation mémoire pour une valeur constante et par la même occasion de simplifier la réédition de la dite valeur en ayant pas à parcourir tout le code pour changer cette dite valeur.

Exemple :

```c
#define WIDTH 1920
#define HEIGHT 1080
// Définition d'une taille de fenêtre par exemple
```

Lorsque l'on parle de non utilisation de case mémoire, cela est vraie uniquement pour la pile et le tas (allocation dynamique).
Mais cette constante de préprocesseur , elle entre bien en mémoire statique au chargement du programme (plus précisément dans le *segment text*.)

Voir [l'allocation de mémoire](https://fr.wikipedia.org/wiki/Allocation_de_mémoire)

*Avant la norme C11, l'allocation dynamique de taille de tableau n'est pas autorisée mais elle peut être préprocessée.*

```c
#define TAILLE_TABLEAU

int main(int argc, char *argv[])
{
	char chaine[TAILLE_TABLEAU];
	...
}
```

### Les calculs avec `#define`

Nous pouvons donc créer une directive de calcul lors de la compilation et faire un binding sur cette valeur, toujours dans le cas de simplifier l'écriture et la maintenance de notre code. Exemple :

```c
#define WIDTH 800
#define HEIGHT 600
#define NB_PIXELS (WIDTH * HEIGHT)
```

**Nous mettons donc le calcul entre parenthèse afin de bien définir le calcul de l'attribution à la constante de préprocesseur.**
L'ensemble des opérateurs de base du langage peuvent être utilisé.

### Les constantes pré-existantes

Il existe quelques constantes de préprocesseur prédéfinies par le langage, tel que:

- `__LINE__` : Affichera la ligne de programme en cour d'exécution.
- `__FILE__` : donne le fichier en cour d'exécution.
- `__DATE__` : donne la date de compilation.
- `__TIME__` : donne l'heure de la compilation.

L'intérêt de cela est dans le car de débogage.

### Les macros

Cette directive permet de générer des morceaux de code réutilisable et surtout si celui-ci est très récurent.

La macro peut avoir ou pas des arguments, être sur plusieurs lignes.
Lors de sont utilisation celle-ci ne demande pas de `;` à la fin (bien qu'elle fonctionne aussi avec).

*Exemple de macro simple*

```c
#define HELLO() printf("Hello World  !\n");
```

*Exemple de macro multiligne*

```c
#define RACONTE_TA_VIE() printf("Bonjour\n"); \
						 printf("Je m'appelle\n"); \
						 printf("John Doe\n");
```

*Exemple de macro avec condition*

```c
#define MAJEUR(age, nom) if (age >= 18) \
                    printf("Vous etes majeur %s\n", nom);

int main(int argc, char *argv[])
{
    MAJEUR(22)

    return 0;
}
```

### Les définitions simples et condition sur définition

Les définitions simples permettent de créer des points de validation pour les conditions sur définition.

Les conditions sur définition sont composées des mots clefs :

- `#ifdef` : si définis
- `#ifndef` : si non définis
- `#endif` : fin des conditions

Exemple :

```c
#define LINUX

#ifdef LINUX
	// code à exécuter à la compilation
#endif

#ifdef WINDOWS
	// code à exécuter à la compilation
#endif

#ifdef MACOS
	// code à exécuter à la compilation
#endif
```

L'exemple précédent permet de mettre en place une compilation conditionnelle selon l'OS utilisé.

Pour le `#ifndef` cela peut servir à éviter les inclusions infinies.

Exemple :

```c
#ifndef DEF_FICHIER_A_INCLURE
#define DEF_FICHIER_A_INCLURE

// Plus la définition des autres inclusions
#endif
```

Cela permet donc d'éviter les inclusions infinies dans le cas de projets multi-fichiers.

### Les conditions

la syntaxe reprend :
- `#if <expression>` : si
- `#elif <expression>` : alors si
- `#else` : alors
- `#endif` : fin de condition

*Pour toutes informations via la doc de gcc aller [ici](https://gcc.gnu.org/onlinedocs/cpp/index.html#SEC_Contents).*
