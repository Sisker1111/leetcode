/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int post_order(struct TreeNode** ans,int *flag, struct TreeNode* root, struct TreeNode* p, struct TreeNode* q){
    if(!root || *flag)
        return 0;
    if(root == p){
        *ans = p;
        return 1;
    }
    if(root == q){
        *ans = q;
        return 1;
    }
    int left = post_order(ans, flag, root->left, p, q);
    int right = post_order(ans, flag, root->right, p, q);
    if( left && right){
        *ans = root;
        *flag=1;
    }
    return left | right; 
        
}
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode** ans = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    int flag=0;
    *ans = NULL;
    post_order(ans,&flag, root, p, q);
    return *ans;
    
}