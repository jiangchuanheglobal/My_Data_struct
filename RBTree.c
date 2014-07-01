#include <stdlib.h>
#include <assert.h>
#include "RBTree.h"

/*
 * red black implementation
 * 
 * invariants:
 * #1 root - black
 * #2 root - NULL path, same number of black nodes
 * #3 red parent - black children
 */

struct TreeNode* 
minimun(struct TreeNode* x) {
	if (x->left == NULL) {
		return x;
	}
	return minimun(x->left);
}
void insert_fix_up(struct RBTree*, struct TreeNode* );

struct RBTree* create_rbtree() {
	struct RBTree* tree = malloc(sizeof(struct RBTree));
	tree->root = NULL;
	return tree;
}

void left_rotate(struct RBTree* T, struct TreeNode* x) {
	struct TreeNode* y;
	
	y = x->right;
	// y->left & x
	if (y->left != NULL) {
		y->left->pi = x;
	}
	x->right = y->left;
	
	// y & x->pi
	if (x->pi == NULL) {
		T->root = y;
	}
	else if (x == x->pi->left) {
		x->pi->left = y;
	}
	else {
		x->pi->right = y;
	}
	y->pi = x->pi;
	// x & y
	x->pi = y;
	y->left = x;	
}
void right_rotate(struct RBTree* T, struct TreeNode* x) {
	struct TreeNode* y;

	y = x->left;
	if (y->right != NULL) {
		y->right->pi = x;
	}
	x->left = y->right;

	if (x->pi == NULL) {
		T->root = x;
	}
	else if (x->pi->left == x) {
		x->pi->left = y;
	}
	else {
		x->pi->right = y;
	}
	y->pi = x->pi;

	x->pi = y;
	y->right = x;
}

void insert(struct RBTree* T, struct TreeNode* z) {
	struct TreeNode* x;
	struct TreeNode* y;

	y = NULL;
	x = T->root;
	while (x != NULL) {
		y = x;
		if (z->key <= x->key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}

	if (y == NULL) {
		// root
		T->root = z;
	}
	else if (z->key <= y->key) {
		z = y->left;
	}
	else {
		z = y->right;
	}
	z->pi = y;

	z->color = RED;
	z->left = NULL;
	z->right = NULL;

	insert_fix_up(T, z);
}

/* new node inserted as left subtree child
 * --------------------------------
 * note: since we always treat the new inserted node as red node,
 * there will be three conditions we need to do fix up.
 *
 * case #1: pi & uncle both are red
 *
 * case #2: pi == red, uncle == black, new node == pi->left (this case is Intro to Alg case #3)
 *
 * case #3: pi == red, uncle == black, new node == pi->right
 *
 * note: if case #1 is done, then case #2 must follow it no matter what.
 */
void insert_fix_up(struct RBTree* T, struct TreeNode* z) {
	struct TreeNode* y;
	assert(z->pi != NULL);
	while (z->pi->color == RED) {
		if (z->pi == z->pi->pi->left) {
			y = z->pi->pi->right;

			// case #1
			if (y->color == RED) {
				y->color = BLACK;
				z->pi->color = BLACK;
				z->pi->pi->color = RED;
				z = z->pi->pi;
			}
		 // case #3
			else if (z == z->pi->right)	{
				z = z->pi;
				left_rotate(T, z);
			}
		 // case #2
		 z->pi->pi->color = RED;
		 z->pi->color = BLACK;
		 right_rotate(T, z->pi->pi);
		}
		else {
			y = z->pi->pi->left;
			
			if (y->color == RED) {
				y->color = BLACK;
				z->pi->color = BLACK;
				z->pi->pi->color = RED;
				z = z->pi->pi;
			}
			else if (z == z->pi->left) {
				z = z->pi;
				right_rotate(T, z);
			}
			
			z->pi->pi->color = RED;
			z->pi->color = BLACK;
			left_rotate(T, z->pi->pi);
		}
	}

	T->root->color = BLACK;
}

void
transplant(struct RBTree* T, struct TreeNode* u, struct TreeNode* v) {
	if (u->pi == NULL) {
		T->root = v;
	}
	else if (u->pi->left == u) {
		u->pi->left = v;
	}
	else {
		u->pi->right = v;
	}
	v->pi = u->pi;
}

void
delete_fix_up(struct RBTree* T, struct TreeNode* x) {
	struct TreeNode* w;
	while (x != T->root && x->color == BLACK) {
		// from left subsubtree
		if (x == x->pi->left) {
			// case #1
			if (w->color == RED) {
				w->color = BLACK;
				x->pi->color = RED;
				left_rotate(T, x->pi);
			}
			// case #2
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->pi;
			}
			// case #3
			else if (w->right->color == BLACK) {
				w->left->color = BLACK;
				w->color = RED;
				right_rotate(T, w);
				w = x->pi->right;
			}
			// cae #4
			w->color = x->pi->color;
			x->pi->color = BLACK;
			w->right->color = BLACK;
			left_rotate(T, x->pi);
			x = T->root;
		}
		// from right subtree
		else {
			w = x->pi->left;
			// case #1
			if (w->color == RED) {
				w->color = BLACK;
				x->pi->color = RED;
				right_rotate(T, x->pi);
				w = x->pi->left;
			}
			// case #2
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->pi;
			}
			// case #3
			else if (w->left->color == BLACK) {
				w->right->color = BLACK;
				w->color = RED;
				left_rotate(T, w);
				w = x->pi->left;
			}
			// case #4
			w->color = x->pi->color;
			x->pi->color = BLACK;
			w->right->color = BLACK;
			right_rotate(T, x->pi);
			x = T->root;
		}
	}
	x->color = BLACK;
}
void 
delete(struct RBTree* T, struct TreeNode* z) {
	struct TreeNode* x;
	struct TreeNode* y;
	enum Color y_original_color;	
	y = z;
	y_original_color = y->color;	

	// only has right child
	if (z->left == NULL) {
		x = z->right;
		transplant(T, z, x);
	}
	// only has left child
	else if (z->right == NULL) {
		x = z->left;
		transplant(T, z, x);
	}
	else {
		y = minimun(z->right);
		y_original_color = y->color;
		x = y->right;
		assert(x != NULL);
		// case: y.pi == z
		if (y->pi == z) {
			x->pi = z;
		}
		//
		else {
			transplant(T, y, y->right);
			// y and z->right
			y->right = z->right;
			y->right->pi = y;
		}
		transplant(T, z, y);
		y->left = z->left;
		y->left->pi = y;
		y->color = z->color;
		if (y_original_color == BLACK) {
			delete_fix_up(T, x);
		}
	}
}
