#ifndef MAIN_H
#define MAIN_H

typedef struct Message
{
	char *title;
	char *items[NB_ITEMS];
	char *question;
} Message;

typedef enum Menu
{
	MAIN = 1,

	TYPES = 10,
	CHAR = 11,
	SHORT = 12,
	INT = 13,
	LONG = 14,
	LLONG = 15,

	LOOPS = 20,
	FOR = 21,
	WHILE = 22,
	DO_WHILE = 23
} Menu;

typedef enum Bool
{
	false,
	true
} Bool;

Menu printTypes(Menu types);
void subLiner(size_t nb, char c);
void printMenu(Message msg);
Menu saisi(Menu level);
void keyPressed(void);
void menu(void);

#endif // !MAIN_H
