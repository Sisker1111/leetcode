
#define MAX(a,b) (((a)>(b))?(a):(b))

void dp(int *money, int *nums, int dp_site){
    
    if(dp_site == 1){
        money[1] = (nums[0] > nums[1]) ? nums[0] : nums[1];
        return;
    }  
    if(money[dp_site-2] == -1)
        dp(money, nums, dp_site-2);
    if(money[dp_site-1] == -1)
        dp(money, nums, dp_site-1);
    money[dp_site] = MAX( money[dp_site-2] + nums[dp_site], money[dp_site-1] );

}
int rob(int* nums, int numsSize){
    
    int *money = (int *)malloc(numsSize*sizeof(int));
    for(int i=1; i<numsSize; i++)
        money[i] = -1;  
    money[0] = nums[0];
    if( numsSize > 1 )
        dp(money, nums, numsSize-1);
    return money[numsSize-1];

}