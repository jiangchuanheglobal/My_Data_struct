#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "heap.h"

static 
void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
struct Heap* 
create_min_heap(int n) {
	struct Heap* hp = malloc(sizeof(struct Heap));
	hp->node = malloc(sizeof(int) * n);
	hp->capacity = n;
	hp->size = 0;
	return hp;
}

void 
destroy_min_heap(struct Heap* hp) {
	if (hp != NULL) {
		if (hp->node != NULL) {
			free(hp->node);
		}
		free(hp);
	}
}

void 
insert(struct Heap* hp, int key) {
	int i, p;
	if (hp->size < hp->capacity) {
		hp->node[hp->size] = key;
		for(i = hp->size; hp->node[i / 2 - 1] > hp->node[i] && (i/2-1) >=	0; i = i / 2 - 1) {
			swap(&hp->node[i / 2 - 1], &hp->node[i]);
		}
		hp->size = hp->size + 1;
	}
}

void
extract_min(struct Heap* hp, int* key) {
	int i, left, right;

	if (hp->size > 0) {
		*key = hp->node[0];
		i = 0;
		while ((i+1) * 2 - 1 < hp->size){
			left = (i+1) * 2 - 1; 
			right = (i+1) * 2;

			/*
			 * note: we have two conditions.
			 */

			// only one child
			if (right >= hp->size) {
				hp->node[i] = hp->node[left];
				i = left;
				break;
			}
		
			// two children, check which one is smaller 
			else if (hp->node[left] < hp->node[right]) {
				hp->node[i] = hp->node[left];
				i = left;
			}
			else {
				hp->node[i] = hp->node[right];
				i = right;
			}
		}

		// adjust the leaf level
		for(; i+1 < hp->size; i++ ) {
			hp->node[i] = hp->node[i+1];
		}
		hp->size = hp->size - 1;
	}
}

void 
print_heap(struct Heap* hp) {
	int i;
	for (i = 0; i < hp->size; i++) {
		printf("%d ", hp->node[i]);
	}
	printf("\n");
}
