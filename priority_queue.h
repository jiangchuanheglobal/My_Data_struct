/*
 * priority queue
 * implementation using min heap
 * to serve dijkstra algorithm
 */

struct Element {
	int key;   // specify weight of each element
	int id;
};

struct PQueue {
	struct Element* element;
	int* map; // mapping id to its position in heap array, optimizing lookup time to be O(1)
	int capacity;
	int size;
};

struct PQueue* create_pqueue(int num);
void destroy_pqueue(struct PQueue* pq);

void insert(struct PQueue* pq, int id, int key);
void decrease_key(struct PQueue* pq, int id, int key);

void extract_min(struct PQueue* pq, int* id, int* key);

void print_pqueue(struct PQueue* pq);
