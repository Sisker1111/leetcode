/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode *create_node(int x){
    struct TreeNode* node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = x;
    node->left = NULL;
    node->right =NULL;
    return node;
}
void binary_tree(struct TreeNode* root, int *trace, int* preorder, int start, int* inorder, int end, int num){
    int index = 0;
    for(int i=start; i<end; i++){
        if(preorder[*trace] == inorder[i]){
            index = i;
            break;
        }
    }
    for(int i=start; i<index; i++){
        if( (*trace)+1 >= num)
            return;
        if( inorder[i] == preorder[(*trace)+1]){
            root->left = create_node(preorder[++(*trace)]);
            binary_tree(root->left, trace, preorder, start, inorder, index, num);
            
        }
    }
    for(int i=index+1; i<end; i++){
        if( (*trace)+1 < num){
            if( inorder[i] == preorder[(*trace)+1]){
                root->right = create_node(preorder[++(*trace)]);
                binary_tree(root->right, trace, preorder, index+1, inorder, end, num);
                break;
            }
        }
    
    }
    
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if(!preorderSize && !inorderSize)
        return NULL;
    struct TreeNode *root = create_node(preorder[0]);
    int num = preorderSize;
    int trace = 0;
    binary_tree(root, &trace, preorder, 0, inorder, inorderSize, num);
    return root;

}