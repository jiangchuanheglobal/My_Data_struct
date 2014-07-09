//#include "queue.h"
#include <stdio.h>
#include "trie.h"
int main() {
	struct PrefixTree* T = create_prefix_tree();
	char* str = "abc";
	char* test = "ab";
	insert(T, str, 3);
	insert(T, test, 2);
	if (search(T, test, 2)) {
		printf("find it!\n");
	}
	else {
		printf("not find it!\n");
	}
	printf("prefix count:%d\n", words_with_prefix(T, test, 2));
	return 0;
}
