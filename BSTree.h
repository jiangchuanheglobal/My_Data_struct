/*
 * binary search tree implementation
 *
 * operations:
 * 1. create_bstree
 * 2. destroy_bstree
 * 
 * 3. insert
 * 
 * 4. minimum
 * 5. transplant
 * 6. successor
 * 7. delete
 *
 * 8. search
 */

struct TreeNode {
	int elem;
	int key;
	struct TreeNode* pi;  // parent
	struct TreeNode* left;
	struct TreeNode* right;
};

struct BSTree {
	struct TreeNode* root;
};


