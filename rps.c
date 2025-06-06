#include "rps.h"

extern cdll_t *make_rps(void) {
   cdll_t *list;
   shapes_t shape[] = { 
      shape_rock,
      shape_paper,
      shape_scissors
   };
   
   list = cdll_create();

   for (int i = 0; i < SHAPE_NUM; i++)
      (void) cdll_push(list, &shape[i], sizeof *shape);  /* shape[0] */

   return list;
}