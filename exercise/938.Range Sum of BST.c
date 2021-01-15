/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void trace(struct TreeNode* current, int low, int high, int *sum){
    if(!current)
        return NULL;
    
    if( current-> val  >= low && current-> val  <= high){
        *sum += current-> val;
        trace(current->left, low, high, sum);
        trace(current->right, low, high, sum);
    }
    else if(current-> val  > high )
        trace(current->left, low, high, sum);
    else
        trace(current->right, low, high, sum);
    
}
int rangeSumBST(struct TreeNode* root, int low, int high){
    
    int sum = 0;
    trace(root,low,high,&sum);
    return sum;

}
