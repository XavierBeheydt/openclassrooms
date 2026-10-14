#include <stdio.h>
#include <stdlib.h>

int sommeTableau(int tableau[], int tailleTableau);

int main(int argc, char const *argv[])
{
    int tailleTableau = 5;
    int tableau[5] = { 
        1,
        2,
        3,
        4,
        5
    };

    printf("La somme du tableau est = %d\n", sommeTableau(tableau, tailleTableau));
    return 0;
}

int sommeTableau(int tableau[], int tailleTableau)
{
    int resultat = 0;

    for (size_t i = 0; i < tailleTableau; i++)
    {
        resultat += tableau[i];
    }
    return resultat;
}