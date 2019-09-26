# Les pointeurs

Dans le cas ou nous voudrions manipuler plusieurs variables au sein d'une fonction la solution
est l'utilisation de pointeurs car nous savons que la mise en place de variables globales est
peu préconisées.

Explication de la syntaxe :

- `var` est le retour de la valeur contenue dans `var`,
- `&var`est le retour de l'adresse mémoire de la variable,
- `*pointer`est une variable de type pointeur et contiendra l'adresse d'une autre variable mais qui affichera la valeur de la variable pointée,
- `pointer` affichera la valeur du pointeur soit l'adresse de la variable pointée.

Exemple de déclaration :

```C
int age = 10;

int *pointeurSurAge = &age;
// ou
int *pointeurSurAge;
pointeurSurAge = &age;

// Nous remarquons que le pointeur est typé de la même manière que la variable pointée
// Dans le cas où la variable était de type double, notre pointeur aurait été aussi de type double
```

Exemple de passage de pointeur sur une fonction :

```C
void triplePointeur(int *pointeurSurNombre);

int main()
{
	int nombre = 5;

	triplePointeur(&nombre); // Envoie de l'adresse de la variable
	printf("%i", nombre);

	return 0;
}

void triplePointeur(int *pointeurSurNobmre)
{
	// Ici nous travaillons sur la valeur de la variable pointée, donc *pointeurSurNombre.
	*poointeurSurNombre *= 3; // Et on multiplie par 3 la valeur pointée.
}
