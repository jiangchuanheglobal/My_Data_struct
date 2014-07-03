#include <stdlib.h>
#include "SplayTree.h"


struct TreeNode* 
left_rotate(struct TreeNode* x) {
	struct TreeNode* y;

	y = x->right;
	x->right = y->left;
	y->left = x;	
	return y;
}

struct TreeNode* 
right_rotate(struct TreeNode* x) {
	struct TreeNode* y;

	y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

struct SplayTree* 
create_splaytree() {
	struct SplayTree* T = malloc(sizeof(struct SplayTree));
	T->root = NULL;
	return T;
}
void
destroy_splaytree(struct SplayTree* root) {
}

struct TreeNode* 
splay(struct TreeNode* root, struct TreeNode* x) {
	if (root == NULL || root->key == x->key) {
		return root;
	}

	// x lies in the left subtree
	if (x->key < root->key) {
		if (root->left == NULL) {
			return root;
		}
		// 1st zig 
		if (x->key < root->left->key) {
			root->left->left = splay(root, root->left->left);
			root = right_rotate(root);
		}
		// 1st zag
		else if (x->key > root->left->key) {
			root->left->right = splay(root, root->left->right);
			if (root->left->right != NULL) {
				root->left = left_rotate(root->left);
			}
		}
		// 2nd zig
		return (root->left == NULL)? root : right_rotate(root);
	}
	// x lies in the right subtree
	else {
		if (root->right == NULL) {
			return root;
		}
		// 1st zag
		if (x->key > root->right->key) {
			root->right->right = splay(root, root->right->right);
			root = left_rotate(root);
		}
		// 1st zig
		else if (x->key < root->right->key) {
			root->right->left = splay(root, root->right->left);
			if (root->right->left != NULL) {
				root->right = right_rotate(root->right);
			}
		}
		// 2nd zag
		return (root->right == NULL)? root: left_rotate(root);
	}
}

struct TreeNode* lookup(struct SplayTree* T, struct TreeNode* x) {
	return splay(T->root, x);
}


void 
insert(struct SplayTree* T, struct TreeNode* x) {
	struct TreeNode* node;
	if (T->root == NULL) {
		T->root = x;
		return;
	}
	
	// splay the cloest node to the top of tree
	node = splay(T->root, x);
	if (node->key == x->key && node->elem == x->elem) {
		// find the same node 
		return;
	}
	
	// do insert
	if (x->key < T->root->key) {
		x->left = T->root->left;
		x->right = T->root;
		T->root->left = NULL;
		T->root = x;
	}
	else {
		x->right = T->root->right;
		x->left = T->root;
		T->root->right = NULL;
		T->root = x;
	}
}

