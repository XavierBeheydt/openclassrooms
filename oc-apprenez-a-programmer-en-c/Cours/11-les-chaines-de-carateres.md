# Les chaînes de caractères

## Le type char

En C pour le stockage de caractère, nous préconisons l'utilisation de variables de type `char`.

Celui-ci permet de stocker des variable de -128 à +127. Ce qui correspond pour sa partie positive à la table ASCII.

**Écrire un char**

```C
char lettre = 'A';
// Pour convertir une lettre en valeur de char, il faut utiliser le simple quote.

printf("%c\n", lettre);
```

**Saisir un char**

```C

char lettre;

scanf("%c", lettre);
```

## Un tableau de char

En C afin de mettre en variable du texte, celui-ci est enregistré dans un tableau de `char`.

La particularité vient aussi du fait qu'il faut notifier la fin de la chaîne de caractère.

Cela se mette en place par un *null byte* ou *un caractère de fin de chaîne* le `\0`.

Exemple :

```C

char* texte = "salut"; // Je préférerais cette écriture afin de bien séparé les type de variable

// ou 

char texte[] = "salut";

/*
De cette manière la dimension du tableau est automatiquement calculée, de même que le null byte est intégré de manière automatique.
*/
```

## La manipulation de string

En C une bibliothèque existe et est spécialement dédiée à cela, la `string.h`. Voir l'API.
