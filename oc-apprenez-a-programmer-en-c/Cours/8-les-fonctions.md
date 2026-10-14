# Les fonctions

Comme dans tout les langages typés une fonction doit être typé tel que la valeur retournée.

Dans le cas ou la fonction est en faite une procédure celle-ci doit être du type `void`.

Exemple :

```C
type nomDeFonction(paramètres)
{
	// Instructions

	return valeur; // dans le cas d'une fonction
}
```

# La programmation modulaire

## Le prototype

Dans le cas de plusieurs fonctions au sein d'un programme, nous devons écrire les fonctions avant la fonction `main` pour que celles-ci soit prisent en compte. Pour éviter cela nous pouvons mettre en amont de la fonction `main` des prototypes.

Le prototype n'est ni plus ni moins que la signature d'une fonction terminée par un `;`.

Exemple :

```C
int triple(int value);
```

Dans le cas d'un petit programme nous pouvons l'intégrer dans notre fichier `<filename>.c`.

Mais dans le cas de programmes plus gros, il est préférable de les intégrer dans un header.

## Le header

Le header est un fichier comportant tout les prototypes lié à un fichier source `<filename>.c`.

Le fichier header lui est un fichier du même nom tel que `<filename>.h`.

## La directive de préprocesseur

Dans le cas d'une mise en place de prototype au sein d'un fichier header, nous devons inclure les prototypes dans le fichier source, par la directive `#include "nom_de_header.h"`.

Dans les directives de préprocesseur, l'utilisation :

- **des chevrons** `< >` est pour inclure des fichiers se trouvant dans le répertoire "include" de l'OS ou de l'IDE,
- **des double quote** `" "` est pour inclure des fichiers se trouvant dans le dossier courant du fichier source `.c`.

## La portée des fonctions et des variables

Au sein d'une fonction, les variables déclarées en interne aurons une porté limitée à la dite fonction.

La variable a donc une existant que lors de l'exécution de la fonction. C'est à dire son existence et son contenu existe seulement lors de l'utilisation de la fonction et est donc supprimée à la fin.

Dans le cas de l'utilisation d'une variable dite `static` tel que `static int var = 0;`, l'existence et le contenu de la variable persiste après l'exécution de la fonction.

Dans le cas d'une déclaration de variable en dehors d'une fonction, elle dite `globale`. Cela est en générale à proscrire. Nous préférerons le retours de valeur par le mot clef `return`.

Mais, nous pouvons définir que la variable globale est limitée en porté à un fichier en ajoutant le mot clef `static`.

La fonction `static` à la même influence que la variable globale `static`. 

Cela permet donc de limiter la porté de la fonction au fichier. 

*Il faut donc bien penser à mettre aussi le prototype en `static` de même que la signature de fonction*.
