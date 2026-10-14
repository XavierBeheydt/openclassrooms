#include <stdio.h>
#include <stdlib.h>

/* Lib */
#ifndef DICT_h
#define DICT_h

typedef struct Dict Dict;
struct Dict
{
    FILE* file;
    int maxSizeWord;
    int nbWord;
};

void initInfoDict(Dict* dict);

#endif /* dict.h */
