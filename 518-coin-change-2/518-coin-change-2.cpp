class Solution {
public:
    int change(int amt, vector<int>& coins) {
       int n = coins.size();
        vector<int> prev(amt+1,0);
        
        for(int j = 0;j<amt + 1;j++){
            if(j%coins[0] == 0) prev[j] = 1;
            else prev[j] = 0;
        }
        
        for(int idx = 1;idx < n;idx++){
            vector<int> temp(amt+1,0);
            for(int tar = 0;tar <= amt ;tar++){
                
                int no = prev[tar];
                
                int take = 0;
                
                if(coins[idx] <= tar){
                    take = temp[tar-coins[idx]];
                }
                
                temp[tar] = (no+take);
            }
            prev = temp;
        }
        int ans = prev[amt];
        return ans;
    }
};