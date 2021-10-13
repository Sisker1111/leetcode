

int numberOfArithmeticSlices(int* nums, int numsSize){
    
    int *dp = (int *)calloc(numsSize,sizeof(int));
    int total = 0;
    if(numsSize < 3)
        return 0;
    for(int i=2; i<numsSize; i++){
        if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2])
            dp[i] = dp[i-1] + 1;
        total += dp[i];
    }
    return  total;
}