//#include "queue.h"
#include <stdio.h>
#include "priority_queue.h"
int main() {
	int id, key;
	struct PQueue* pq = create_pqueue(20);

	insert(pq, 0, 5);
	insert(pq, 1, 14);
	decrease_key(pq, 1, 2);
//	insert(pq, 2, 23);
//	insert(pq, 3, 32);
//	insert(pq, 4, 41);
//	insert(pq, 5, 87);
//	insert(pq, 6, 90);
//	insert(pq, 7, 50);
//	insert(pq, 8, 64);
//	insert(pq, 9, 53);
//	
//		
//	extract_min(pq, &id, &key);
//	extract_min(pq, &id, &key);
//	printf("extract min - id:%d-key:%d \n", id, key);
	print_pqueue(pq);
//	print_pqueue(pq);
	destroy_pqueue(pq);
}
