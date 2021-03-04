bool isHappy(int n){
    int temp = n;
    int record=0;
    while(temp != 1){
        char *str = (char *)malloc(11*sizeof(char));
        sprintf(str, "%d\0", temp);
        int i = 0;
        int total = 0;
        while( str[i] != '\0'){
            total += (str[i] - 48) * (str[i] - 48);
            i++;
        }
        temp = total;
        if(record == temp)
            return false;
        if(temp < 10)
            record = temp;
    }
    
    
    if(temp == 1)
       return true;
    return false;
}