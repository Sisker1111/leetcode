

int majorityElement(int* nums, int numsSize){
    int temp = nums[0], count = 1;
    for(int i=1; i<numsSize; i++){
        if(temp == nums[i])
            count++;
        else
            count--;
        if(!count){
            temp = nums[i];
            count = 1;
        }
            
    }
    return temp;
   
}