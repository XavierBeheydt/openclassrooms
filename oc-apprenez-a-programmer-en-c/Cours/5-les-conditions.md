# Les conditions

## Les opérateurs booléens

| Symbole | Signification            |
|:-------:|--------------------------|
| ==      | est égale à              |
| >       | est supérieur à          |
| <       | est inférieur à          |
| >=      | est supérieur ou égale à |
| <=      | est inférieur ou égale à |
| &&      | ET                       |
| `||`    | OU                       |
| !       | NON                      |

Il faut savoir qu'en C 0 équivaut à FALSE et 1 à TRUE.

Cela peut être mis en place par la créer de constrantes tel que

```C
const short TRUE = 1;
const short FALSE = 0;
```

*Il faut que je vois si l'on peut faire une définition pour cela???*

## La condition par le if

### Le if simple

```C
if (/*condition de type booléenne*/)
{
	// Instructions
}
```

### if ... else ...

```C
if (/*condition*/)
{
	// Instructions
}
else
{
	// Instructions
}
```

## if ... else if ...

```C
if (/*condition*/)
{
	// Instructions
}
else if
{
  // Instructions
}
else
{
	// Instructions
}
```

## Switch ... case ...

Dans le cas d'un imbriquement de condition if ... else if ..., nous pouvons opter 
pour le switch ... case ..., exemple :

```C
switch (/*variable à tester*/)
{
case 2:
	// instructions
	break;
case 3:
	// instructions
	break;
...
default;
	// instructions
	break;
}
```

Cette condition là permet de tester des valeurs fixes et unique par cas, alors que le if lui permet
de tester des plages.
Dansle cas ou aucunes valeurs n'est reconnu le cas `default` sera donc mis en place.

Chaque cas se termine par l'instruction `break`, ce qui a pour effet d'arrêter le test et sortir du conditionnement.

## La condition ternaire

Elle se comporte comme un if ... else ... mais elle affecte des valeurs, exemple :

```C
int majeur;
int age;

scanf_s("%i", &age);

// soit var = (condition) ? var_si_condition_vraie : var_si_condition_fausse;
majeur = (age >= 18) ? 18 : 17;
```

