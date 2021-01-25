
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_INT 2147483647
#define MIN(a,b) (((a)<(b))?(a):(b))
void Inorder(struct TreeNode* current, int *res, int *pre){
    if(!current)
        return;
    Inorder(current->left, res, pre);
    if(*pre != -1) *res = MIN(*res, current->val - *pre);
    *pre = current->val;
    Inorder(current->right, res, pre);
   
}
int getMinimumDifference(struct TreeNode* root){
    int res = MAX_INT, pre = -1;
    Inorder(root, &res, &pre);
    return res;
}


