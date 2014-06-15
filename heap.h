/*
 * heap operations
 *
 */

struct Heap {
	int *node;
	int size;
	int capacity;
};

struct Heap* create_min_heap(int n);
void destroy_min_heap(struct Heap* hp);

void insert(struct Heap* hp, int key);
void extract_min(struct Heap* hp, int* key);

void print_heap(struct Heap* hp);
