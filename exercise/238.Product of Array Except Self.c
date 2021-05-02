

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    int product = 1;
    int zero_count = 0;
    int* answer = (int *)calloc(numsSize,sizeof(int));
    for(int i=0; i<numsSize-1; i++){
        product *= nums[i];
        if(!nums[i]){
            zero_count++;
            if(zero_count >= 2)
                return answer;
        }
    }
    answer[numsSize-1] = product;
    for(int i=numsSize-2; i>=0; i--){
        if(nums[i]!=0)
            product = (product*nums[i+1])/nums[i];
        else{
            product = 1;
            for(int j=0; j<numsSize; j++)
                if(j!=i) product*=nums[j];
        }
        answer[i] = product;
    }
    return answer;

}