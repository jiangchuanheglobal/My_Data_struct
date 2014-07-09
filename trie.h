#include <stdbool.h>
#define MAX_CHAR_NUM 26
struct TreeNode {
	struct TreeNode* child[MAX_CHAR_NUM];
	bool is_end;
	int prefix_count;
};

struct PrefixTree {
	struct TreeNode* root;
};

struct PrefixTree* create_prefix_tree();
void insert(struct PrefixTree* T, char* str, int len);
bool search(struct PrefixTree* T, char* str, int len);
int words_with_prefix(struct PrefixTree* T, char* str, int len);
