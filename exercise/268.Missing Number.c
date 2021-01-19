

int missingNumber(int* nums, int numsSize){
   
    int total = (1+numsSize)*numsSize/2;
    int tmp=0;
    for(int i=0 ;i<numsSize; i++){
        tmp+=nums[i];
    }
    return total - tmp;
}