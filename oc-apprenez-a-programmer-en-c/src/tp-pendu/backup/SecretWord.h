#include <stdio.h>
#include <stdlib.h>

/* Lib */
#ifndef SECRET_WORD_h
#define SECRET_WORD_h

typedef struct Dict Dict;
struct Dict
{
    FILE* file;
    int maxSizeWord;
    int nbWord;
};

void initInfoDict(Dict* dict);

#endif /* SecretWord.h */
