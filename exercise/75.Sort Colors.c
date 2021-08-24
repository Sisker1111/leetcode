

void sortColors(int* nums, int numsSize){
    int count[3] = {0};
    
    for(int i=0; i < numsSize; i++)
        count[nums[i]]++;
    
    int j = 0, i = 0;
    while( j < 3 ){
        if(count[j]){
            nums[i++] = j;
            count[j]--;
        }
        else{
            j++;
        }
    }
 

}