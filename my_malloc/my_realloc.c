/*
** my_realloc.c for malloc in /home/allawa/C/abdat_a/malloc_ff
** 
** Made by ABDAT Allawa
** Login   <abdat_a@etna-alternance.net>
** 
** Started on  Wed Jun 27 21:13:56 2018 ABDAT Allawa
** Last update Wed Jun 27 21:48:31 2018 ABDAT Allawa
*/

#include "my_malloc.h"

void *realloc(void  *block, size_t  size)
{
  struct s_header *header;
  void  *retourne;

  if (!block || !size)
    return malloc(size);
  header = (struct s_header*)block - 1;
  if (header->size >= size)
    return block;
  retourne = malloc(size);
  if (retourne) {
    memcpy(retourne, block, header->size);
    free(block);
  }
  return retourne;
}
