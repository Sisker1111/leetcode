void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int **tmp ;
    tmp = (int **)malloc(matrixSize*(sizeof(int *)));
    for(int i=0;i<matrixSize;i++){
        tmp[i] = (int *)malloc(matrixSize*(sizeof(int)));
    }
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixSize;j++){
            tmp[j][matrixSize-i-1] = matrix[i][j]; 
        }
    }
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixSize;j++){
           matrix[i][j] = tmp[i][j];
        }
    }
    for(int i=0;i<matrixSize;i++){
        free(tmp[i]);
    }
    free(tmp);
    
}