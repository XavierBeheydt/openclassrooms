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
│   ├── current_mps.csv
|   └── SyceronBrut.xml
├── parser
│   ├── csv.py
|   └── xml.py
├── .gitignore
├── README.md
├── setup.py
└── parite.py
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

### Le fichier de dépendance

Lorsque nous développons des modules python, notre programme aura très certainement besoins de modules/package extérieurs. Ainsi, il est possible de générer un fichier listant et automatisant l'installation des dépendances. Celui-ci s'appel `requirements.txt`.

Nous pouvons donc `freeze`, la configuration des packages installés en lançant la commande `pip freeze`. Mais celle-ci comporte un défaut, certains packages ne seront certainement pas utiles pour le fonctionnement de notre programme. Il faudra donc effectué un nettoyage de la sortie.

Les dépendances seront donc à affecter au fichiers `requirements.txt`.

### Installation des dépendances

Pour faire une installation manuel, la commande est `pip install <nom_package>`.

Pour effectuer, une installation depuis un fichier voici la syntaxe : `pip install -r requirements.txt`.

## Organiser un projet en module

L'organisation d'un projet est important, car celui-ci permet une meilleur maintenabilité. Mais aussi le possibilité dans le futur d'en faire un package publiable.
Comme j'ai pu lire dans différents blog. Il est fortement conseillé de faire l'ensemble dans la langue de Sheakspeer. Car cela limitera moins le nombre de personne pouvant être intéressé par votre projet.

### Création des paquets (lib)

Dans ce projet, nous allons avoir deux lib d'analyse. L'une pour le `xml` et l'autre pour le `csv`.

Nous allons créer un fichier `setup.py` à la base du projet et un dossier reprenant les modules qui seront respectivement `parser/xml.py` et `parser/csv.py`.

Dans chaque dossier, de sous-module afin de créer un package dispo d'un fichier `__init__.py`.
Celui-ci est lancé comme initialisateur, un peu comme le constructeur en python. Il permet de définir les process effectué lors de l'import.
_Dans le cas d'aucun process, `__init__.py`, peut rester vide.

[Documentation de python-packaging](https://python-packaging.readthedocs.io/en/latest/minimal.html)

## Parsing des arguments

Ici, nous allons présenter le concept d'envois d'argument au script et donc augmenté les capacités de celui-ci.

Python dispose d'un lib permettant de simplifier le travail sur les arguments passés.

Le principe est de créer une fonction reprenant les options de parsing, tel l'exemple suivant :

```python
def parser_arguments():
    parser = argparse.ArgumentParser()
    parser.add_argument("-e", "--extension", 
    help="""Type of file to analyse. It is a CSV or en XML?""")
    return parser.parse_args()
```

Cette fonction retourne l'ensemble des arguments passés par la ligne de commande, puis dans notre `main()`, nous fesons un traintement conditionnel :

```python
if __name__ == "__main__":
    args = parser_arguments()
    if args.extension == 'xml':
        xml.launch_analysis('SyceronBrut.xml')
    else:
        csv.launch_analysis('current_mps.csv')
```

## Gérez les erreurs et les bogues

Cette partie a une importance flagrante, elle permet de faire une vérification immédiate des problèmes de code. Cela, permet aussi de trouver quels sont les algo ne fonctionnant pas.

### Débogue Python avec PDB

Pour lancer le débuggueur en mode console, il y a la méthode suivante.

Pour inclure, un debugger dans un fichier python, nous importons la lib pdb. Et nous demandons la tracage avec la méthode `pdb.set_trace()`.
L'endroit ou est positionné le set_trace, permet l'arrêt de l'exécution et de regarder les objets juste après.

```python
import pdb; set_trace()
```

L'intégration d'un debuggueur vie VScode.
Il faut donc paramétrer une task permettant de lancer le script ou le projet avec les éléments que nous voulons, je vais détailler la configuration via l'exemple du projet actuel.

```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Python: Parite.py CSV",
            "type": "python",
            "request": "launch",
            "program": "${workspaceFolder}/parite.py",
            "args": [
                "-d",
                "data/current_mps.csv",
                "-e",
                "csv"
            ],
            "console": "integratedTerminal"
        }
    ]
}
```

Ici, nous lançons notre script `parite.py` avec les arguments que nous avons besoin pour lancer une analyse de csv.
