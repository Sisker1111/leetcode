

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **output, *map, *solution;
int *used, count = 0;
const int size = 4290;
void backtracking(int n, int numsSize,int count_left, int count_right){
    
    if(n==numsSize){
        for(int i=0;i<n;i++){
            output[count][i]=solution[i];
        }
        count++;
        return;
    }
    char tmp_left='\0',tmp_right='\0';
    for(int i=0;i<numsSize;i++){
        if(!used[i] && map[i] == '(' && map[i]!=tmp_left){
            used[i]=1;
            solution[n]=map[i];
            backtracking(n+1,numsSize,count_left+1,count_right);
            tmp_left = '(';
            used[i]=0;
        }
        else if (!used[i] && map[i] == ')' && (count_left > count_right) && map[i]!=tmp_right){
            used[i]=1;
            solution[n]=map[i];
            backtracking(n+1,numsSize,count_left,count_right+1);
            tmp_right = ')';
            used[i]=0;
        }
    }
    
}
void initial(int n){
    output = (char **) malloc( size * sizeof(char *) );
    for(int i=0; i<size; i++){
        output[i] = (char*)malloc( (n*2 + 1) *sizeof(char) );
        memset(output[i],0,(n*2 + 1)*sizeof(char));
    }
    used = (int*)malloc(n*2*sizeof(int));
    solution = (char*)malloc((n*2 + 1)*sizeof(char));
    map = (char*)malloc(n*2*sizeof(char));
    for(int i=0; i<n*2; i++)
        map[i] = (i<n) ? '(' : ')';
    memset(solution,0,(n*2 + 1)*sizeof(char));
    memset(used,0,n*2*sizeof(int));
}
char ** generateParenthesis(int n, int* returnSize){
    initial(n);
    backtracking(0,n*2,0,0);
    *returnSize = count;
    count=0;
    return output;
}