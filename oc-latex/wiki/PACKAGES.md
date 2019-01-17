## Les Packages

L'utilisation de packages permet à LaTeX d'effectuer des mise en formes , ou des fonctionnalités suplémentaires, que dans le langage de base nous ne pourrions faire.

*Exemple : mettre en couleur du texte.*


### Utiliser un package

Pour activé l'utilisation d'un package, c'est la commande suivante :

```latex
\usepackage[option1, optionN]{packageName}
```

Elle se place juste après la commande `\documentclass`.

> La zone entre `\documentclass` et le `\begin{document}` est ce qu'on peut appeler le préambule du **code**. Nous y placerons les différents appels de package et autres commandes.

Nous allons détailler un exemple :

```latex
\documentclass{report}

\usepackage[utf8]{inputenc} % un package
\usepackage[T1]{fontenc}      % un second package
\usepackage[francais]{babel}  % un troisième package
\begin{document}

J'écris mon 3\up{e} document avec \og \LaTeX \fg.
\LaTeX{} est un langage créé par Leslie \bsc{Lamport}.

\end{document}
```

Détails :
- Ici `% commentaire` est donc un commentaire en ligne.
- `babel` avec l'option *français* explique que le document est donc écrit en français.
- `fontenc` et `inputenc`, permettent d'utiliser tous les caractères du clavier latin via l'encodage UTF-8.
- `\up{text}` est la mise à la puissance du package `babel`.
- `\og` est "<<" du package `babel`.

> Les chevrons guillemet peuvent être transcris aussi via `<< >>`.


Tableau détaillant quelques commandes de mise en page du package `babel` :

Package babel           |   Commandes       
------------------------|---------------
    << guillemets       |       \og
    >> guillemets       |       \fg
    Exposant            |       \up{}
    Petites Majuscules  |       \bsc{Lamport}
    1er                 |       1\ier
    2e                  |       2\ieme
    1°                  |       \primo
    2°                  |       \secondo
    3°                  |       \tertio
    4°                  |       \quarto
    8° ou n'importe     |       \FrencEnumerate{8}
    n°                  |       \no
    N°                  |       \No
    n°s                 |       \nos
    N°s                 |       \Nos
    40° degré           |       40\degres


### Installation de packages

**TODO**