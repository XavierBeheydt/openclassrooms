#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

void decoupeMinutes(int *heure, int *minute);

int main()
{	
	int heure = 0, minute = 90;

	decoupeMinutes(&heure, &minute);

	printf("Il est %i heure et %i minutes", heure, minute);

	return 0;
}

void decoupeMinutes(int *heure, int *minute)
{
	*heure = *minute / 60;
	*minute = *minute % 60;
}
