# Afficher et saisi utilisateur

## Afficher

### Du texte

Dans le cas d'un programme en console, la bibliothèque standard permet d'afficher du texte via plusieurs fonctions. Ici nous verrons la fonction `printf();`.

Exemple d'affichage:

```C
printf("Hello World!\n");
// Ici, pour créer une saut de ligne nous devons utiliser le symbole \n.
```

### Du texte et des variables

Dans le cas d'une intégration de variable numéric à afficher au sein d'un texte.

Nous utiliserons le caractère spécial `%` et du format de conversion spécifier dans la tableau du cour précédent.

Exemple :

```C
int nombreDeVie = 5;
printf("Je dispose de %d vies\n", nombreDeVie);
```

> Comme saisi dans le code source `printf` depuis C99 prend en paramètre un format restraint afin de sécuriser le dépassement de tampon.

## Saisi

Dans le cas d'une saisi, l'opération est particulière voir l'exemple.

Exemple :

```C
int nombreDeVie = 0;

scanf_s("%i", &nombreDeVie);
```

> Depuis la C11, il faut donc, pour ne pas énerver notre compilateur, choisir une saisi avec format restrictif, tel que le `scanf_s` afin de vérifier un potentiel dépassement de tampon.

*Nous utilisons aussi un caractère de conversion puisque que la saisi est un ensemble de char qui doit être retranscrit dans le format voulu (ici un int) et une référence à la variable que nous voulons modifier.*
