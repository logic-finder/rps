#include <stdlib.h>
#include <string.h>
#include "cdll.h"

extern cdll_t *cdll_create(void) {
	cdll_t *cdll;

	cdll = malloc(sizeof *cdll);
	if (!cdll) exit(EXIT_FAILURE);

	cdll->head = NULL;
   cdll->tail = NULL;
   cdll->len = 0;

   return cdll;
}

extern void cdll_destroy(cdll_t *cdll) {
   cdll_cleanup(cdll);
   free(cdll);
}

extern void cdll_cleanup(cdll_t *cdll) {
   while (cdll_pop(cdll, NULL));
}

static node_t *makenode(void *elem, size_t elemsize) {
   node_t *new;
   void *dup;

   new = malloc(sizeof *new);
   if (!new) exit(EXIT_FAILURE);
   dup = malloc(elemsize);
   if (!dup) exit(EXIT_FAILURE);

   memcpy(dup, elem, elemsize);

   new->data = dup;
   new->datasize = elemsize;

   return new;
}

extern void *cdll_push(cdll_t *cdll, void *elem, size_t elemsize) {
   node_t *node;
   
   node = makenode(elem, elemsize);

   if (!cdll->len) {
      cdll->head
      = cdll->tail
      = node->prev
      = node->next
      = node;
   }
   else {
      cdll->tail->next = node;
      node->prev = cdll->tail;
      node->next = cdll->head;
      cdll->head->prev = node;
      cdll->tail = node;
   }
   cdll->len++;

   return node->data;
}

extern bool cdll_pop(cdll_t *cdll, void *dest) {
   node_t *tail;

   tail = cdll->tail;
   if (!tail) return false;
   
   if (dest)
      memcpy(dest, tail->data, tail->datasize);
   
   if (cdll->len == 1) {
      free(tail->data);
      free(tail);
      cdll->head = NULL;
      cdll->tail = NULL;
   }
   else {
      node_t *newtail = tail->prev;
      cdll->tail->prev->next = cdll->head;
      cdll->head->prev = cdll->tail->prev;
      free(cdll->tail->data);
      free(cdll->tail);
      cdll->tail = newtail;
   }
   cdll->len--;

   return true;
}

extern node_t *cdll_getnode(cdll_t *cdll, int idx) {
   node_t *node;
   int cnt;

   node = cdll->head;
   if (!node) return NULL;

   cnt = 0;
   while (cnt++ < idx)
      node = node->next;

   return node;
}