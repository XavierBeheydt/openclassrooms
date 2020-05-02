#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    const int MIN = 1;
    int saisie = 0, compteur = 0, max, nombreMystere;
    char rejoue = 'N';
    short difficulte = 0;

    // Boucle menu et rejouer
    do
    {
        // (ré)init compteur de coups
        compteur = 0;
        // Menu choix difficulté
        printf("Choix de la difficulté de jeu :\n");
        printf("\t1 = entre 1 et 100\n");
        printf("\t2 = entre 1 et 1000\n");
        printf("\t3 = entre 1 et 10000\n");
        // Boucle de vérification de saisie
        do
        {
            scanf_s("%d", &difficulte);
        } while (difficulte < 1 || difficulte > 3);
        switch (difficulte)
        {
        case 1:
            max = 100;
            break;
        case 2 :
            max = 1000;
            break;
        case 3:
            max = 10000;
            break;
        }
        // Génération du nouveau nombreMystere
        nombreMystere = (rand() % (max - MIN + 1)) + MIN;

        // boucle de jeu
        do
        {
            // Comptage de coup
            compteur++;
            // Saisi de l'utilisateur
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
                printf("Bravo, vous avez le nombre mystère en %d de coups!\n", compteur);
            }
        } while (saisie != nombreMystere);

        printf("Voulez-vous rejouer ? (O/N) ");
        // boucle de vérification de saisie de rejoue
        do
        {
            scanf_s("%c", &rejoue);
        } while (rejoue != 'O' || rejoue != 'N');
    } while (rejoue == 'O');

    return 0;
}
