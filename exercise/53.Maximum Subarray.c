int maxSubArray(int* nums, int numsSize){
    int cur, res;
    cur = res = nums[0];
    for(int i=1; i<numsSize; i++){
        if( (cur+nums[i] < 0) || (cur+nums[i] < nums[i]) )
            cur = nums[i];
        else
            cur += nums[i];
        if( cur > res)
            res = cur;
    }
   
    return res;
}