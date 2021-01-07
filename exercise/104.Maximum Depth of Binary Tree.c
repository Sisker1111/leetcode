/**123132
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int traversal(struct TreeNode* node){
    if(node == NULL)
        return 0;
    int left_level = traversal(node->left);
    int right_level = traversal(node->right);
    if(left_level >= right_level)
        return left_level+1;
    else
        return right_level+1;
    
}
int maxDepth(struct TreeNode* root){
    
    if(root == NULL)
        return 0;
    return traversal(root);
    
    
}