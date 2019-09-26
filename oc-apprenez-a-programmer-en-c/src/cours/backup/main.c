#include <stdio.h>
#include <stdlib.h>
#include "macros.h"

#include "main.h"
#include "GUI.h"
#include "types.h"

int main(int argc, char *argv[])
{
	menuMain();

	Jumpline(1);
	Print("Good bye !");
	return EXIT_SUCCESS;
}
