/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode** output;
int count ;
struct TreeNode* create_node(){
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
    
}

struct TreeNode** full_tree(int n, int size){
    
    if(n==1){
        struct TreeNode *cur = create_node();
        // struct TreeNode ** tmp = &cur;
        struct TreeNode ** tmp = (struct TreeNode**)malloc(2 * sizeof(struct TreeNode*));
        tmp[0] = cur;
        tmp[1] = NULL;
        // printf("q %d\n",(*tmp)->val);
        return tmp;
    }
    
    struct TreeNode** root = (struct TreeNode**)calloc(5000, sizeof(struct TreeNode*)); // initaily NULL
    int add = 0;
    
    
    for(int i=1; i<n-1 ; i++){
        if( i%2 == 0 )
            continue;
        struct TreeNode** left = full_tree(i,size);
        struct TreeNode** right = full_tree(n-1-i,size);
        // printf("t %d\n",(*left)->val);
        while( *left ){
            struct TreeNode** cursor = right;
            while( *cursor ){
                struct TreeNode* cur = create_node();
                cur->left = *left;
                cur->right = *cursor;
                cursor++;
                root[add++] = cur;
            }
            left++;
        }
    }
    
    if( n == size ){ 
        while( *root ){
            output[count++] = *root;
            root++;
        }
    }
    
    return root;
    
    
}
struct TreeNode** allPossibleFBT(int N, int* returnSize){
    
    count = 0;
    output = (struct TreeNode**)malloc(5000 * sizeof(struct TreeNode*));
    for(int i=0; i<5000; i++)
        output[i]=NULL;
    if(!(N % 2)){
        *returnSize = 0;
        return output;
    }
    
    if(N == 1){
        struct TreeNode *root = create_node();
        output[count++] = root;
        goto jump;
    }
    
    full_tree(N,N);
    jump:
    *returnSize = count;
    return output;
    
}