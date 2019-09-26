#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#include "macros.h"
#include "GUI.h"

void types(int choix)
{
	Clear();
	switch (choix)
	{
	case 1:
		printf("signed or unsigned char = %d byte(s)\n", CHAR_BIT);
		printf("min char		= %+d\n", CHAR_MIN);
		printf("max char		= %+d\n", CHAR_MAX);
		printf("min signed char		= %+d\n", SCHAR_MIN);
		printf("max signed char		= %+d\n", SCHAR_MAX);
		printf("min unsigned char	= %+d\n", 0);
		printf("mac unsigned char	= %+d\n", UCHAR_MAX);
		break;
	default:
		break;
	}
}