//#include "queue.h"
#include <stdio.h>
#include "SegmentTree.h"
int main() {
	int arr[] = {1, 3, 5, 7, 9, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	int *tree = create_segment_tree(arr, n);
	printf("range = %d\n", get_sum(tree, n, 1, 3));
	update_value(arr, tree, n, 1, 10); 
	printf("range = %d\n", get_sum(tree, n, 1, 3));
	return 0;
}
