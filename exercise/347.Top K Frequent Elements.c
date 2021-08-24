
struct Frequent{
    int nums;
    int frequent;
};
int comp_s(const void* s1, const void* s2){
      struct Frequent *e1 = (struct Frequent *)s1;
      struct Frequent *e2 = (struct Frequent *)s2;
      return e1->frequent - e2->frequent;
}
int comp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    
    struct Frequent *Top = (struct Frequent *)malloc(numsSize*sizeof(struct Frequent));
    int* answer = (int *)malloc(numsSize*sizeof(int));
    if( numsSize == 0 ){
        *returnSize = 0;
        return answer;
    }
    qsort(nums,numsSize,sizeof(int),comp);
    *returnSize = 0;
    Top[(*returnSize)++].nums = nums[0];
    int temp = nums[0] , frequent = 1;
    
    for(int i=1; i<numsSize; i++){
        if( temp != nums[i] ){
            Top[(*returnSize)].nums = nums[i];
            Top[(*returnSize)-1].frequent = frequent;
            (*returnSize)++;
            frequent = 1;
            temp = nums[i];
        }
        else{
            frequent++;
        }
        if( i == numsSize-1 ){
            Top[(*returnSize)-1].frequent = frequent;
        }
    }
    
    qsort(Top,(*returnSize),sizeof(struct Frequent),comp_s);
    temp = 0, frequent = k;
    for(int i=(*returnSize)-1; i>=0; i--){
        if( (frequent--) == 0 ) break;
        answer[temp++] = Top[i].nums;
    }
    (*returnSize) = k;
    return answer;
     
}