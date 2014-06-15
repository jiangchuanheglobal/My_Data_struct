#include "stdbool.h"
struct Stack{
	int* stk;
	int capacity;
	int top;
};

struct Stack* create_stack(int cap);
void destroy_stack(struct Stack* st);

bool is_full(struct Stack* st);
bool is_empty(struct Stack* st);

void push(struct Stack* st, int data);
void pop(struct Stack* st, int *data);

void top(struct Stack* st, int *data);

void print_stack(struct Stack* st);
