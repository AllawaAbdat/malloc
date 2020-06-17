/*
** my_malloc.h for malloc in /home/allawa/C/abdat_a/malloc_ff
** 
** Made by ABDAT Allawa
** Login   <abdat_a@etna-alternance.net>
** 
** Started on  Wed Jun 27 21:14:50 2018 ABDAT Allawa
** Last update Wed Jun 27 21:47:40 2018 ABDAT Allawa
*/
#ifndef _MY_MALLOC_H_
# define _MY_MALLOC_H_

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

struct s_header {
  size_t size;
  unsigned available;
  struct s_header *next;
};

pthread_mutex_t malloc_lock;

void	*malloc(size_t size);
void	free(void *ptr);

#endif /* !_MY_MALLOC_H_ */
