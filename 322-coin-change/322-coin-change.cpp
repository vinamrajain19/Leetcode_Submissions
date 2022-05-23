class Solution {
public:
    
    int coinChange(vector<int>& coins, int amt) {
        
        int n = coins.size();
        vector<int> prev(amt+1,0);
        
        for(int j = 0;j<amt + 1;j++){
            if(j%coins[0] == 0) prev[j] = j/coins[0];
            else prev[j] = 1e9;
        }
        
        for(int idx = 1;idx < n;idx++){
            vector<int> temp(amt+1,0);
            for(int tar = 0;tar <= amt ;tar++){
                int no = prev[tar];
                int take = 1e9;
                if(coins[idx] <= tar){
                    take = 1 + temp[tar-coins[idx]];
                }
                
                temp[tar] = min(no,take);
            }
            prev = temp;
        }
        int ans = prev[amt];
        if(ans >= 1e9) return -1;
        return ans;
    }
};