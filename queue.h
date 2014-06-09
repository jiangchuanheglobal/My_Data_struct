#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
struct Queue {
	int* A;
	int size;
	int front;
	int rear;
	int amount;
};

struct Queue* create_queue(int s);
void destroy_queue(struct Queue* q);

void enqueue(struct Queue* q, int val);
void dequeue(struct Queue* q, int* val);


bool is_empty(struct Queue* q);
bool is_full(struct Queue* q);

void print_queue(struct Queue* q);
