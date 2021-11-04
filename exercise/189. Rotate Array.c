void reverse(int *nums, int start, int end){
    while(start < end){
        nums[start] ^=  nums[end];
        nums[end] ^= nums[start];
        nums[start++] = nums[start] ^ nums[end--];
    }
}
void rotate(int* nums, int numsSize, int k){
    k %= numsSize;
    if(k > 0){
        reverse(nums, 0, numsSize-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, numsSize-1);
    }
}