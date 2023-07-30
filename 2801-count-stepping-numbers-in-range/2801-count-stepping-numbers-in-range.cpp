class Solution {
public:
    
    int mod = 1e9+7;
    
    int dp[101][3][3][11];
    int f(string &s,int i,bool tight,bool zero,int ch){
        
        if(i == s.size()){
            if(zero) return 0;
            return 1;
        }
        
        
        if(dp[i][tight][zero][ch+1] != -1) return dp[i][tight][zero][ch+1];
        
        int ans = 0;
        
        int ub = tight ? s[i] - '0' : 9;
        
        for(int d = 0;d <= ub;d++){
            if(zero and d == 0){
                 ans += f(s,i+1,0,1,d);
                 ans %= mod;
            }
            else if(zero and d != 0){
                ans += f(s,i+1,tight & (ub == d),0,d);
                ans %= mod;
            }
            else{
                if(abs(d - ch) == 1){
                    ans += f(s,i+1,tight & (ub == d),0,d);
                    ans %= mod;
                }
                
            }
        }
        
        return dp[i][tight][zero][ch+1] = ans % mod;
        
    }
    
    int countSteppingNumbers(string low, string high) {
        
        bool fl = true;
        
        for(int i = 1;i<low.size();i++){
            if(abs(low[i-1] - low[i]) != 1) fl = false;   
        }
        
        memset(dp,-1,sizeof(dp));
        int a = f(high,0,1,1,-1);
         memset(dp,-1,sizeof(dp));
        int b = f(low,0,1,1,-1);
        
        if(fl) a++;
        
        return (a-b + mod) % mod;
    }
};