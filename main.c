//#include "queue.h"
#include <stdio.h>
#include "linkedlist.h"
int main() {
//	struct PrefixTree* T = create_prefix_tree();
//	char* str = "abc";
//	char* test = "ab";
//	insert(T, str, 3);
//	insert(T, test, 2);
//	if (search(T, test, 2)) {
//		printf("find it!\n");
//	}
//	else {
//		printf("not find it!\n");
//	}
//	printf("prefix count:%d\n", words_with_prefix(T, test, 2));
  struct LinkedList* list = create_linkedlist();
	struct Node* node;
  insert_node(list, 0);
  insert_node(list, 2);
  insert_node(list, 4);
  insert_node(list, 6);
	delete_node(list, 2);
	print_linkedlist(list);
	printf("\n");
	
	node = search(list, 2);
	if (node != NULL) {
		printf("=%d",node->elem);
	}	
	return 0;
}
