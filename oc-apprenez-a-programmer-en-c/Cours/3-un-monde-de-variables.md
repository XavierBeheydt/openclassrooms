# Un monde de variables

## Les variables et leurs types

*Informations tirées de [wikipedia](https://en.wikipedia.org/wiki/C_data_types).*

### Les types

|          Type          |  size   |         Valeur Min         |         Valeur Max          |         Format specifier          |
| :--------------------: | :-----: | :------------------------: | :-------------------------: | :-------------------------------: |
|          char          |  8bits  |            -127            |            +127             |                %c                 |
|      signed char       |  8bits  |            -127            |            +127             | %c (or %hhi for numerical output) |
|     unsigned char      |  8bits  |             0              |            +255             | %c (or %hhu for numerical output) |
|         short          | 16bits  |          -32,767           |           +32,767           |             %hi or %d             |
|       short int        |    "    |             "              |              "              |                 "                 |
|      signed short      |    "    |             "              |              "              |                 "                 |
|    signed short int    |    "    |             "              |              "              |                 "                 |
|     unsigned short     | 16bits  |             0              |           +65,535           |                %hu                |
|   unsigned short int   |    "    |             "              |              "              |                 "                 |
|          int           | 16bits  |          -32,767           |           +32,767           |             %i or %d              |
|         signed         |    "    |             "              |              "              |                 "                 |
|       signed int       |    "    |             "              |              "              |                 "                 |
|      unsigned int      | 16bits  |             0              |           +65,535           |                %u                 |
|        unsigned        |    "    |             "              |              "              |                 "                 |
|          long          | 32bits  |       -2,147,483,647       |       +2,147,483,647        |                %li                |
|        long int        |    "    |             "              |              "              |                 "                 |
|      signed long       |    "    |             "              |              "              |                 "                 |
|    signed long int     |    "    |             "              |              "              |                 "                 |
|     unsigned long      | 32bits  |             0              |       +4,294,967,295        |                %lu                |
|   unsigned long int    |    "    |             "              |              "              |                 "                 |
|       long long        | 64bits  | -9,223,372,036,854,775,807 | +9,223,372,036,854,775,807  |               %lli                |
|     long long int      |    "    |             "              |              "              |                 "                 |
|    signed long long    |    "    |             "              |              "              |                 "                 |
|  signed long long int  |    "    |             "              |              "              |                 "                 |
|   unsigned long long   | 64bits  |             0              | +18,446,744,073,709,551,615 |               %llu                |
| unsigned long long int |    "    |             "              |              "              |                 "                 |
|         float          | 32bits  |  Real floating-point type  |     Real floating-type      |             %f or %F              |
|           "            |    "    |             "              |              "              |             %g or %G              |
|           "            |    "    |             "              |              "              |             %e or %E              |
|           "            |    "    |             "              |              "              |             %a or %A              |
|         double         | 64bits  |  Real floating-point type  |  Real floating-point type   |            %lf or %lF             |
|           "            |    "    |             "              |              "              |            %lg or %lG             |
|           "            |    "    |             "              |              "              |            %le or %lE             |
|           "            |    "    |             "              |              "              |            %la or %lA             |
|      long double       | 128bits |  Real floating-point type  |  Real floating-point type   |            %Lf or %LF             |
|           "            |    "    |             "              |              "              |            %Lg or %LG             |
|           "            |    "    |             "              |              "              |            %Le or %LE             |
|           "            |    "    |             "              |              "              |            %La or %LA             |

### La déclaration

Exemple de déclaration de variable :

```C
// Déclaration et affectation de valeur séparée.
int nombre_de_vie;
nombre_de_vie = 50;

// Déclaration et affectation de valeur simultanée.
unsigned int somme_argent = 150;
```

*On préférera effectuer les déclarations en début de fonction.*

### Les constantes

Exemple de déclaration de constante :

```C
// Déclaration et affectation simultanée.
const float TAUX = 15.5;
```

**Pour les noms de constante, la règle veut un nom en majuscule et des séparation de mot avec un *underscore*.**

*Ici, nous ne pouvons pas effectuer d'affectation séparée, car le principe d'une constante est de ne pas pouvoir être modifiée au cours du programme.*

## La porté des variables

Selon le context ou la manière de préfixer une variable sa porté peut être déterminée.

### La porté globale

Lorsqu'une variable est déclarée en dehors d'une fonction celle-ci est de portée globale et sera accessible partout.

**Il est fortement déconseillé de faire cela!**

*Exemple :*

```c
int maVarGlobale = 5;

in main()
{
    // Il est possible de la modifier partout
    maVarGlobale++;
}
```

### La porté dans une fonction

Une variable déclaré dans une fonction a une durée de vie limité. C'est à dire que celle-ci n'existe que lorsque la fonction est appelée. Elle sera détruite après l'exécution de celle-ci.

La variable n'est accessible nulle part d'autre qu'à l'intérieur de la fonction.

### La porté statique

Nous voulons dans certains cas particulier disposer d'un variables semi-globale. Avec l'ajout en préfixe du mot clé `static` une variable dispose d'une porté limité au fichier concerné.

```c
static float maVarStatic = 7.8;
```

### La fonction statique

De la même manière qu'une variable une fonction peut être aussi `static`.

```c
static void hello(string[] name)
{
    printf("%s", string);
}
```
