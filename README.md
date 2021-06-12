# Cpp_jeu

# JEU EN C++ POO
Le but de ce projet est de mettre en pratique les notions abordées lors du cours de POO en mettant en oeuvre un jeu 2d en C++.
## Description
On a appellé notre jeu "sauve qui peut", au début du jeu, on a deux joueurs. L'objectif du jeu est de s'échapper de la prison sans se faire repérer par les gardes, il faut veiller à ne pas se trouver dans le champ de vision du garde. 

Dans le jeu, on dispose de trois types d'objets:
- L'argent, ça permet de corrompre le garde, il faut se trouver derrière le garde pour l'activer, lorsqu'on ramasse l'argent on gagne 50, corrompre coute 20. 
- Le couteau, permet de poignarder le garde par derrière, on ne peut l'utiliser qu'une seule fois.
- La clé permet d'ouvrir la porte qui permet d'accéder au niveau supérieur (dans notre cas on gagne).

Pour déplacer le joueur 1, on utilise les fleches, pour le joueur 2 on utilise les lettres "zqsd".
Pour la corruption et l'attaque avec un couteau, on utilise C et T respectivement.

## Getting Started

### Dependencies

* Ubuntu/unix
* SDL 

### Executing program

* How to run the program
```
make
./exec 
```
appuyer sur start pour commencer 

## Authors 

Guegen Léa
Ben Hamou Hocine

## Roles
commun : on a commencé par s'initier ensemble à la SDL, en utilisant des exemples simples.
Léa : Programmation des personnages, de la vision, des déplacement des gardes et des joueurs.
Hocine : conception de la carte avec tiled et de son importation, gestion des collisions avec la carte, utilisation des objets. 


