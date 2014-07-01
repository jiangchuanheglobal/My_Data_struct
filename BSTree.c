/*
 * binary search tree implementation
 *
 */
#include <stdlib.h>
#include "BSTree.h"
struct BSTree* create_bstree();
void destroy_bstree(struct BSTree* tree);

void insert_tree_node(struct BSTree* tree, struct TreeNode* x);
void delete_tree_node(struct BSTree* tree, struct TreeNode* z);


// file local functions
static struct TreeNode* minimun(struct TreeNode* x);
static struct TreeNode* successor(struct TreeNode* x);
static void transplant(struct BSTree* tree, struct TreeNode* u, struct TreeNode* v);

struct BSTree* 
create_bstree() {
	struct BSTree* tree = malloc(sizeof(struct BSTree));
	tree->root = NULL;
	return tree;
}

void 
destroy_bstree(struct BSTree* tree) {
	if (tree != NULL) {
		if (tree->root != NULL) {
			// using postorder traversal to delete all nodes
		}
	}
}

void 
insert_tree_node(struct BSTree* tree, struct TreeNode* x) {
	struct TreeNode* node = tree->root;
	struct TreeNode* pi;
 	pi = NULL;
	while (node != NULL) {
		pi = node->pi;
		if (x->key <= node->key) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}

	if (pi == NULL) {
		// empty tree
		tree->root = x;
		x->pi = NULL;
	}
	else if (x->key <= pi->key) {
		// you are my left child
		pi->left = x;
		x->pi = pi;
	}
	else {
		// you are my right child
		pi->right = x;
		x->pi = pi;
	}
}

struct TreeNode* 
minimun(struct TreeNode* x) {
	if (x->left == NULL) {
		return x;
	}
	return minimun(x->left);
}

struct TreeNode* 
successor(struct TreeNode* x) {
	struct TreeNode* y = x->pi;

	// find successor at right child tree
	if (x->right != NULL) {
		return minimun(x->right);
	}

	// find successor in ancesstors
	while (y != NULL && x == y->right) {
		x = y;
		y = y->pi;
	}
	return y;
}

void 
transplant(struct BSTree* tree, struct TreeNode* u, struct TreeNode* v) {
	if (u->pi == NULL) {
		// u is the root
		tree->root = v;
	}
	else if (u->pi->left == u) {
		// u is the left child
		u->pi->left = v;
	}
	else {
		// u is the right child
		u->pi->right = v;
	}
	if (v != NULL) {
		v->pi = u->pi;
	}
}
void 
delete_tree_node(struct BSTree* tree, struct TreeNode* z) {
	struct TreeNode* y = minimun(z->right);

	if (z->left == NULL) {
		transplant(tree, z, z->right);
	}
	else if (z->right == NULL) {
		transplant(tree, z, z->left);
	}
	else {
		if (y->pi != z) {
			transplant(tree, y, y->right);
			y->right = z->right;
			y->right->pi = y;
		}
		transplant(tree, z, y);
		y->left = z->left;
		y->left->pi = y;
	}
}
