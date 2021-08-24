int uniquePaths(int m, int n){
    if( m==1 && n==1)
        return 1;
    long maze [100][100];
    for(int k=1;k<n;k++){
        maze[0][k]=1;
    }
    for(int k=1;k<m;k++){
        maze[k][0]=1;
    }
    int i = 1,j = 1;
    while(i < m ){
        while(j < n ){
            maze[i][j] = maze[i-1][j]+maze[i][j-1];
            j++;
        }
        j = 1;
        i++;
        
    }
    return maze[m-1][n-1];
}