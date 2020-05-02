# Lire et écrire dans un fichier

Jusqu'ici nos programmes disposaient de nombre et valeurs acquises durant son exécution. Mais lorsque nous voulons garder des valeurs après la fin d'exécution de notre programme une des solutions consiste à écrire cela dans une fichier.

## Ouvrir et fermer un fichier

Pour cela, les fonctions que nous allons utiliser, sont disponible dans la bibliothèque standard `stdio.h`.

**La fonction `fopen`**

Voici son prototype :

```c
FILE* fopen(const char* pathDuFichier, const char* modeDOuverture);
```

Nous pouvons lire dans ce prototype les informations suivantes :
- Le retour de la fonction est un pointeur vers un fichier (structure de fichier).
- Le path vers le fichier que l'on veut ouvrir.
- Et un mode d'ouverture.

## Les modes d'ouverture

Selon nos besoins nous allons définir un mode d'ouverture de fichier, voici les différents modes :
- `'r'` : **lecture seule** : Il faut un fichier déjà éxistant et seule la lecture est faisable.
- `'w'` : **écriture seule** : Si le fichier n'existe pas il sera créé et seule la l'écriture est possible.
- `'a'` : **mode ajout** : Si le fichier n'existe pas il sera créé, dans le as d'un fichier préexistant l'écriture s'effectue depuis la fin.
- `'r+'` : **lecture et écriture** : Le fichier doit existé, et il est possible de lir et écrire dans le fichier.
- `'w+'` : **lecture et écriture avec suppression préalable du contenu** : Si le fichier n'existe pas il sera crée. *Attention l'ensemble du contenu d'un fichier existant sera supprimé*.
- `'a+'` : **ajout en lecture et écriture à la fin** : Si le fichier n'existe pas il sera créé, nous pouvons lire et écrire depuis la fin du fichier.

*Nous avons vu les modes en version texte, il existe une version binaire `b`, il faut ajouter un `b` après la première lettre exemple : `wb+`*.

### Ouverture d'un fichier

```c
FILE* fichier = NULL;

fichier = fopen("test.txt", "r+");


// Test sur l'ouverture du fichier.
if (fichier != NULL)
{
    // manipulation du fichier
}
else
{
    printf("Impossible d'ouvrir le fichier\n");
    exit(EXIT_FAILURE);
}
```

### Fermeture d'un fichier

Nous utiliserons la fonction `fclose` et voici son prototype.

```c
int fclose(FILE* fichier);
```

La fonction retourne deux valeurs selon le contexte : 
- `0` si tout s'est bien passé.
- `EOF` si la fermeture échoue (cette valeur provient de la bibliothèque standard `stdio.h`).

Reprenons notre exemple :

```c
fclose(fichier);

// Il est possible si l'on souhaite effectué un test sur la fermeture
if (fclose(fichier) == EOF)
{
    printf("Une erreur est subvenue !\n");
    exit(EXIT_FAILURE);
}
else
{
    printf("Tout c'est bien passé !\n");
    exit(EXIT_SUCCESS);
}
```

**Attention** il faut bien penser à refermer les fichiers ouverts car cela bloque de la mémoire et on parlera de *fuite de mémoire*.

## Méthodes de lecture et écriture

Maintenant que nous savons ouvrir et fermer un fichier. Il va falloir le manipuler.

### Écrire dans un fichier

Pour cela il existe plusieurs fonctions possible, le choix se fera selon le besoins et le contexte :

- `fputc` : écriture d'un seul caractère à la fois.
- `fputs` : écriture d'une chaîne de caractères.
- `fprintf` : écriture d'une chaîne de caractère formatée (très proche de la fonction `printf`).

#### `fputc`

Voici son prototype :

```c
int fputc(int caractere, FILE* fichier);
```

Dans le détail, cette fonction prend en paramètre :
- un caractère mais codé en `int`.
- un pointeur sur un fichier.
- La valeur de retour est `EOF` si l'écriture échoue.

*Exemple de code*

```c
FILE* fichier = NULL
fichier = fopen("test.txt", "w");

if (fichier != NULL)
{
    fputc('A', fichier);
    fclose(fichier);

    // Il est possible de faire des tests
}
```

#### `fputs`

Voici son prototype : 

```c
char* fputs(const char* chaine, FILE* fichier);
```

