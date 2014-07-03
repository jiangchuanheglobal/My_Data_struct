/*
 * AVL tree implementation
 * referred: http://www.geeksforgeeks.org/avl-tree-set-1-insertion/
 *
 */

struct TreeNode {
	int key;
	int elem;

	struct TreeNode* left;
	struct TreeNode* right;
	int height;
};

struct AVLTree {
	struct TreeNode* root;
};


struct AVLTree* create_avltree();
void destroy_avltree(struct AVLTree* T);

void insert_node(struct AVLTree* T, struct TreeNode* x);
void delete_node(struct AVLTree* T, struct TreeNode* x);


