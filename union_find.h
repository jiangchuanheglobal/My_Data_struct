/*
 * union find implementation
 * using array
 *
 */

struct Unionfind {
	int* elem;
	int capacity;
};

struct Unionfind* create_ufind(int cap);
void destroy_ufind(struct Unionfind* ufind);

void make_set(struct Unionfind* set, int x);
int find_set(struct Unionfind* set, int x);
void union_set(struct Unionfind* set, int x, int y);