Dans le détail, cette fonction prend en paramètre :
- `chaine` :  nous passons un constante de tableau de `char`. (elle est constante car elle s'interdit la modification de la chaîne passée en argument).
- un pointeur sur un fichier.
- bien que la valeur de retour soit un tableau de `char` la valeur `EOF` sera retournée si une erreur est rencontrée.

*Exemple de code*

```c
FILE* fichier = NULL
fichier = fopen("test.txt", "w");

if (fichier != NULL)
{
    fputs("Hello World !\nAutre ligne.", fichier);
    fclose(fichier);

    // Il est possible de faire des tests
}
```

#### `fprintf`

Voici son prototype :

```c
int fprintf(FILE* fichier, const char* chaineFormatee);
```

Dans le détail, cette fonction prend en paramètre :
- un pointeur sur un fichier.
- un tableau de `char` formatée
- La valeur de retour est `EOF` si l'écriture échoue.

*Exemple de code*

```c
FILE* fichier = NULL;
int age = 0;

fichier = fopen("test.txt", "w");

if (fichier != NULL)
{
    // On demande l'âge
    printf("Quel age avez-vous ? ");
    scanf("%d", &age);

    // On l'écrit dans le fichier
    fprintf(fichier, "Le Monsieur qui utilise le programme, il a %d ans", age);
    fclose(fichier);
}
```

### Lire dans une fichier

Pour cela il existe plusieurs fonctions possible, le choix se fera selon le besoins et le contexte :

- `fgetc` : lecture d'un seul caractère à la fois.
- `fgets` : lecture d'une chaîne de caractères.
- `fscanf` : lecture d'une chaîne de caractère formatée (très proche de la fonction `scanf`).

#### `fgetc`

Voici son prototype :

```c
int fgetc(FILE* fichier);
```

Dans le détail, cette fonction prend en paramètre :
- un pointeur sur un fichier.
- La valeur de retour est `EOF` si l'écriture échoue.

*Exemple de code*

```c
FILE* fichier = NULL
fichier = fopen("test.txt", "r");
int caractere = 0;

if (fichier != NULL)
{
    // Boucle de lecture de chaque caratère
    do
    {
        caractere = fgetc(fichier);
        printf("%c", caractere);
    while(caractere != EOF);
    
    fclose(fichier);

    // Il est possible de faire des tests
}
```

#### `fgets`

Voici son prototype : 

```c
char* fgets(char* chaine, int nbCharALire, FILE* fichier, ...);
```

Dans le détail, cette fonction prend en paramètre :
- `chaine` :  nous passons de tableau de `char` ou sera copié notre chaîne lue.
- le nombre de `char` à lire. Nous pouvons donc limiter le nombre afin de ne pas dépasser la limite du tableau de `char` où l'on va copier notre lecture.
- un pointeur sur un fichier.
- bien que la valeur de retour soit un tableau de `char` la valeur `NULL` sera retournée si une erreur est rencontrée.

*Exemple de code*

```c
#define TAILLE_MAX 1000


FILE* fichier = NULL;
char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX

fichier = fopen("test.txt", "r");

if (fichier != NULL)
{
    while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
    {
        printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
    }

    fclose(fichier);
    // Il est possible de faire des tests
}
```

#### `fscanf`

Voici son prototype :

```c
int fscanf(FILE* fichier, const char* chaineFormatee, ...);
```

Dans le détail, cette fonction prend en paramètre :
- un pointeur sur un fichier.
- un tableau de `char` formatée
- La valeur de retour est `EOF` si l'écriture échoue.

*Exemple de code*

```c
FILE* fichier = NULL;
int score[3] = {0}; // Tableau des 3 meilleurs scores

fichier = fopen("test.txt", "r");

if (fichier != NULL)
{
    fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]);
    printf("Les meilleurs scores sont : %d, %d et %d", score[0], score[1], score[2]);

    fclose(fichier);
}
```

### Se déplacer dans un fichier

Pour cela nous allons manipuler une sorte de "curseur virtuel" afin de nous déplacer dans le fichier et lire ou écrire ce qu'il nous intéresse ou là où ça nous intéresse.

Il existe trois fonctions à connaître :

- `ftell`: indique à quelle position vous êtes actuellement dans le fichier ;
- `fseek`: positionne le curseur à un endroit précis ;
- `rewind`: remet le curseur au début du fichier (c'est équivalent à demander à la fonction `fseek` de positionner le curseur au début).

#### `ftell` : position dans le fichier

Voici le prototype :

```c
long ftell(FILE* fichier);
```

Cette fonction retourne la position du curseur dans le fichier.

#### `fseek` : se positionner dans le fichier

Voici le prototype :

```c
in fseek(FILE* fichier, long deplacement, int origine);
```

Cette fonction permet de se déplacer d'un nombre de `char` depuis une position d'origine.
- un pointeur de fichier ouvert.
- `deplacement` permet une valeur négative pour aller en arrière, `0` pour rester là où nous sommes et positive pour avancer.
- `origine` est le `char` de départ où l'on veut effectuer le déplacement. Nous disposons de constante avec des valeurs déterminées par notre fichier actuellement ouvert
  - `SEEK_SET` : le début du fichier
  - `SEEK_CUR` : la position actuelle du curseur
  - `SEEK_END` : la fin du fichier

*Quelques exemple de déplacement*

```c
fseek(fichier, 2, SEEK_SET);
fseek(fichier, -4, SEEK_CUR);
fseek(fichier, 0, SEEK_END);
```

**Attention** `fseek` peut avoir un comportement assez bizarre lorsque le fichier est ouvert en mode `text`, cette fonction est plutôt utilisée pour le mode `binary`.

#### `rewind` : retour au début

Voici son prototype : 

```c
void rewind(FILE* fichier);
```

### Renommer et supprimer un fichier

Ici, seules deux fonctions :

- `rename`
- `remove`

#### `rename` : renommer un fichier

Voici son prototype :

```c
int rename(const char* ancNom, const char* nouvNom);
```

La fonction renvoie `0` si elle a réussi.

*Exemple de code*

```c
rename("test.txt", "test_renomme.txt");
```

### `remove`: supprimer un fichier

Voici son prototype :

```c
int remove(const char* nomFichier);
```

La fonction renvoie `0` si elle a réussi.

*Exemple de code*

```c
remove("test.txt");
```
