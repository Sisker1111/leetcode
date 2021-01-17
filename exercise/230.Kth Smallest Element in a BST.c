/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int count = 0;
int ans ;
int output;
void Inorder_Traversals(struct TreeNode* node) 
{ 
  
    if (node == NULL || count > ans) 
        return; 
    if( !node->left && !node->right){
        if(++count == ans) output = node->val;
        return;
    }
    Inorder_Traversals(node->left);
    if(++count == ans) output = node->val;
    Inorder_Traversals(node->right); 
} 

int kthSmallest(struct TreeNode* root, int k){
    ans = k;
    Inorder_Traversals(root); 
    count = 0;
    return output;
    
}