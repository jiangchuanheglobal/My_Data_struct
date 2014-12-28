#include <stdbool.h>

struct Deque {
    int *arr;
    int front;
    int rear;
    int capacity;
};


struct Deque *create_deque(int capacity);
void destroy_deque(struct Deque*);

bool is_empty(struct Deque*);
bool is_full(struct Deque*);

void add_at_front(struct Deque*, int val);
void add_at_rear(struct Deque*, int val);
int get_from_front(struct Deque*);
int get_from_rear(struct Deque*);

int peek_from_front(struct Deque*);
int peek_from_rear(struct Deque*);




