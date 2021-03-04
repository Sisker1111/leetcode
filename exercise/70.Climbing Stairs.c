

int climbStairs(int n){
    int i=3;
    long solution[46];
    solution[1]=1;
    solution[2]=2;
    while(i<=n){
        solution[i] =  solution[i-1] + solution[i-2];
        i++;
    }
        
    return solution[n];
}

