## Structurer son premier document

Nous allons voir les premières fonctionnalités de LaTeX, tel que la compilation, la rédaction d'un document simple et l'intégration des caractères spéciaux.


### La compilation

Lors de la rédaction d'un document en LaTeX, celui-ci est donc au format de source du langage, ainsi pour générer un fichier tel qu'un PDF ou un PostScript, il faut donc passer par la case compilation.

Le logiciel de compilation LaTeX, s'appel une **distribution**.

Pour résumer le processus :
- Création et édition d'un fichier `.tex`,
- la distribution LaTeX compile le fichier,
- le fichier `.tex` est converti en PDF `.pdf` ou PostScript `.ps`.

![Processus de compilation](https://user.oc-static.com/files/235001_236000/235670.png)


### Création d'un document simple

Voici une forme minimale d'un document LaTeX:

```latex
\documentclass{article}

\begin{document}
Bonjour, voici mon premier document en LaTeX!
\end{document}
```

Pour le compiler voici les commandes.

*Sous Windows*

```shell
pdflatex <file>.tex
```

ou utilisation de l'extension dans VSCode.

*Sous macOS*

**TODO**

*Sous GNU/Linux*

**TODO**

**ATTENTION** Les noms de fichiers doivent être sans espace ni accents et caractères spéciaux.


### Types de documents et caractères spéciaux

**Les types de documents**

Cela fait référence à des spécificités à propos du document rédigé.

Voici la syntax pour une type de document :

```latex
\documentclass[option1, optionN]{class}
```

Tableau de description des types de class :

Class   | Descriptions
--------|----------------------------------------
article | Articles, revues, et rapport courts
report  | Rapports longs, thèses et petits livres
book    | Vrais livre, centaines de pages
slide   | Des transparents, présentations


Tableau de description des options du documents : 

Description | Valeurs possibles | Valeur par défaut
------------|-------------------|------------------
Taille de police | 10pt, 11pt, 12pt | 10pt
Dimension d'impression | a4paper, letterpaper, a5paper, b5paper, executivepaper, legalpaper | letterpaper
Aligner les équations à gauche | fleqn | none
Affiche la numérotation des formules | fleqn | none
Indique si une nouvelle page doit être commencée après le titre | titlepage, notitlepage | none
Formate le texte en deux colonnes | twocolumn | none
Impression recto-verso | twoside, oneside | article et report : oneside & book : twoside

**Les caractères spéciaux**

LaTeX est un langage qui est interprété, nous retrouverons donc des caractères utilent à la compilation. Exemple pour "\", qui envoi un ordre et donc ne peut être afficher simplement.

Voici un tableau sur les caratères réservés et leur commande en LaTeX:

Caratères réservés  | Commande LaTeX
--------------------|---------------
        $           |       \$
        &           |       \&
        %           |       \%
        #           |       \#
        _           |       \_
        {           |       \{
        }           |       \}
                    |       \
        ^           |       \^
        \           |       \textbackslash{}

Il y en a pleins d'autres qui serons dans mes notes, mais ces caractères sont surtout liés à la mise en forme de formules mathématiques.

**Les portions de texte**

```latex
\begin{document}
\end{document}
```

Ces commandes délimitent un **environnement**, donc touts documents commencera et finira par ces commandes.

Nous pouvons donc insérer des portion de text au sein du document, tel que :

```latex
\begin{document}
\begin{exercice1}
Réponses à l'exercice 1.
\end{exercice1}
\begin{exercice2}
Réponses à l'exercice 2.
\end{exercice2}
\end{document}
```

En résumé voici la commande d'environnement :

```latex
\begin{type}[option1, optionN]
Text ...
\end{type}
```