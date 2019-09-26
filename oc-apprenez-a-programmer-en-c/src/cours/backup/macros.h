#ifndef MACROS_H
#define MACROS_H

#define TRUE 1
#define FALSE 0

#define Print(message)		printf("%s\n", message);
#define Clear()				printf("\033[H\033[J");

#define Jumpline(nb)		for (size_t i = 0; i < nb; i++) \
								printf("\n");

#endif // !MACROS_H
