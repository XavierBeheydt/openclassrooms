#include <stdio.h>
#include <stdlib.h>

#include "SecretWord.h"

void initInfoDict(Dict *dict)
{
    int charRead = 0;
    // Boucle de lecture du fichier
    do
    {
        // Lecture et inc du nombre de char
        charRead = fgetc(dict->file);
        charRead++;
        // Test fin de ligne ou de fichier
        if (charRead == '\n' || charRead == EOF)
        {
            dict->nbWord++;
            // test max
            if (dict->maxSizeWord < charRead)
            {
                dict->maxSizeWord = charRead;
            }
            // Remise à zero du comptage de char
            charRead = 0;
        }
    } while (charRead != EOF);

    // retour au debut du fichier
    rewind(dict->file);
}
