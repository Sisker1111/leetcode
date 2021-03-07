/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// int *output, idx;

// int heightoftree(struct TreeNode *root){
//     if(!root)
//         return 0;
//     int leftsubtree = heightoftree(root->left);
//     int rightsubtree = heightoftree(root->right);
//     return (leftsubtree > rightsubtree) ? leftsubtree + 1 : rightsubtree + 1;
// }
    

// void currentlevel(struct TreeNode *root, int level){
//     if(!root){
//         output[idx++] = -1;
//         return;
//     }
//     if (level == 1){
//         output[idx++] = root->val;
//     }
//     else if (level > 1){ 
//         currentlevel(root->left, level-1); 
//         currentlevel(root->right, level-1);
//     }	
// }

bool is_Symmetric(struct TreeNode* left, struct TreeNode* right){
    if(!left || !right){
        return left == right ; 
    }
    if(left->val != right->val)
        return false ; 
    return is_Symmetric(left->left, right->right) && is_Symmetric(left->right, right->left);
}
bool isSymmetric(struct TreeNode* root){
    
    if(!root)
        return true;
    return is_Symmetric(root->left,root->right);
    
    // int height = heightoftree(root);
    // idx = 0;
    // for(int i = 1; i <= height; i++){
    //     output = (int *)calloc(pow(2,i-1),sizeof(int));
    //     currentlevel(root,i);
    //     for(int j=0; j<idx/2; j++){
    //         if(output[j] != output[idx-j-1]){
    //             return false;
    //         }
    //     }
    //     idx=0 ; 
    // }
    // return true;
    
}