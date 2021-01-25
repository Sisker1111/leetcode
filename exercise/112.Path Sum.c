
int is_leaf(struct TreeNode* node){
    if( !node->left && !node->right)
        return 1;
    return 0; 
}
void DFS(struct TreeNode* current, int targetSum, int *sum, int *result){
    if(*result || !current)
        return NULL;
    *sum += current->val;
    if( is_leaf(current) ){
        if( *sum == targetSum )
            *result = 1;
    }
    else{
        DFS(current->left, targetSum, sum, result);
        DFS(current->right, targetSum, sum, result);
    }
    *sum -= current->val;
}
bool hasPathSum(struct TreeNode* root, int targetSum){
    int sum = 0, result = 0;
    DFS(root, targetSum, &sum, &result);
    return result; 
}