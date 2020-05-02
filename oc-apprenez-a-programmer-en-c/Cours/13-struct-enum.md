# Les structures et les énumérations

Ici, nous allons parler de la création de nouveaux type de données. Il ne faut pas non plus s'attendre à une révolution car il n'y a pas de magie.

Les types créés sont toujours basé sur les types de base existants. On parle plus d'imbrication de type standard pour en créer de nouveaux.

Nous pourrions donc créer un type `Keyboard` ou `Fichier` par exemple.

## La structure

Une structure est purement un assemblage de type de base. Voici un exemple de structure.

### Définition d'une structure

La définition d'une structure et donc la création de son architecture intervient en générale à l'intérieur de fichier `.h`.

```c
struct Personnage
{
    string nom[100];
    int vie;
    int genre; // Booléen 0 = garçon et 1 = fille
};
```

**Attention** en fin de structure celle-ci doit être terminée avec `;`. En générale les noms de structures sont écrites avec des majuscules comme `MorceauMusique`.

### Conversion en type

Cel est valable aussi pour les `Enum` que nous verrons ensuite. Cela permet de simplifier l'écriture de notre programme et permet donc de définir que notre structure devient un type dans notre programme.

Reprenons notre exemple précédent :

```c
typedef struct Personnage Personnage;
struct Personnage
{
    string nom[100];
    int vie;
    int genre; // Booléen 0 = garçon et 1 = fille
};
```

**Attention** la fin de ligne de `typerdef` termine par `;`.

*Lors de la définition d'un type en faite nous expliquons que `struct Personnage` est un alias de `Personnage`.*

### Utilisation d'un structure

Maintenant que nous avons typé notre structure voici une utilisation de celle-ci.

**Cas si la structure est pas définie en type*

```c
struct Personnage john; // Création d'une variable Personnage john.
```

**Cas si la structure est définie en type*

```c
Personnage john; // Création d'une variable Personnage john.
// Plus besoin d'écrire struct !!!
```

### Modifier les valeurs de structure

Une structure est une sorte de variable complexe et il est donc intéressant de pouvoir y intégrer ou modifier des valeurs.

Toujours avec notre exemple de `Personnage`.

```c
Personnage unePersonne;

unePersonne.vie = 32;
unePersonne.genre = 0; // Est un garçons.

printf("Quel est votre nom ? ");
scanf("%s", unePersonne.nom);
```

### Déclaration multiple de structure

Nous allons voir une partie intéressante des structures la déclaration multiple.

Nous pourrions créer plusieurs personnes via notre structure `Personnage` comme :

```c
Personnage personne1, personne2;
```

Mais il est possible de faire mieux encore. Il est possible de créer un tableau de `Personnage`.

```c
// Création de 2 personnes
Personnage personne[2];
```

L'avantage réside dans le faite de pouvoir boucler sur l'ensemble des personnes.

### Méthodes d'initialisation d'une structure

Il y a plusieurs méthodes possibles comme celle que nous avons précédemment vues. Voici un récapitulatif des méthodes d'initialisation.

**Méthode 1 - déclaration puis initialisation**

```c
Personnage unePersonne;

unePersonne.vie = 32;
unePersonne.genre = 0; // Est un garçons.

printf("Quel est votre nom ? ");
scanf("%s", unePersonne.nom);
```

**Méthode 2 - déclaration avec initialisation**

```c
Personnage unePersonne = {"John", 32, 1};
// Les paramètres sont dans l'ordre déclaré dans notre structure de base
```

**Méthode 3 - fonction d'initialisation**

Comme vu dans les pointeurs afin de pouvoir modifier plusieurs paramètres extérieurs, il faut jouer des pointeurs.

```c
// Déclaration d'un Personnage et de son pointeur
Personnage unePersonne;

// init de pointeur
Personnage *unePersonnePointeur = NULL;
// ou variante
Personnage* unePersonnePointeur = NULL;


// Fonction d'initialisation utilisant les pointeurs
void initPersonne(Personnage* unePersonne)
{
    // Première méthode d'écriture
    (*unePersonne).vie = 0;
    (*unePersonne).genre = 0;

    // Méthode officielle
    unePersonne->vie = 0;
    unePersonne->genre = 0;
}

initPersonne(&unePersonne);
```

## L'énumération

L'énumération est un peu différente. On ne parle pas d'assemblage mais d'une liste liée à des valeurs permettant de rendre les choses plus intelligible.

Voyons un exemple :

```c
typedef enum Volume Volume;
enum Volume
{
    FAIBLE, MOYEN, FORT
};
```

On remarque le `typedef` qui aura la même fonction que pour les structures. Puis la syntaxe est assez ressemblante le bloc termine aussi par `;`.

### Déclaration d'une énumération

```c
Volume musique = MOYEN;
```

### Association de nombres aux valeurs

Les valeurs d'une énumération ont une syntaxe similaire aux valeurs de `#define` mais la fonctionnement n'est pas équivalente.

Dans notre exemple, nous n'avons pas définie de valeurs numériques aux valeurs de l'énumération. Mais à la compilation est nombres seront automatiquement affectées.

Reprenons notre exemple :

```c
typedef enum Volume Volume;
enum Volume
{
    // Voici les nombres automatiquement affectés
    FAIBLE,     // 0
    MOYEN,      // 1
    FORT        // 2
};
```

*Dans ce cas d'utilisation, nous avons pas réellement besoin de connaître le nombre associé. Voici un exemple de test sur énumération.*

```c
if (musique == MOYEN)
{
    // code here
}
```

Cela permet d'amélioré la syntaxe et la compréhension du programme pour nous humains.

### Associer une valeur précise

Dans certains cas, nous avons besoin d'associer à une valeur un nombre précis.

```c
typedef enum Volume Volume;
enum Volume
{
    FAIBLE = 10, MOYEN = 50, FORT = 100
};
```
