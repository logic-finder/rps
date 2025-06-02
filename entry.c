#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rps.h"

void clearstdin(void);
shapes_t input2shape(int input);
char *shape2str(shapes_t);

int main(void) {
	cdll_t *rps_list;

	srand(time(NULL));
	rps_list = make_rps();
	
	puts("r for ROCK, p for PAPER, and s for SCISSORS. q to quit.");
	for (;;) {
		int rv, input;
		node_t *node;
		shapes_t input_shape, curr_shape, prev_shape, next_shape;

		/* Refer to https://c-faq.com/lib/randrange.html */
		rv = rand() / (RAND_MAX / SHAPE_NUM + 1);
		node = cdll_getnode(rps_list, rv);

		printf("Type your hand shape: ");

		input = getchar();
		if (input == 'q' || input == EOF) break;
		input_shape = input2shape(input);
		if (input_shape == -1) break;
		clearstdin();

		memcpy(&curr_shape, node->data, node->datasize);
		memcpy(&prev_shape, node->prev->data, node->prev->datasize);
		memcpy(&next_shape, node->next->data, node->next->datasize);

		static char *msg = "YOU => %s  |  %s <= PROGRAM,  %s\n";
		#define PRINT_MSG(result) printf(msg, shape2str(input_shape), shape2str(curr_shape), result)

		if (input_shape == curr_shape)
			PRINT_MSG("TIE");
		else
		if (input_shape == next_shape)
			PRINT_MSG("WIN!");
		else
			PRINT_MSG("DEFEATED...");
	}

	cdll_destroy(rps_list);
	return 0;
}

void clearstdin(void) {
   int ch;
   while ((ch = fgetc(stdin)) != '\n' && ch != EOF);
}

shapes_t input2shape(int input) {
	shapes_t ret;

	switch (input) {
		case 'r': ret = shape_rock; break;
		case 'p': ret = shape_paper; break;
		case 's': ret = shape_scissors; break;
		default: ret = -1;
	}

	return ret;
}

char *shape2str(shapes_t shape) {
	static char *rock = "ROCK";
	static char *paper = "PAPER";
	static char *scissors = "SCISSORS";

	char *ret;

	switch (shape) {
		case shape_rock: ret = rock; break;
		case shape_paper: ret = paper; break;
		case shape_scissors: ret = scissors; break;
	}

	return ret;
}