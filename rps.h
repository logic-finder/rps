#ifndef RPS_H
#define RPS_H

#include "cdll.h"

#define SHAPE_NUM 3

typedef enum shapes {
	shape_rock, shape_paper, shape_scissors
} shapes_t;

cdll_t *make_rps(void);

#endif