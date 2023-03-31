class Solution {
public:
    
    int dp[301][5002];
    
    int f(vector<int> &c,int amt,int idx){
        if(amt < 0) return 0;
        
        if(idx == c.size()-1){
            if(amt % c[idx] == 0){
                return 1;
            }
            return 0;
        }
        
        if(dp[idx][amt] != -1) return dp[idx][amt];
        
        int a = 0;
        
        if(c[idx] <= amt){
            a = f(c,amt-c[idx],idx);
        }
        
        int b = f(c,amt,idx+1);
        
        return dp[idx][amt] =  a + b;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return f(coins,amount,0);
    }
};