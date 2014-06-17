#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "heap.h"

/*
 * extract_min is referred from wiki
 *
 */
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
		for(i = hp->size; hp->node[(i - 1) / 2] > hp->node[i] && ((i - 1) / 2) >=	0; i = (i - 1) / 2) {
			swap(&hp->node[(i - 1) / 2], &hp->node[i]);
		}
		hp->size = hp->size + 1;
	}
}

void
extract_min(struct Heap* hp, int* key) {
	int i, child;
	int lastelem;

	if (hp->size > 0) {
		*key = hp->node[0];
		lastelem = hp->node[--hp->size];
		for (i = 0; i * 2 + 1 <= hp->size; i = child) {
			child = i * 2 + 1;
			if (child != hp->size && hp->node[child + 1] < hp->node[child]) {
				child++; // select right child
			}
			if (lastelem > hp->node[child]) {
				hp->node[i] = hp->node[child];
			}
			else {
				break; // we find a place for last element, it's current i which satisfy lastelement < child < child's brother
							/*
							 *        i
							 *      /   \
							 *    child 
							 */
			} 
		}
		hp->node[i] = lastelem;	
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
