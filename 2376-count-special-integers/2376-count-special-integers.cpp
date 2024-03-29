class Solution {
public:
    
    int dp[11][2][1<<10][2];
    
    int f(int i,int tight,int mask,string &s,int lz){
        if(i == s.size()) return 1;
        
        if(dp[i][tight][mask][lz] != -1) return dp[i][tight][mask][lz];
        
        int ans = 0;
        int ub = tight ? s[i] - '0' : 9;
        
        for(int dig = 0;dig<=ub;dig++){
            
            if(lz == 1 and dig == 0) ans += f(i+1,0,mask,s,1);
            
            else if(mask & (1 << dig)) continue;
            
            else{
                mask = mask | (1 << dig);
                ans += f(i+1,(tight & (dig == ub)),mask,s,0);
                mask = mask ^ (1 << dig);
            } 
        }
        
        return dp[i][tight][mask][lz] = ans;
    }
    
    int countSpecialNumbers(int n) {
        memset(dp,-1,sizeof(dp));
        string s = to_string(n);
        return f(0,1,0,s,1)-1;
    }
};