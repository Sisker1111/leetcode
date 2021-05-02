int missingNumber(int* nums, int numsSize){
    int i;
    int missing = numsSize;
    for (i = 0; i < numsSize; i ++) {
        missing ^= (i ^ nums[i]);
    }
    return missing;
}