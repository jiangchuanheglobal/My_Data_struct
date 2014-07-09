#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "trie.h"

struct 
PrefixTree* create_prefix_tree() {
	struct PrefixTree* T = malloc(sizeof(struct PrefixTree));
	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	T->root = root;
	return T;
}
void 
insert(struct PrefixTree* T, char* str, int len) {
	int i;
	struct TreeNode* node;
	struct TreeNode* root = T->root;
	for (i = 0; i < len; i++) {
		if (root->child[str[i] - 'a'] == NULL) {
			node = malloc(sizeof(struct TreeNode));
			node->is_end = false;
			node->prefix_count = 0;
			root->child[str[i] - 'a'] = node;
		}
		root->child[str[i] - 'a']->prefix_count += 1;
		root = root->child[str[i] - 'a'];
	}
	root->is_end = true;
}
bool 
search(struct PrefixTree* T, char* str, int len) {
	int i;
	struct TreeNode* root = T->root;
	for (i = 0; i < len; i++) {
		if (root->child[str[i] - 'a'] == NULL) {
			return false;
		}
		root = root->child[str[i] - 'a'];
	}
	return true;
}

int 
words_with_prefix(struct PrefixTree* T, char* str, int len) {
	int i;
	struct TreeNode* root = T->root;
	for (i = 0; i < len; i++) {
		if (root->child[str[i] - 'a'] == NULL) {
			return 0;
		}
		root = root->child[str[i] - 'a'];
	}
	return root->prefix_count;
}

