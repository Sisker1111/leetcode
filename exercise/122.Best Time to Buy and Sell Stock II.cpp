class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profit;
        int i,j=0;
        int sum=0;
        for(i=1;i<prices.size();i++){
            profit.push_back(prices[i]-prices[i-1]);
            if(profit[j]>0)
                sum+=profit[j];
            j++;
        }
        
        
        return sum;
    }
};