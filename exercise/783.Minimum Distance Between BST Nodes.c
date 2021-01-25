/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// int temp[100]={0};
// int count;
// void Inorder(struct TreeNode* root){
//     if(!root)
//         return ;
//     Inorder(root->left);
//     temp[count++] = root->val;
//     Inorder(root->right);
    
// }
// int minDiffInBST(struct TreeNode* root){
//     count = 0;
//     int min = 2147483647;
//     Inorder(root);
//     for(int i=0; i<count-1; i++){
//         if(  temp[i+1]-temp[i] < min )
//             min = temp[i+1]-temp[i];
//     }
//     return min;
    
// }

// 解法同530.
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
int minDiffInBST(struct TreeNode* root){
    int res = MAX_INT, pre = -1;
    Inorder(root, &res, &pre);
    return res;
}

