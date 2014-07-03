/*
 * splay tree implementation
 * referred: http://www.geeksforgeeks.org/splay-tree-set-1-insert/
 *
 */

struct TreeNode {
	int key;
	int elem;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct SplayTree {
	struct TreeNode* root;
};



struct SplayTree* create_splaytree();
void destroy_splaytree(struct SplayTree* root);

struct TreeNode* splay(struct TreeNode* root, struct TreeNode* x);
void insert(struct SplayTree* T, struct TreeNode* x);
