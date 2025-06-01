#ifndef CDLL_H
#define CDLL_H

#include <stddef.h>
#include <stdbool.h>

typedef struct node {
	struct node *prev;
	struct node *next;
	void *data;
   size_t datasize;
} node_t;

/* circular doubly linked list */
typedef struct cdll {
	node_t *head;
   node_t *tail;
	int len;
} cdll_t;

cdll_t *cdll_create(void);
void cdll_destroy(cdll_t *cdll);
void cdll_cleanup(cdll_t *cdll);
void *cdll_push(cdll_t *cdll, void *elem, size_t elemsize);
bool cdll_pop(cdll_t *cdll, void *dest);
node_t *cdll_getnode(cdll_t *cdll, int idx);

#endif
