/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int depth_tree(struct TreeNode* root, int *diameter ){
    if(!root)
        return 0;
    int left = depth_tree(root->left, diameter );
    int right = depth_tree(root->right, diameter );
    if((left + right) > *diameter )
        *diameter  = left + right;
    return (left>right) ? left+1 :right+1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    int diameter  = 0;
    depth_tree(root, &diameter );
    return diameter ;
}