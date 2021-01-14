/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void Inorder(struct TreeNode *current, int *count, int* output){
    if(!current)
        return;
    Inorder(current->left, count, output);    
    output[(*count)++] = current->val;
    Inorder(current->right, count, output);       
    
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *output = (int *)malloc(101*sizeof(int));
    int count = 0;
    if(!root){
        *returnSize = 0;
        return output;
    }
    Inorder(root,&count,output);
    *returnSize = count;
    return output;
    
}
