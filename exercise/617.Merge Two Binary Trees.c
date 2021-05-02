/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* create(){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void merge(struct TreeNode** merge_tree, struct TreeNode* root1, struct TreeNode* root2){
    
    if( root1 && root2 ){
        *merge_tree = create();
        (*merge_tree)->val = root1->val + root2->val ;
        merge(&(*merge_tree)->left, root1->left, root2->left);
        merge(&(*merge_tree)->right, root1->right, root2->right);
    }
    else if(root1 && !root2){
        *merge_tree = root1;
    }
    else if(!root1 && root2){
        *merge_tree = root2;
    }
    
}
struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2){
    struct TreeNode* merge_tree = NULL;
    merge(&merge_tree, root1, root2);
    return merge_tree;
    
}