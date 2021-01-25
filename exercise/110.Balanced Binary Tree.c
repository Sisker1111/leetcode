/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int trace(struct TreeNode* current, int *result){
    
    if(!current) return 0;
    int left = trace(current->left, result);
    if( left == -1 ) return -1;
    int right = trace(current->right, result);
    if( right == -1 ) return -1;
    
    if( left >= right){
        if( left - right > 1){
            *result = 0;
            return -1;
        }
        else
            return left+1;
    }
    else{
        if( right - left > 1){
            *result = 0;
            return -1;
        }
        else
            return right+1;
    }
    
}

bool isBalanced(struct TreeNode* root){
    int result = 1;
    trace(root,&result);
    return result;

}