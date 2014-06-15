//#include "queue.h"
#include <stdio.h>
#include "heap.h"
int main() {
	int min;
	struct Heap* hp = create_min_heap(10);
	insert(hp, 6);
	insert(hp, 7);
	insert(hp, 12);
	insert(hp, 10);
	insert(hp, 15);
	insert(hp, 17);
	insert(hp, 5);
//	insert(hp, 0);
	print_heap(hp);
	//extract_min(hp, &min);
	//print_heap(hp);
	destroy_min_heap(hp);
}
