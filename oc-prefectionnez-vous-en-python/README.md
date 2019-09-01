# Prefectionnez-vous en Python

Tutoriel sur la gestion des modules et paquets. Apprentissage des lib Numpy, Mathplotlib. Les décorateurs.

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
