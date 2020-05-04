#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "Dict.h"

#define PATH_DICT "C:\\Users\\xavie\\source\\computer-learning\\computer-learning-site\\cursus\\openclassrooms\\oc-apprenez-a-programmer-en-c\\src\\tp-pendu-vs\\dictionnaire.txt"

int main(int argc, char const* argv[])
{
    // FIXME : just for tests
    Dict dictMotSecret = { NULL, 0, 0 };
    dictMotSecret.file = fopen(PATH_DICT, "r");
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
