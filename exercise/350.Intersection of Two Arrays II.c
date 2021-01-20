

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp ( const void *a , const void *b ) 
{ 
    if( *(int *)a > *(int *)b)
        return 1;
    return 0;
    // return *(int *)a - *(int *)b; 
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    
    int *tmp;
    if(nums1Size >= nums2Size)
        tmp = (int *)malloc(nums1Size*sizeof(int));
    else
        tmp = (int *)malloc(nums2Size*sizeof(int));
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int num1_idx = 0, num2_idx = 0, output_size = 0;
    while( num1_idx < nums1Size && num2_idx < nums2Size){
        if(nums1[num1_idx] < nums2[num2_idx])
            num1_idx++;
        else if(nums1[num1_idx] > nums2[num2_idx])
            num2_idx++;
        else{
            tmp[output_size++] = nums1[num1_idx];
            num1_idx++;
            num2_idx++;
        }
    }
    int *output = (int *)malloc(output_size*sizeof(int));
    for(int i=0; i<output_size; i++){
        output[i] = tmp[i];
    }
    *returnSize = output_size;
    free(tmp);
    return output;

}