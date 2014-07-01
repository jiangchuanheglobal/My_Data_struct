#include <stdlib.h>
#include "weighted_graph.h"
struct Graph* 
create_graph(int V, int E) {
	struct Graph* g = malloc(sizeof(struct Graph));
	g->edge = malloc(sizeof(struct Edge) * E);
	g->E = E;
	g->V = V;
	return g;
}
