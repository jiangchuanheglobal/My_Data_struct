/*
 * queue implementation
 * using circular array
 */
#include "queue.h"

bool 
is_empty(struct Queue* q) {
	return q->amount == 0 ? true:false;
}
bool 
is_full(struct Queue* q) {
	return q->amount == q->size ? true:false;
}
struct 
Queue* create_queue(int num) {
	struct Queue* q = malloc(sizeof(struct Queue));
	q->A = malloc(sizeof(int) * num);
	q->size = num;
	q->amount = 0;
	q->front = 0;
	q->rear = 0;
	return q;
}
void 
destroy_queue(struct Queue* q) {
	if (q != NULL) {
		if (q->A != NULL) {
			free(q->A);
		}
		free(q);
	}
}

void 
enqueue(struct Queue* q, int val) {
	if (!is_full(q)) {
		q->A[q->front] = val;
		q->amount++;
		if (q->front + 1 == q->size) {
			q->front = 0;
		}
		else {
			q->front++;
		}
	}
}
void 
dequeue(struct Queue* q, int* val) {
	if (!is_empty(q)) {
		*val = q->A[q->rear];
		q->amount--;
		if (q->rear + 1 == q->size) {
			q->rear = 0;
		}
		else {
			q->rear++;
		}
	}
}

void 
print_queue(struct Queue* q) {
	int i,j;
	if (!is_empty(q)) {
		for (i = 0, j = q->rear; i < q->amount; i++) {
			printf("|%d", q->A[j]);
			if (j + 1 == q->size) {
				j = 0;
			}
			else {
				j++;
			}
		}
		printf("\n");
	}
}
