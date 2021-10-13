void DFS(char** grid, int index_i, int index_j, int gridSize, int gridColSize){
    
    if(index_i < 0 || index_j < 0 || index_i >= gridSize || index_j >= gridColSize || grid[index_i][index_j] == '0')
        return;
    
    grid[index_i][index_j] = '0';
    DFS(grid, index_i - 1, index_j, gridSize, gridColSize);
    DFS(grid, index_i + 1, index_j, gridSize, gridColSize);
    DFS(grid, index_i, index_j - 1, gridSize, gridColSize);
    DFS(grid, index_i, index_j + 1, gridSize, gridColSize);
    
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    
    int count = 0;
    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < *gridColSize; j++){
            if(grid[i][j] == '1'){
                DFS(grid, i, j, gridSize, *gridColSize);
                count++;
            }
        }
    }  
    return count;
}