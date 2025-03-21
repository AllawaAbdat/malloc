/*
** my_malloc.c for malloc in /home/allawa/C/abdat_a/malloc_ff
** 
** Made by ABDAT Allawa
** Login   <abdat_a@etna-alternance.net>
** 
** Started on  Wed Jun 27 21:11:39 2018 ABDAT Allawa
** Last update Tue Jul  3 20:19:20 2018 MOULINETTE Edouard
*/

#include "my_malloc.h"

struct s_header *head = NULL, *tail = NULL;

struct s_header *get_freeblock(size_t  size)
{
  struct s_header *current = head;

  while(current){
    if (current->available && current->size >= size)
      return current;
    current = current->next;
  }
  return NULL;
}

void free(void  *block)
{
  struct s_header *header;
  struct s_header *tmp;
  void  *pbreak;

  if (!block)
    return;
  pthread_mutex_lock(&malloc_lock);
  header = (struct s_header*)block - 1;
  pbreak = sbrk(0);
  if ((char*)block + header->size == pbreak) {
    if (head == tail) {
      head = tail = NULL;
    } else {
        tmp = head;
        while (tmp) {
          if(tmp->next == tail) {
            tmp->next = NULL;
            tail = tmp;
          }
            tmp = tmp->next;
        }
      }
      sbrk(0 - header->size - sizeof(struct s_header));
      pthread_mutex_unlock(&malloc_lock);
      return;
    }
    header->available = 1;
    pthread_mutex_unlock(&malloc_lock);
}

void *malloc(size_t size)
{
  size_t  size_total;
  void    *block;
  struct s_header *header;

  if (!size)
    return NULL;
  pthread_mutex_lock(&malloc_lock);
  header = get_freeblock(size);
  if (header) {
    header->available = 0;
    pthread_mutex_unlock(&malloc_lock);
    return (void*)(header + 1);
  }
  size_total = sizeof(struct s_header) + size;
  block = sbrk(size_total);
  if (block == (void*) -1) {
    pthread_mutex_unlock(&malloc_lock);
    return NULL;
  }
  header = block;
  header->size = size;
  header->available = 0;
  header->next = NULL;
  if (!head)
    head = header;
  if (tail)
    tail->next = header;
  tail = header;
  pthread_mutex_unlock(&malloc_lock);
  printf("Hello");
  return (void*)(header + 1);
}
