class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val=prices[0];
        int max_profit=0;
        for(int i=0;i<prices.size();i++){
            min_val=min(min_val,prices[i]);
            int profit = prices[i]-min_val;
            max_profit=max(profit,max_profit);
        }
        return max_profit;
    }
};