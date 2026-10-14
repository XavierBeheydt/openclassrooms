#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    const int MAX = 100, MIN = 1;
    int nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
    int saisie = 0;

    do
    {
        printf("Quel est le nombre ? ");
        scanf_s("%i", &saisie);

        if (saisie > nombreMystere)
        {
            printf("C'est moins !\n");
        }
        else if (saisie < nombreMystere)
        {
            printf("C'est plus !\n");
        }
        else
        {
            printf("Bravo, vous avez le nombre mystère !\n");
        }
        
    } while (saisie != nombreMystere);

    return 0;
}
