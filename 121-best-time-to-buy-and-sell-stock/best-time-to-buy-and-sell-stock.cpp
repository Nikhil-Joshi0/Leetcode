class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = prices[0];
        for(int i = 0;i<prices.size();i++){
            if(prices[i] - mini > profit){
                profit = prices[i] - mini;
            }
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};