

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *count = (int *)calloc(TSize,sizeof(int));
    int *large = (int *)calloc(TSize,sizeof(int));
    *returnSize = TSize;
    for(int i = TSize - 1; i > 0; i--){
        if(T[i] > T[i-1]){
            large[i-1] = i;
            count[i-1] = 1;
        }
        else{
            int k = large[i];
            while(k!=0){
                if(T[k] > T[i-1]){
                    large[i-1] = k;
                    count[i-1] = k-i+1;
                    break;
                }
                k = large[k];
            }
        }
    }
    return count;

}