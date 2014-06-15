/*
 * stack implementation
 * using array
 */
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


struct Stack* 
create_stack(int cap) {
	struct Stack* st = malloc(sizeof(struct Stack));
	st->stk = malloc(sizeof(int) * cap);
	st->capacity = cap;
	st->top = 0;
	return st;
}

void 
destroy_stack(struct Stack* st) {
	if (st != NULL) {
		if (st->stk != NULL) {
			free(st->stk);
		}
		free(st);
	}
}

bool 
is_full(struct Stack* st) {
	return st->top == st->capacity? true:false;
}
bool 
is_empty(struct Stack* st) {
	return st->top == 0? true:false;
}

void 
push(struct Stack* st, int data) {
	if (!is_full(st)) {
		st->stk[st->top] = data;
		st->top++;
	}
}
void 
pop(struct Stack* st, int* data) {
	if (!is_empty(st)) {
		st->top--;
		*data = st->stk[st->top];
	}
}

void 
top(struct Stack* st, int *data) {
	int top;
	if (!is_empty(st)) {
		top = st->top - 1;
		*data = st->stk[top];
	}
}

void
print_stack(struct Stack* st) {
	int i;
	if (!is_empty(st)) {
		for (i = st->top - 1; i >= 0; i--) {
			printf("%d\n", st->stk[i]);
		}
	}
}
