#include <stdlib.h>
#include "deque.h"

struct Deque*
create_deque(int capacity) {
    struct Deque* deq = malloc(sizeof(struct Deque));
    deq->arr = malloc(sizeof(int) * capacity);
    deq->front = 0;
    deq->rear = capacity - 1;
    deq->capacity = capacity;

    return deq;
}
void 
destroy_deque(struct Deque* deq) {
    if (deq != NULL) {
        free(deq->arr);
        free(deq);
    }
}

bool 
is_empty(struct Deque* deq) {
    return deq->front == 0 && deq->rear == deq->capacity;
}
bool 
is_full(struct Deque* deq) {
    return deq->front == deq->rear;
}

void 
add_at_front(struct Deque* deq, int val) {
    if (!is_full(deq)) {
        deq->arr[deq->front++] = val;
    }
}
void 
add_at_rear(struct Deque* deq, int val) {
    if (!is_full(deq)) {
        deq->arr[deq->rear--] = val;
    }
}
int 
get_from_front(struct Deque* deq) {
    if (deq->front > 0) {
        return deq->arr[--deq->front];
    }
    return -1;
}
int 
get_from_rear(struct Deque* deq) {
    if (deq->rear < deq->capacity - 1) {
        return deq->arr[++deq->rear];
    }
    return -1;
}

int 
peek_from_front(struct Deque* deq) {
    if (deq->front > 0) {
        return deq->arr[deq->front-1];
    }
    return -1;
}
int 
peek_from_rear(struct Deque* deq) {
    if (deq->rear < deq->capacity - 1) {
        return deq->arr[deq->rear+1];
    }
    return -1;
}
