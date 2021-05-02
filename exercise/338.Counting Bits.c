

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize){
    // *returnSize = num + 1;
    // int *output = (int *)malloc((num+1)*sizeof(int));
    // for(int i=0; i<=num; i++){
    //    output[i]= __builtin_popcount(i);
    // }
    // return output;
    
    *returnSize = num + 1;
    int *output = (int *)malloc((num+1)*sizeof(int));
    output[0] = 0;
    if(num == 0)
        return output;
    output[1] = 1;
    int k = 2, i = 2;
    while(i <= num){
        int count = pow(2, k-2);
        for(int j = pow(2, k-1); j < pow(2, k); j++ ){
            output[j] = (j <= (pow(2, k-1)+pow(2, k)-1)/2) ? output[count] : output[count]+1;
            count++;
            i++;
            if( i > num )break;   
        }
        k++;
    }
    return output;
    
}