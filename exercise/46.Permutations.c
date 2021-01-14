
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int count=0;
int *solution;
int *used;
int **answer;
void backtracking(int n,int numsSize,int *nums){
    if(n==numsSize){
        for(int i=0;i<n;i++){
            answer[count][i]=solution[i];
        }
        count++;
        return;
    }
    for(int i=0;i<numsSize;i++){
        if(!used[i]){
            used[i]=1;
            solution[n]=nums[i];
            backtracking(n+1,numsSize,nums);
            used[i]=0;
        }
        
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int row_number=1;
    int *columns_sizes;
    for(int i=2;i<=numsSize;i++){
        row_number*=i;
    }
    
    solution = (int*)malloc(numsSize*sizeof(int));
    used = (int*)malloc(numsSize*sizeof(int));
    columns_sizes = (int*)malloc(row_number*sizeof(int));
    answer = (int**)malloc(row_number*sizeof(int*));
    memset(used,0,numsSize*sizeof(int));
    
	for (int i = 0; i < row_number; i++){
        columns_sizes[i] = numsSize; 
        answer[i] = (int*)malloc(numsSize*sizeof(int)); 
    }
    backtracking(0,numsSize,nums);
    
  
    *returnSize = row_number;
    *returnColumnSizes = columns_sizes;
    count=0;
    return answer;
	
}
