#include "priority_queue.h"
#include <stdlib.h>
#include <stdio.h>

static void 
swap(struct Element* a, struct Element* b) {
	struct Element tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void
int_swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

struct PQueue* 
create_pqueue(int num) {
	struct PQueue* pq = malloc(sizeof(struct PQueue));	
	pq->element = malloc(sizeof(struct Element) * num);
	pq->map = malloc(sizeof(int) * num);
	pq->capacity = num;
	pq->size = 0;

	return pq;
}

void 
destroy_pqueue(struct PQueue* pq) {
	if (pq != NULL) {
		if (pq->element != NULL) {
			free (pq->element);
		}
		free (pq);
	}
}

void 
insert(struct PQueue* pq, int id, int key) {
	int i;

	if (pq->size < pq->capacity) {
		pq->element[pq->size].id = id;
		pq->element[pq->size].key = key;

		pq->map[id] = pq->size;

		for (i = pq->size; pq->element[(i-1) / 2].key > pq->element[i].key && (i-1) / 2 >= 0; i = (i-1) / 2) {
			swap(&pq->element[(i-1) / 2], &pq->element[i]);
			int_swap(&pq->map[ pq->element[(i-1) /2].id ], &pq->map[ pq->element[ pq->element[i].id ].id]);
		}
		++ pq->size;
	}
}

void 
decrease_key(struct PQueue* pq, int id, int key) {
	int i;
	i = pq->map[id];
	pq->element[i].key = key;
  for (; (i-1) / 2  >= 0 && pq->element[(i-1) / 2].key > pq->element[i].key; i = (i-1) / 2) {
		swap(&pq->element[i], &pq->element[(i-1) / 2]);
		int_swap(&pq->map[pq->element[i].id], &pq->map[pq->element[(i-1) / 2].id]);
	}
}

void 
extract_min(struct PQueue* pq, int* id, int* key) {
	int i, child;
	struct Element lastelem;

	if (pq->size > 0) {
		*id = pq->element[0].id;
		*key = pq->element[0].key;
		lastelem = pq->element[pq->size - 1];
		--pq->size;
		
		for(i = 0; i * 2 + 1 <= pq->size; i = child) {
			child = i * 2 + 1;

			if (child != pq->size && pq->element[child + 1].key < pq->element[child].key) {
				++ child; // select the right child
			}

			if (pq->element[child].key < lastelem.key) {
				pq->element[i] = pq->element[child];
			}
			else {
				break;
			}
		}
		pq->element[i] = lastelem;
	}
}


void 
print_pqueue(struct PQueue* pq) {
	int i;
	for (i = 0; i < pq->size; i++) {
		printf("key:%d<->id:%d\t", pq->element[i].key, pq->element[i].id);
	}
	printf("\n");
}
