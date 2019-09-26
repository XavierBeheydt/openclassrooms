# Simple MakeFile

# Documentations
# 
# Syntaxe:
# 
# ```MakeFile
# cible: dependance
# 	commandes
# ```
#
# - cible : est le fichier ou dossier générer s'il n'est pas inclus dans `.PHONY`
# - dependances : ce sont les cibles ou fichiers requis pour exécuté la cible
# - commandes : ce sont les commandes exécutées pour stisfaire la cible
#
# Variables internes:
# 
# *Ce sont les variables utilisables au sein de la commande*
#
# - `$@` = le nom de la cible en cours
# - `$<` = le nom de la première dépendance de la cible
# - `$^` = l'ensemble de la liste des dépendances de la cible
# - `$?` = la liste des dépendance plus récente que la cible
# - `$*` = le nom d'un fichier sans suffixe, ex: hello.c -> hello
#
# .PHONY:
#
# PHONY permet d'exécuté les cibles mentionnées quelque soit les fichiers du projet courant.
# càd que ici si un fichier s'appel `mrproper` celui-ci ne sera pas vérifier, ni créé/modifié lorsque
# la cible `mrproper` est appelée.
#
# Règles génériques:
#
# Dans le cas où des fichiers sont multiples, en C les fichiers objets compilés depuis les fichiers 
# sources, la syntaxe est par exemple :
#
# ```MakeFile
# %.o: %.c
# 	gcc -o $@ -c $< $(LDFLAGS)
# ```


# Variables personnalisées
CC=gcc
CCFLAGS= -Wall -Werror
LDFLAGS=
EXEC=cours ## nom du programme à générer
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
DEPS= $(wildcard *.h)

# .PHONY
.PHONY: clean mrproper test

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: $(DEPS)

# Création des fichiers objets
%.o: %.c
	$(CC) -o $@ -c $< $(LDFLAGS)

test: all
	./$(EXEC)

# Cibles de nétoyage du projet
#
# Nétoyage des fichier objets
clean:
	rm -rf *.o

# Nétoyage complet du projet
mrproper: clean
	rm -rf $(EXEC)
