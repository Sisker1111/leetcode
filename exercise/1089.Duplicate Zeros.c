

void duplicateZeros(int* arr, int arrSize){
    int count = 0;
    for(int i=0; i<arrSize; i++){
        if(!arr[i])
            count++;
    }
    

    for(int i=arrSize-1; count>0 && i>=0; i--){
        
        if(i+count < arrSize){
            arr[i+count] = arr[i];
            if(!arr[i]){
                arr[i+count-1] = 0;
                count--;
            }
        }
        else{
            if(!arr[i]) count--;
            arr[i] = 0;
        }
        

    }

}