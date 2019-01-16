# Notes

Ce sont mes notes, qui me servirons pour la rédaction de mon cour sur le LaTeX.


## Document Class

```latex
\documentclass[option1, optionN]{class}
```

### Class

Class   | Descriptions
--------|----------------------------------------
article | Articles, revues, et rapport courts
report  | Rapports longs, thèses et petits livres
book    | Vrais livre, centaines de pages
slide   | Des transparents, présentations

### Options

Description | Valeurs possibles | Valeur par défaut
------------|-------------------|------------------
Taille de police | 10pt, 11pt, 12pt | 10pt
Dimension d'impression | a4paper, letterpaper, a5paper, b5paper, executivepaper, legalpaper | letterpaper
Aligner les équations à gauche | fleqn | none
Affiche la numérotation des formules | fleqn | none
Indique si une nouvelle page doit être commencée après le titre | titlepage, notitlepage | none
Formate le texte en deux colonnes | twocolumn | none
Impression recto-verso | twoside, oneside | article et report : oneside & book : twoside


## Specials characteres

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


## Environment

```latex
\begin{type}[option1, optionN]
Text ...
\end{type}
```

*Examples*

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