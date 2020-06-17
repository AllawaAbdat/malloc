:q##
## malloc_readme.txt for malloc in /home/allawa/C/malloc_project/abdat_a/malloc
## 
## Made by ABDAT Allawa
## Login   <abdat_a@etna-alternance.net>
## 
## Started on  Tue Jun 26 15:01:12 2018 ABDAT Allawa
## Last update Sat Feb  2 01:18:33 2019 MOULINETTE Edouard
##

Informations générales :

Le projet sera corrigé sous Debian 8 avec le compilateur gcc et évalué avec l'indentation d'emacs (norme à respecter !)

Le projet doit être compilé avec un Makefile et les flags de compilation suivants : -W -Wall -Werror

Le rendu doit contenir à sa racine un Makefile contenant toutes les règles usuelles pour un projet en C (all ok, name ok, clean ok, fclean ok, re ok, .PHONY ok), capable de générer une librairie dynamique.

Notre librairie devra porter le nom libmy_malloc_$(shell uname).so ("ok")

Sur une debian cela donne libmy_malloc_Linux.so

Le makefile doit également créer un lien symbolique libmy_malloc.so vers la librarie compilée. 

Lancer "make" pour compiler le projet.

Pour tester le malloc en condition réelle nous aurons besoin de précharger la librairie dynamique.

Pour se faire nous utiliserons la ligne de commande suivante pour précharger lalibrairie à partir du dossier courant.

"export LD_PRELOAD=/libmy_malloc.so"

Afin de supprimer ce préchargement et réutiliser le malloc de base de la machine nous utiliserons la commande suivante :

unset LD_PRELOAD
_______________________________________________________________________________

Application de la méthode "First Fit" :

Différentes méthodes nous permettent de réaliser ce malloc tel que le First Fit.
Cette méthode nous permettra d'ajouter, au bloc réservé, une structure contenant les informations nécessaires (cf malloc.h).

On cherche dans le tas un bloc libre suffisamment grand pour notre allocation à l'aide de l'adresse de début de tas et du chaînage que l'on vient de mettre en place.

L'algorithme de First Fit prend le premier bloc qui convient d'ou son nom. 
Il engendre ainsi une certaine perte de mémoire mais également rapide à l'execution et facile à implémenter, d'où notre choix pour cette méthode.

Pour aller plus loin ...

Best Fit : On cherche le meilleur bloc plutôt que le premier qui vient.
Dummy Malloc, Buddy, Slab Allocator et bien d'autres ...

_______________________________________________________________________________

Création du Makefile à partir de Make permettant d'automatiser la generation de fichiers. Plusieurs règles sont implémentées au sein de ce fichier.

Création du fichier malloc.h. Librairie regroupant include, structure et prototypes nécessaires au bon fonctionnement de notre malloc.

SBRK & BRK : Avec sbrk et brk nous pouvons augmenter et diminuer la quantité de mémoire allouée pour les données de votre processus.

Malloc.c : Création du fichier malloc.c composée des fonctions malloc et free.

Malloc check dans un premier temps si la taille est éale à 0. 
Dans le cas contraire, nous allouons un nouveau block de mémoire libre.

Commentaires utiles, retirés pour question de norme : 
	/* On regarde si il y'a un block de libre*/

	/* Le programme cessera de fonctionner si erreur */

	/* sbrk(0) renvoie l'adresse du premier byte de mémoire non allouée */

	/*
  	Vérifie si le block à libérer (free) est le dernier de la liste chaînée.
  	Si ça l'est, alors on peut réduire la taille du heap et "rendre" de la mémoire à l'OS.
  	Sinon, on garde le block dans la liste mais on le marque comme libre (free)
	*/

	/* sbrk() avec un argument négatif décrémente l'adresse du premier byte de mémoire non allouée. */

	/* Il faut accorder de la mémoire pour le block requis et le header par l'OS */
