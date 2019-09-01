# Prefectionnez-vous en Python

Tutoriel sur la gestion des modules et paquets. Apprentissage des lib Numpy, Mathplotlib. Les décorateurs.

<div hidden>
    TODO : Revoir le bloc de texte précédent à la fin du cour.
</div>

## Préparation des dossiers

Alors pour créer un projet et pouvoir en faire un package à terme voici l'architecture des dossiers et fichiers.

```shell
/repo
├── data
│   ├── nosdeputes.fr_deputes_en_mandat_2019-09-01.csv
|   └── débats.xml
├── .gitignore
├── README.md
├── setup.py
├── parite.py
└── main.py
```

## Organisation d'un script

### L'interpréteur et l'encodage

Ici, nous allons créer un script principal de calcul de parité. Celui-ci sera `parite.py`.

Nous y intègrerons, le path d'environnement de python, ici `Python3` et nous définirons l'encodage des caractères `utf-8`. Cela n'est plus vraiment valable depuis la version 3 de Python. Mais il reste une bonne pratique de le mentionner tout de même.

Pour l'environnement, nous appelons cela le `bang`.

Fichier `/parite/parite.py`:

```python
#!/usr/bin/env python3
# coding: utf-8
```

### Une exécution maîtrisée

Dans le cas où un script peut servir de module au sein un paquet ou bien être utilisé en tant que programme principal. Il ya une best practice à mettre en moeuvre.

Nous créons une fonction `main()` qui sera la partie lanceur en mode autonôme. Son appel se fera via une condition.

Comme un script est lu de haut en bas, tout est exécuté au lancement de celui-ci ainsi la condition `__main__` permet de dire on lance la fonction `main()` lorsqu'on lance ce script seulement :

```python
def main():
    pass

if __name__ == '__main__':
    main()
```

## Les environnements virtuels

> Je vais détailler les envs via `pyenv`, car c'est le système que j'utilise et que je trouve plus simple.

Dans le cas de travaux sur différents projets, les modules extérieurs utilisés peuvent être très nombreux. Ainsi, les dates de départs de lancement des projets pose problèmes.

Pourquoi ?

Car les modules utilisés peuvent évolués en terme de version, donc cela peut créer des soucis de compatibilité entre les version utilisées dans les différents projets que l'on développe.

Voici, la syntaxe pour créer un projet local via `pyenv`.

### Installation d'une version de python

`Pyenv` permet d'installer des versions différentes de python, ce qui à mon goût donne un avantage à cette solution.

```shell
# Installation de la version de python 3.7.4
pyenv install 3.7.4
```

On peut voir les versions installés sur le système via la commande `pyenv versions`.

Pour savoir quelle version est utilisée, nous lançons la commande `pyenv version`, **attention version sans (s)**.

Nous pouvons, donc définir une version de base pour le système et aussi configuré une version locale pour un dossier.

```shell
# Configuration de version système/global
pyenv global version 3.7.4
# Configuration d'une version locale dans un dossier
pyenv local version 3.7.4
```

Ici, nous choisissons une version de python, mais nous le verrons plustard, nous pouvons créer un environnement virtuel basée sur une version mais avec son lot de package et l'affecter au système ou à une configuration locale.

### Création d'un environnement virtuel

Dans le cas du travail sur un projet, la bonne méthode consiste à créer un environnement virtuel.

```shell
# Création d'un env basée sur une version de python
pyenv virtualenv 3.7.4 mon_env
# Affectation de l'env au dossier de travail
pyenv local mon_env
```

L'affectation de l'env doit s'effectuer dans le dossier de travail. Cette commande créée un fichier nommer `.python-version`. Ce fichier permet d'activer automatiquement l'env lorsque nous sommes dans le dossier.

Le cas d'une activation manuelle de l'env:

```shell
pyenv activate mon_env
```

Ce fichier peut ête exclue du suivi de git. on l'ajoute donc au fichier `.gitignore`.

```shell
echo ".python-version" >> .gitignore
```
