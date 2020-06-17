:q##
## malloc_readme.txt for malloc in /home/allawa/C/malloc_project/abdat_a/malloc
## 
## Made by ABDAT Allawa
## Login   <abdat_a@etna-alternance.net>
## 
## Started on  Tue Jun 26 15:01:12 2018 ABDAT Allawa
## Last update Sat Feb  2 01:18:33 2019 MOULINETTE Edouard
##

Informations g�n�rales :

Le projet sera corrig� sous Debian 8 avec le compilateur gcc et �valu� avec l'indentation d'emacs (norme � respecter !)

Le projet doit �tre compil� avec un Makefile et les flags de compilation suivants : -W -Wall -Werror

Le rendu doit contenir � sa racine un Makefile contenant toutes les r�gles usuelles pour un projet en C (all ok, name ok, clean ok, fclean ok, re ok, .PHONY ok), capable de g�n�rer une librairie dynamique.

Notre librairie devra porter le nom libmy_malloc_$(shell uname).so ("ok")

Sur une debian cela donne libmy_malloc_Linux.so

Le makefile doit �galement cr�er un lien symbolique libmy_malloc.so vers la librarie compil�e. 

Lancer "make" pour compiler le projet.

Pour tester le malloc en condition r�elle nous aurons besoin de pr�charger la librairie dynamique.

Pour se faire nous utiliserons la ligne de commande suivante pour pr�charger lalibrairie � partir du dossier courant.

"export LD_PRELOAD=/libmy_malloc.so"

Afin de supprimer ce pr�chargement et r�utiliser le malloc de base de la machine nous utiliserons la commande suivante :

unset LD_PRELOAD
_______________________________________________________________________________

Application de la m�thode "First Fit" :

Diff�rentes m�thodes nous permettent de r�aliser ce malloc tel que le First Fit.
Cette m�thode nous permettra d'ajouter, au bloc r�serv�, une structure contenant les informations n�cessaires (cf malloc.h).

On cherche dans le tas un bloc libre suffisamment grand pour notre allocation � l'aide de l'adresse de d�but de tas et du cha�nage que l'on vient de mettre en place.

L'algorithme de First Fit prend le premier bloc qui convient d'ou son nom. 
Il engendre ainsi une certaine perte de m�moire mais �galement rapide � l'execution et facile � impl�menter, d'o� notre choix pour cette m�thode.

Pour aller plus loin ...

Best Fit : On cherche le meilleur bloc plut�t que le premier qui vient.
Dummy Malloc, Buddy, Slab Allocator et bien d'autres ...

_______________________________________________________________________________

Cr�ation du Makefile � partir de Make permettant d'automatiser la generation de fichiers. Plusieurs r�gles sont impl�ment�es au sein de ce fichier.

Cr�ation du fichier malloc.h. Librairie regroupant include, structure et prototypes n�cessaires au bon fonctionnement de notre malloc.

SBRK & BRK : Avec sbrk et brk nous pouvons augmenter et diminuer la quantit� de m�moire allou�e pour les donn�es de votre processus.

Malloc.c : Cr�ation du fichier malloc.c compos�e des fonctions malloc et free.

Malloc check dans un premier temps si la taille est �ale � 0. 
Dans le cas contraire, nous allouons un nouveau block de m�moire libre.

Commentaires utiles, retir�s pour question de norme : 
	/* On regarde si il y'a un block de libre*/

	/* Le programme cessera de fonctionner si erreur */

	/* sbrk(0) renvoie l'adresse du premier byte de m�moire non allou�e */

	/*
  	V�rifie si le block � lib�rer (free) est le dernier de la liste cha�n�e.
  	Si �a l'est, alors on peut r�duire la taille du heap et "rendre" de la m�moire � l'OS.
  	Sinon, on garde le block dans la liste mais on le marque comme libre (free)
	*/

	/* sbrk() avec un argument n�gatif d�cr�mente l'adresse du premier byte de m�moire non allou�e. */

	/* Il faut accorder de la m�moire pour le block requis et le header par l'OS */
