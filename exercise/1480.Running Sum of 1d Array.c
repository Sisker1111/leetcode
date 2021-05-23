/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int *res = (int *)malloc(numsSize*sizeof(int));
    *returnSize = numsSize;
    int total = 0;
    for(int i=0; i<numsSize; i++){
        total += nums[i];
        res[i] = total;
    }
    return res;
}