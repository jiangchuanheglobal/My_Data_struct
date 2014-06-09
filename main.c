#include "queue.h"

int main() {
	int val;
	struct Queue* q = create_queue(20);
	enqueue(q, 0);
	enqueue(q, 3);
	enqueue(q, 2);
	enqueue(q, 8);
	enqueue(q, 10);
	enqueue(q, 12);

	enqueue(q, 12);
	enqueue(q, 0);
	enqueue(q, 3);
	enqueue(q, 2);
	enqueue(q, 8);
	enqueue(q, 10);
	enqueue(q, 0);
	enqueue(q, 3);
	enqueue(q, 2);
	enqueue(q, 8);
	enqueue(q, 10);

//	dequeue(q, &val);
//	dequeue(q, &val);
//	dequeue(q, &val);
//	dequeue(q, &val);
//	dequeue(q, &val);
	while (!is_empty(q)) {
		dequeue(q, &val);
		printf("dequeue: %d\n",val);
	}
	//print_queue(q);
	destroy_queue(q);
}
