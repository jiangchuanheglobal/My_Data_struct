/*
 * skip list implementation
 *
 */
#define ERR_NOT_FIND -1
#define MAX_LEVEL 10

struct Node {
	int key;
	int val;
	struct Node* forward[MAX_LEVEL];
};

struct SkipList {
	struct Node* header;
	int level;
};

struct SkipList* create_skiplist();
void destroy_skiplist(struct SkipList* list);

int search(struct SkipList* list , int key);
void insert_key(struct SkipList* list, int key, int val);
void delete_key(struct SkipList* list, int key);
