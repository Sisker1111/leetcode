/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void invert(struct TreeNode* cur){
    if(!cur)
        return;
    struct TreeNode* tmp = cur->left;
    cur->left = cur->right;
    cur->right = tmp;
    invert(cur->left);
    invert(cur->right);
}

struct TreeNode* invertTree(struct TreeNode* root){
    invert(root);
    return root;
}