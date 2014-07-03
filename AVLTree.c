#include <stdlib.h>
#include <assert.h>
#include "AVLTree.h"

int height(struct TreeNode* x);
struct TreeNode* left_rotate(struct TreeNode* x);
struct TreeNode* right_rotate(struct TreeNode* x);
int max(int a, int b);
int balance_factor(struct TreeNode* x);
struct TreeNode* minimum(struct TreeNode* x);
struct TreeNode* successor(struct TreeNode* x);

int
max(int a, int b) {
	return (a > b)? a : b;
}

int 
height(struct TreeNode* x) {
	if (x == NULL) {
		return -1;
	}
	return x->height;
}
struct TreeNode* 
left_rotate(struct TreeNode* x) {
	assert(x->right != NULL);
	struct TreeNode* y;
	y	= x->right;
	x->right = y->left;
	y->left = x;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}


struct TreeNode* 
right_rotate(struct TreeNode* x) {
	struct TreeNode* y;
	y = x->left;
	x->left = y->right;
	y->right = x;

	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

int 
balance_factor(struct TreeNode* x) {
	if (x == NULL) {
		return -1;
	}
	return max(height(x->left), height(x->right)) + 1;
}

struct AVLTree* create_avltree();
void destroy_avltree(struct AVLTree* T);


/*
 * insert: we have 4 cases.
 * ------------------------
 * case #1: left - left
 * case #2: right - right
 * case #3: left - right
 * case #4: right - left
 */
struct TreeNode*
insert_helper(struct TreeNode* node, struct TreeNode* x) {
	int balance;
	if (node == NULL) {
		return x;
	}
	if (x->key <= node->key) {
		node->left = insert_helper(node->left, x);
	}
	else {
		node->right = insert_helper(node->right, x);
	}

	node->height = max(height(node->left), height(node->right)) + 1;
	balance = balance_factor(node);

	// case #1
	if (balance > 1 && x->key <= node->left->key) {
		return right_rotate(node);
	}
	// case #2
	if (balance < -1 && x->key > node->right->key) {
		return left_rotate(node);
	}
	// case #3
	if (balance > 1 && x->key > node->left->key) {
		node->left = left_rotate(node->left);
		return right_rotate(node);
	}
	// case #4
	if (balance < -1 && x->key <= node->right->key){
		node->right = right_rotate(node->right);
		return left_rotate(node);
	}
	return node;
}
void 
insert_node(struct AVLTree* T, struct TreeNode* x) {
		T->root = insert_helper(T->root, x);
}
struct TreeNode* 
minimum(struct TreeNode* x) {
	if (x->left == NULL) {
		return x;
	}
	return minimum(x->left);
}
/*
 * slight difference with BST
 */
struct TreeNode* 
successor(struct TreeNode* x) {
	return minimum(x);
}

/*
 * delete helper
 */
struct TreeNode*
delete_helper(struct TreeNode* root, struct TreeNode* x) {
	if (root == NULL) {
		return root;
	}
	if (x->key <= root->left->key && x->elem != root->elem) {
		return delete_helper(root->left, x);
	}
	else if (x->key > root->right->key) {
		return delete_helper(root->right, x);
	}
	if (root->left == NULL || root->right == NULL) {
		struct TreeNode* temp = root->left? root->left : root->right;
		// no child
		if (temp == NULL) {
			temp = root;
			root = NULL;
		}
		// only one child
		else {
			*root = *temp;
		}
		// free it
		free(temp);
	}
	// two children
	else {
		struct TreeNode* temp = minimum(root->right);
		root->key = temp->key;
		root->elem = temp->elem;
		root->right = delete_helper(root->right, temp);
	}

	if (root == NULL) {
		return root;
	}
	
	root->height = max(height(root->left), height(root->right));
	int balance = balance_factor(root);
	
	// case #1: left - left
	if (balance > 1 && balance_factor(root->left) >= 0) {
		return right_rotate(root);
	}
	// case #2: right - right
	else if (balance < -1 && balance_factor(root->right) <= 0) {
		return left_rotate(root);
	}
	// case #3: left - right
	else if (balance > 1 && balance_factor(root->left) < 0) {
		root->left = left_rotate(root->left);
		return right_rotate(root);
	}
	// case #3: right - left
	else if (balance < -1 && balance_factor(root->right) > 0) {
		root->right = right_rotate(root->right);
		return left_rotate(root);
	}

	return root;
}

void 
delete_node(struct AVLTree* T, struct TreeNode* x) {
	T->root = delete_helper(T->root, x);
}
