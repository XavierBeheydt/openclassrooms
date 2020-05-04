#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "SecretWord.h"

#define PATH_DICT "dictionnaire.txt"

int main(int argc, char const *argv[])
{

    // FIXME : just for tests
    Dict dictMotSecret = {NULL, 0, 0};
    dictMotSecret.file = fopen(PATH_DICT, "w");
    // test d'ouverture de fichier
    if (dictMotSecret.file == NULL)
    {
        printf("Dictionnaire non ouvert\n");
        exit(EXIT_FAILURE);
    }

    initInfoDict(&dictMotSecret);
    printf("Nombre de mot = %d\n", dictMotSecret.nbWord);
    printf("Taille max mot = %d\n", dictMotSecret.maxSizeWord);
    fclose(dictMotSecret.file);
    return 0;
}
