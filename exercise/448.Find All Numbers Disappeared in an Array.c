

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    int* result = calloc(numsSize+1, sizeof(int));
    for(int i=0; i<numsSize; i++){
        result[nums[i]]++;
    }
    
    for(int i=1; i<numsSize+1; i++){
        if( result[i] == 0 ){
            result[*returnSize] = i;
            (*returnSize)++;
        }
    }
    
    return result;
}