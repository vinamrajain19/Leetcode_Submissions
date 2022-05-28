class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<int> after(2*k+1,0);
        vector<int> curr (2*k+1,0);
        
        
        for(int idx = n-1;idx>=0;idx--){
            
            for(int t = 2*k - 1;t>=0;t--){
                
                    
                if(t % 2 == 0){
                     curr[t] = max(-p[idx] + after[t+1], after[t]);
                }
        
        //sell -> sell it or not sell -> sell -> positive -> add in profit
                else{
                    curr[t] = max(p[idx] + after[t+1],after[t]);
                }
            }
            after = curr;
        }
        
        return after[0];
    }
};