Voyageur-de-Commerce
==========

Ce projet vise à résoudre le problème du Voyageur de Commerce.

## Table des matières

- [Introduction](#introduction)
- [Problème du Voyageur de Commerce](#probleme-du-voyageur-de-commerce)
- [Solutions](#solutions)
	- [Algorithme génétique](#algorithme-génétique)
	- [Algorithme glouton][#algorithme-glouton)

*********

# Introduction
L'objectif de ce projet est de présenter différentes méthodes de résolution du problème du Voyageur de Commerce.
Les méthodes retenues sont :
- Algorithme génétique
- Algorithme glouton

Ces solutions ont été implémentées en langage C++.

# Problème du Voyageur de Commerce
Le problème du Voyageur de Commerce (Travelling Salesman Problem) est un problème d'optimisation.
Il faut minimiser la distance parcourue durant un parcours, tout en ne passant qu'une seule fois par ville et en revenant au point de départ.

Ce problème est de type "NP complets", le nombre de solutions augmente exponentiellement avec l'ajout de variables.

Pour un nombre de ville peu important, on peut faire le calcul "à la main". Seulement, on arrivera rapidement à des
quantités trop élévées pour le faire. Ainsi, pour 4 villes nous avons 4! solutions soit 24 parcours possibles, pour 6 villes nous avons 6! = 720 solutions. 

Aucun moyen mathématique ne permet de déterminer la meilleure solution, aussi, il est intéressant d'employer 
des heuristiques afin de fournir un résultat, certes, pas optimal mais approchant.

De nombreuse heuristiques existent :
- Algorithme génétique
- Algorithme glouton
- Descent de gradient
- Recuit simulé

# Solutions

## Algorithme génétique


## Algorithme glouton



