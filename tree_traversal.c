/*
 * pre, in post-order
 */

/*
 * recursive implementation
 * ------------------------------
 * preorder(struct Tree* root) {
 *  if (root == NULL) {
 *   return;
 *  }
 *  printf("->%d", root->val);
 *  preorder(root->left);
 *  preorder(root->right);
 * }
 *
 */

/*
 * iterative implementation
 * ------------------------------
 *

