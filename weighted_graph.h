
/*
 * weighted graph implementation
 * using just one dimension array
 */ 

struct Edge {
	int src;
	int dest;
	int weight;
};

struct Graph {
	struct Edge* edge;
	int V;
	int E;
};



struct Graph* create_graph(int V, int E);
