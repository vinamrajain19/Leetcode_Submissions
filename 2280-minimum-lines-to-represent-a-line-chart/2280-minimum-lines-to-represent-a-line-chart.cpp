class Solution {
public:

    int minimumLines(vector<vector<int>>& stockPrices) {
      sort(stockPrices.begin(), stockPrices.end()); 
        int ans = 0; 
        for (int i = 1; i < stockPrices.size(); ++i) 
            if (i == 1 || (long) (stockPrices[i][1] - stockPrices[i-1][1]) * (stockPrices[i-1][0] - stockPrices[i-2][0]) != (long) (stockPrices[i-1][1] - stockPrices[i-2][1]) * (stockPrices[i][0] - stockPrices[i-1][0]))
                ++ans; 
        return ans;
    }
};