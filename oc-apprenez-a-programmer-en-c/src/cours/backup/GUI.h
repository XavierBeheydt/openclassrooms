#ifndef GUI_H
#define GUI_H

int printMenu(char *title, char **menu, size_t size);


void menuMain();
void menuType();

typedef enum Section Section;
enum Section
{
	EXIT = 0,
	TYPE = 10,
};

#endif
