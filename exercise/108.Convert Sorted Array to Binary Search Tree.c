/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* crearte_node(int num){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node -> val = num; 
    node -> left = NULL; 
    node -> right = NULL; 
    return node;
}
struct TreeNode* binary_search(int* nums, int begin, int end){
    if(begin > end)
        return NULL;
    int mid = (begin + end)/2;    
    struct TreeNode* node = crearte_node(nums[mid]);
    node->left = binary_search(nums,begin,mid-1);
    node->right = binary_search(nums,mid+1,end);
    return node; 
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    
    return binary_search(nums,0,numsSize-1);
}