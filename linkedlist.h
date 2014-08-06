struct Node {
	int elem;
	struct Node* next;
};

struct LinkedList {
	struct Node* fake_head;
};

struct LinkedList* create_linkedlist();
void destroy_linkedlist(struct LinkedList*);

void insert_node(struct LinkedList*, int elem);
void delete_node(struct LinkedList*, int elem);
struct Node* search(struct LinkedList*, int elem);
void print_linkedlist(struct LinkedList* list);
