#include "union_find.h"
#include <stdlib.h>

struct Unionfind* create_ufind(int cap) {
	struct Unionfind* ufind = malloc(sizeof(struct Unionfind));
	ufind->elem = malloc(sizeof(int) * cap);
	ufind->capacity = cap;
	return ufind;
}


void 
destroy_ufind(struct Unionfind* ufind) {

}
void 
make_set(struct Unionfind* set, int x) {
	if (x < set->capacity) {
		set->elem[x] = -1;
	}
}
int 
find_set(struct Unionfind* set, int x) {
	if (x < set->capacity) {
		if (set->elem[x] == -1) {
			return x;
		}
		return find_set(set, set->elem[x]);
	}
	// error
	return -1;
}
void 
union_set(struct Unionfind* set, int x, int y) {
	int repre_x, repre_y;
	if (x < set->capacity && y < set->capacity) {
		repre_x = find_set(set, x);
		repre_y = find_set(set, y);
		set->elem[repre_y] = repre_x;
	}
}
