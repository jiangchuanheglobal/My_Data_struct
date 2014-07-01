/*
 * red black tree implementation
 *
 * operations:
 * 1. create_rbtree
 * 2. destroy_rbtree
 * 
 * 3. insert
 * 
 * 4. left_rotate
 * 5. right_rotate
 *  . insert_fix_up
 *
 * 6. delete
 *
 * 7. search
 */
enum Color {RED, BLACK};

struct TreeNode {
	int elem;
	int key;
	struct TreeNode* pi;  // parent
	struct TreeNode* left;
	struct TreeNode* right;
	enum Color color;
};

struct RBTree {
	struct TreeNode* root;
};

struct RBTree* create_rbtree();
void insert(struct RBTree* T, struct TreeNode* z);
