

int maxProfit(int* prices, int pricesSize){
    
    if(pricesSize < 2)
        return 0;
    int min = prices[0] ; 
    int max_Profit = 0;
    for(int i=1; i<pricesSize; i++){
        if( prices[i] > min ){
            max_Profit = ( prices[i]-min >= max_Profit) ? prices[i]-min : max_Profit;
        }
        else
            min = prices[i];
    }
    return max_Profit;
}

