/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void DFS(struct TreeNode* p, struct TreeNode* q, int *result){
    if( !(*result) )
        return;
    if( p->val == q->val){
        if( p->left && q->left) DFS(p->left, q->left, result);
        else if( !p->left && !q->left) ;
        else *result = 0;
        
        if( p->right && q->right) DFS(p->right, q->right, result);
        else if( !p->right && !q->right) ;
        else *result = 0;
    }
    else
        *result = 0;
        
}
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    
    int result = 1;
    if( !p && !q ) return 1;
    else if( p && q ){
        DFS(p,q,&result);
        return result;
    }
    else return 0;
    
}