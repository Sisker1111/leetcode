/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode ** array;
void trace(struct TreeNode* root, int * count){
    if(!root)
        return;
    (*count)++;
    trace(root->left,count);
    trace(root->right,count);
    
}
void Inorder(struct TreeNode* current, int * count){
    if(!current)
        return;
    Inorder(current->left,count);
    array[(*count)++] = current;
    Inorder(current->right,count);
    
}
struct TreeNode* increasingBST(struct TreeNode* root){
    struct TreeNode* cursor, *new_tree;
    int count = 0;
    trace(root,&count);
    array = (struct TreeNode**)malloc(count * sizeof(struct TreeNode *));
    count = 0;
    Inorder(root,&count);
    cursor = new_tree = array[0];
    for(int i=0; i<count-1; i++){
        cursor -> right = array[i+1];
        cursor -> left = NULL;
        cursor = cursor->right;
    }
    cursor -> right = NULL;
    cursor -> left = NULL;
    return new_tree;
}