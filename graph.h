//#ifndef _REPRE_H
//#define _REPRE_H

/*
 * graph representation
 * using adjacency list
 *
 */
struct Node {
	struct Node* next;
	int id;
};

struct Head {
	struct Node* next;
};
struct Graph {
	struct Head* head;
	int no;
};


struct Graph* create_directed_graph(int num);
void add_edge(struct Graph *g, int src, int dest);
void print_graph(struct Graph *g);
void destroy_graph(struct Graph* g);

//#endif
