void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int temp ; 
    if(matrixSize==0)
        return;

    for(int i=0; i<matrixSize; i++){
        for(int j=i; j<matrixSize; j++)
        {
            temp = matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }

    for(int i=0; i<matrixSize; i++){
        for(int j=0; j<matrixSize/2;j++){
            temp = matrix[i][j];
            matrix[i][j]=matrix[i][matrixSize-1-j];
            matrix[i][matrixSize-1-j]=temp;
        }

    }

}