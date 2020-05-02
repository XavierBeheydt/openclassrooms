# L'allocation dynamique

Jusqu'ici nous avons fait confiance au compilateur et nous avons vu l'allocation automatique. Mais cela pose certains problèmes.

Les tableaux sont un point où l'allocation automatique peut vite poser problème. Afin de rendre leur mécanisme plus flexible l'allocation dynamique est une arme redoutable. Mais elle a aussi ses travers.

Il faut impérativement être attentif a ce que l'on fait et encore une fois les pointeurs vont pointer leurs nez.

**Rappel d'une allocation manuelle***

```c
int nombre = 0;
```

Ce mécanisme est prédéterminé et l'allocation est faite au début de programme et la libération se fait à la fin du programme.

## Taille des variables

Comme vu au chapitre des variables, nous avons vu que selon le type de variable l'espace requis en mémoire peut différer. Nous allons donc savoir comment déterminer cette taille.

Une fonction existe permettant "d'automatiser" le calcule de cette dimension.

```c
// Exemple pour un int
sizeof(int);
```

Cette fonction peut aussi déterminé la taille d'une structure :

```c
typedef struct Coordonnees Coordonnees;
struct Coordonnees
{
    int x;
    int y;
};

int main(int argc, char *argv[])
{
    printf("Coordonnees : %d octets\n", sizeof(Coordonnees));

    return 0;
}
```

Pour un tableau nous pouvons deviner par exemple qu'un tableau de 100 cases de `int` fera 100 x 4(octet) = 400 octets.

Cela sera aussi valable pour des tableaux de structure par exemple. Dans notre exemple précédent la structure valait 8 octets donc un tableau de 100 de cette structure fera 100 x 8 = 800 octets.

## Allocation de mémoire dynamique

Pour cela la bibliothèque standard requis est la `stdlib.h`. Elle dispose des deux fonctions liées à l'allocation :

- `malloc` pour "Memory ALLOCation" : demande d'allocation mémoire à l'OS.
- `free` pour "libérer" : libération de la mémoire à l'OS.

### `malloc` : demande d'allocation de mémoire

Voici son prototype :

```c
void* malloc(size_t nbOctets);
```

Nous remarquons plusieurs choses étranges :
- la fonction retourne un pointeur sur vide. Oui cette fonction ne peut pas prédire et savoir ce que l'on veut comme type de variable, c'est nous qui le déterminons. La valeur retourné sera une adresse mémoire vers laquelle nous allons faire pointer notre variable.
- Le type `size_t` pour `nbOctets`, c'est un type personnalisé expliquant que c'est une taille en octet.

*Exemple de code*

```c
int* memoireAllouee = NULL;
memoireAllouee = malloc(sizeof(int));
```

**Test du pointeur**

En générale cette partie se passe bien mais une erreur peu subvenir si par exemple notre système est saturé dans l'utilisation de sa mémoire ou bien que la demande dépasse les capacités de notre système.

*Exemple de code*

```c
int* memoireAllouee = NULL;
memoireAllouee = malloc(sizeof(int));

if (memoireAllouee == NULL)
{
    exit(EXIT_FAILLURE);
}
// sinon on peut continuer
```

### `free` : libérer de la mémoire

Voici son prototype :

```c
void free(void* pointeur);
```

La fonction a seulement besoin de l'adresse mémoire à libérer.

*Exemple de code*

```c
int* memoireAllouee = NULL;

memoireAllouee = malloc(sizeof(int));
if (memoireAllouee == NULL) // On vérifie si la mémoire a été allouée
{
    exit(0); // Erreur : on arrête tout !
}

// On peut utiliser ici la mémoire
free(memoireAllouee); // On n'a plus besoin de la mémoire, on la libère
```

**Attention** ici nous créons un pointeur à la base, il faut donc utiliser notre variable d'un point de vue pointeur. Voir l'exemple suivant :

```c
int* memoireAllouee = NULL;

memoireAllouee = malloc(sizeof(int)); // Allocation de la mémoire
if (memoireAllouee == NULL)
{
    exit(0);
}

// Utilisation de la mémoire
printf("Quel age avez-vous ? ");
scanf("%d", memoireAllouee);
printf("Vous avez %d ans\n", *memoireAllouee);

free(memoireAllouee); // Libération de mémoire
```

## Allocation dynamique de tableau

Nous venons de voir comment allouer une petite quantité de mémoire. Nous allons donc voir comment cela se passe pour des tableaux.

**Rappel d'une allocation automatique de tableau**

```c
int tableauAges[15];
```

Ici, nous sommes bloqués à 15 cases de valeurs et pas moyen de faire varier cela selon nos besoins.

Pour cela nous allons procéder comme cela :

```c
int* tableauAges = NULL;

tableauAges = malloc(nbAges * sizeof(int));
```

Ainsi maintenant nous pouvons faire varier notre taille de tableau.

*Voici un exemple d'allocation*

```c
int nombreDAmis = 0, i = 0;
int* ageAmis = NULL; // Ce pointeur va servir de tableau après l'appel du malloc

// On demande le nombre d'amis à l'utilisateur
printf("Combien d'amis avez-vous ? ");
scanf("%d", &nombreDAmis);

if (nombreDAmis > 0) // Il faut qu'il ait au moins un ami (je le plains un peu sinon :p)
{
    ageAmis = malloc(nombreDAmis * sizeof(int)); // On alloue de la mémoire pour le tableau
    if (ageAmis == NULL) // On vérifie si l'allocation a marché ou non
    {
        exit(0); // On arrête tout
    }

    // On demande l'âge des amis un à un
    for (i = 0 ; i < nombreDAmis ; i++)
    {
        printf("Quel age a l'ami numero %d ? ", i + 1);
        scanf("%d", &ageAmis[i]);
    }

    // On affiche les âges stockés un à un
    printf("\n\nVos amis ont les ages suivants :\n");
    for (i = 0 ; i < nombreDAmis ; i++)
    {
        printf("%d ans\n", ageAmis[i]);
    }

    // On libère la mémoire allouée avec malloc, on n'en a plus besoin
    free(ageAmis);
}
```
