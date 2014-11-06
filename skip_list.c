#include <stdlib.h>
#include "skip_list.h"

struct SkipList* 
create_skiplist() {
	struct SkipList* list = malloc(sizeof(struct SkipList));
	list->level = 0;
	list->header = NULL;
	return list;
}
void 
destroy_skiplist(struct SkipList* list) {
	
}
int 
search(struct SkipList* list , int key) {
	int i;
	struct Node* x = list->header;
	for (i = list->level - 1; i >= 0 ; i--) {
		while (x->forward[i]->key < key) {
			x = x->forward[i];
		}
	}
	x = x->forward[0];
	if (x->key == key) {
		return x->val;
	} else {
		return ERR_NOT_FIND;
	}
}
void 
insert_key(struct SkipList* list, int key, int val) {
	struct Node* update[MAX_LEVEL];
	int i;
	int newLevel;
	struct Node* x = list->header;
	struct Node* new_node;
	for (i = list->level - 1; i >= 0; i--) {
		while (x->forward[i]->key < key) {
			x = x->forward[i];
		}
		update[i] = x;
	}
	x = x->forward[0];
	if (x->key == key) {
		x->val = val;
	} else {
		newLevel = random_level();
		if (newLevel > list->level)	 {
			for (i = newLevel; i >= list->level; i--) {
				update[i] = list->header; // prepare to init newly part
			}
			list->level = newLevel;
		}
	  new_node = make_node(newLevel, key, val);
		for (i = 0; i < list->level; i++) {
			new_node->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = new_node;
		}
	}
}
void 
delete_key(struct SkipList* list, int key) {
	struct Node* update[MAX_LEVEL];
	int i;
	int newLevel;
	struct Node* x = list->header;
	struct Node* new_node;
	for (i = list->level - 1; i >= 0; i--) {
		while (x->forward[i]->key < key) {
			x = x->forward[i];
		}
		update[i] = x;
	}
	x = x->forward[0];
	if (x->key == key) {
		for (i = 0; i < list->level; i++) {
			if (update[i]->forward[i] != x) {
				break;
			}
			update[i]->forward[i] = x->forward[i];
		}
		free(x);
		while (list->level > 0 && list->header->forward[list->level] == NULL) {
			--list->level;
		}
	}
}
