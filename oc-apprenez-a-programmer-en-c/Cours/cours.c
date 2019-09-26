#include <stdio.h>
#include <stdlib.h>

#include "macros.h"
#include "menus.h"

int main(int argc, char *argv)
{
	// Les type de variables de bases
	//printf("char = %zu byte(s)\n", sizeof(char));
	//printf("signed char = %zu byte(s)\n", sizeof(signed char));
	//printf("unsigned char = %zu byte(s)\n", sizeof(unsigned char));	
	//printf("short = %zu byte(s)\n", sizeof(short));
	//printf("signed short = %zu byte(s)\n", sizeof(signed short));

	// Car un programme doit en générale retourné un code
	/*
		Les codes de retour programme
		voir man exit()
		- 0 ou EXIT_SUCCESS
		- 1 ou -1 ou EXIT_FAILURE 
	*/

	mainMenu();
	return EXIT_SUCCESS;
}

