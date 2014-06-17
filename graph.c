/*
 * graph representation
 * referred from: http://www.geeksforgeeks.org/graph-and-its-representations/
 */

// adjacent list
//====================================================
#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

struct Graph*
create_directed_graph(int num) {
	// new graph
	struct Graph* g = malloc(sizeof(struct Graph));
	g->no = num;
	// new head
	g->head = malloc(sizeof(struct Head) * num);
	int i;
	for (i = 0; i < num; i++) {
		g->head[i].next = NULL;
	}
	return g;
}

void 
destroy_graph(struct Graph* g) {
	if (g != NULL) {
		if (g->head != NULL) {
			free(g->head);
		}
		free(g);
	}
}
void
add_edge(struct Graph *g, int src, int dest) {
	// create a new node
	struct Node* node = malloc(sizeof(struct Node));
	node->id = dest;
	node->next = g->head[src].next;
	g->head[src].next	= node;	
//	// since graph is undirected, add opposite edge
//	node = malloc(sizeof(struct Node));
//	node->id = src;
//	node->next = g->head[dest].next;
//	g->head[dest].next	= node;	
	
}

void 
print_graph(struct Graph *g) {
	int i; 
	struct Node *node;
	for (i = 0; i < g->no; i++) {
		node = g->head[i].next;
		printf("head %d", i);
		while (node != NULL) {
			printf("->%d", node->id);
			node = node->next;
		}
		printf("\n");
	}
}
