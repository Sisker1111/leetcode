

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int i=1;
    int subset_num = pow(2,numsSize);
    *returnSize = subset_num;
    
    int **output  = (int **)malloc(subset_num*sizeof(int *));
    *returnColumnSizes = (int*)malloc((*returnSize)*sizeof(int));
    for (int i = 0; i < subset_num; i++){
        output[i] = (int*)malloc(numsSize*sizeof(int)); 
    }
    int idx;
    for(int i=0; i<subset_num; i++){
        idx=0;
        for(int j=0; j< numsSize; j++){
            if( 1u<<j & i ){
                output[i][idx++] = nums[numsSize-1-j];
            }
        }
        // (*returnColumnSizes)[i] = idx; 和下面是一樣的
        *(returnColumnSizes[0]+i) = idx;
    }
    
    return output;
}