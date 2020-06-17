/*
** my_calloc.c for malloc in /home/allawa/C/abdat_a/malloc_ff
** 
** Made by ABDAT Allawa
** Login   <abdat_a@etna-alternance.net>
** 
** Started on  Wed Jun 27 21:11:11 2018 ABDAT Allawa
** Last update Wed Jun 27 21:48:08 2018 ABDAT Allawa
*/

#include "my_malloc.h"

void *calloc(size_t number, size_t  nsize) // La fonction calloc() a le même rôle que malloc(). 
//Elle permet d'allouer de la mémoire. 
//La différence entre les fonctions calloc() et malloc(), c'est que calloc() initialise à 0 tous les éléments de la zone mémoire. 
//Il faut faire #include <stdlib.h> pour pouvoir l'utiliser.
{
  size_t  size; // Déclaration d'une variable size de type unsigned
  void    *block; // Décalaration du pointeur block qui se chargera de stocker l'allocation dynamique qui a été faite.

  if (!number || !nsize) // Nous vérifions l'état de nos variable
    return NULL;
  size = number * nsize; // Size stockera la taille du tableau multiplié au nombre d'éléments présent dans le tableau
  if (nsize != size / number)
    return NULL;
  block = malloc(size);
  if (!block)
    return NULL;
  memset(block, 0, size);
  return block;
}
