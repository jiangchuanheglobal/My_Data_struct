/*
 * linked list implementation
 *
 * note:
 * singly
 * doubly 
 * circular linked list
 *
 * note: how to do sorting on linked list?
 */
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

struct LinkedList*
create_linkedlist() {
	struct LinkedList* list = malloc(sizeof(struct LinkedList));
	list->fake_head = malloc(sizeof(struct Node));
	list->fake_head->next = NULL;
	return list;
}
void 
destroy_linkedlist(struct LinkedList* list) {
	if (list == NULL) {
		return;
	}
	struct Node* node = list->fake_head;
	struct Node* tmp;
	while (node != NULL) {
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(list);
}

void 
insert_node(struct LinkedList* list, int elem) {
	if (list == NULL) {
		return;
	}
	struct Node* tmp = list->fake_head->next;
	struct Node* new_node = malloc(sizeof(struct Node));
	new_node->elem = elem;
	new_node->next = tmp;
	list->fake_head->next = new_node;	
}
void delete_node(struct LinkedList* list, int elem) {
	if (list == NULL) {
		return;
	}
	struct Node* tmp;
	struct Node* pi = list->fake_head;
	struct Node* child = list->fake_head->next;
	while (child != NULL) {
		if (child->elem == elem) {
			break;
		}
		pi = child;
		child = child->next;
	}
  pi->next = child->next;
  free(child);
}
struct Node* 
search(struct LinkedList* list, int elem) {
	if (list == NULL) {
		return NULL;
	}
	struct Node* node = list->fake_head->next;
	while (node != NULL) {
		if (node->elem == elem) {
			return node;
		}
		node = node->next;
	}
	return NULL;
}

void print_linkedlist(struct LinkedList* list) {
	if (list == NULL) {
		return;
	}
	struct Node* node = list->fake_head->next;
	while (node != NULL) {
		printf("->%d", node->elem);
		node = node->next;
	}
}
