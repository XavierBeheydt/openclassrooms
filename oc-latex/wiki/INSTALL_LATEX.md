## Installation de LaTeX

Je vais donc détaillés l'installation de LaTEx sur les différentes plateformes que j'utilise, soit MS Windows, macOS et GNU/Linux (*sera abordé Debian et Arch Linux*).

Il existe différents environnements, en CLI ou graphique, différents moteurs de transcription vers les formats d'export.

Nous pouvons utilisé n'importe quel éditeur de texte brut, pour rédiger en LaTeX. Puis convertir via un logiciel à part que l'on appelle la **distribution LaTeX**.

Le principe que je vais utilisé sera une distribution utilisée par la ligne de commande ou intégrée à mon éditeur de code qui est [Visual Studio Code](https://code.visualstudio.com/). Je ne détaillerai pas ici l'installation de VSCode.


### Logiciels dont j'ai besoin

**Windows**

Pour la distribution, j'utilise donc [MikTeX](https://miktex.org/). L'installation ne comporte rien de spécial, soit suivant, suivant...

Ensuite, j'utilise l'extension pour VSCode [LaTeX Workshop](https://github.com/James-Yu/LaTeX-Workshop/wiki), pour l'installer lancer un prompt de VSCode avec `CTRL+SHIFT+P` et lancer la commande `ext install latex-workshop`. [Lien vers le wiki de l'extension](https://github.com/James-Yu/LaTeX-Workshop/wiki).

Cette extension a des dépendances :

- [MikTeX](https://miktex.org/), mais n'installe pas SyncTeX. Il faut utilisé donc la fonctionnalité interne SyncTeXJS. Pour l'activé aller dans les paramètres avec `CTRL+,` et faire la recherche du paramètre `synctexjs`, puis cocher la case et redémarrer VSCode.

- Pour Perl sous windows, nous installerons [Strawberry Perl](http://strawberryperl.com/), l'installateur met le dossier à la racine du disque et l'installation se fait en suivant, suivant ...

- [latexmk](https://mg.readthedocs.io/latexmk.html#installation), est package LaTeX en perl de référence croisé. Pour l'installer, lancer l'outil graphique de MikTeX puis aller dans `Packages`, puis rechercher `latexmk` et ajouter le à la distribution. Pour des informations complémentaires à propos de `latexmk` aller voir la documentations [ici](https://mg.readthedocs.io/latexmk.html). *(edit peut être faire des screenshots à l'occasion)*

**GNU/Linux** *à faire...*
**macOS** *à faire...*