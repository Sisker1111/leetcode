/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root){
    
    if(root == NULL)
        return 0;
    int left_level = maxDepth(root->left);
    int right_level = maxDepth(root->right);
    return (left_level > right_level) ? left_level+1 : right_level+1;
}