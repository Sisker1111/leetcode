/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct Queue{
    struct TreeNode *node;
    int level;
};

int heightoftree(struct TreeNode *root){
    if (!root)
        return 0;
    int leftsubtree = heightoftree(root->left);
    int rightsubtree = heightoftree(root->right);
    return ( leftsubtree > rightsubtree) ? leftsubtree + 1 : rightsubtree + 1;
}


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    
    int height = heightoftree(root);
    *returnSize = height;
    returnColumnSizes[0] = (int *)malloc(height*sizeof(int));  
    int *count = (int *)calloc(height,sizeof(int));
    int **output = (int **)malloc(height*sizeof(int *));
    for(int i=0; i<height; i++){
        output[i] = (int *)malloc(200*sizeof(int));
    }
    if( !root ){
        return output;
    }
    struct Queue *queue =  (struct Queue *)malloc(1500*sizeof(struct Queue));
    int idx = 0, cnt = 1;
    queue[0].node = root;
    queue[0].level = 0;
    while( idx != cnt ){
        struct TreeNode* node = queue[idx].node;
        output[queue[idx].level][count[queue[idx].level]++] = node->val;
        if( node->left != NULL ){
            queue[cnt].level = queue[idx].level+1;
            queue[cnt++].node = node->left;
        }
        if( node->right != NULL ){
            queue[cnt].level = queue[idx].level+1;
            queue[cnt++].node = node->right;
        }
        idx++;
    }
    for(int i=0; i<height; i++){
        returnColumnSizes[0][i] = count[i];
    }
    return output;

}