class Solution {
public:
    
    int mod = 1e9+7;
    int dp[101][201];
    
    int f(vector<int> &l,int finish,int fuel,int idx){
        
        if(idx >= l.size()) return 0;
        
        if(dp[idx][fuel] != -1) return dp[idx][fuel];
        
        int c = 0;
        
        if(idx == finish) c = 1;
        
        
        for(int i=0;i<l.size();i++){
            if(i != idx){
                if(fuel >= abs(l[idx] - l[i])){
                    c = (c+f(l,finish,fuel-abs(l[idx]-l[i]),i)%mod) % mod;
                }
            }
        }
        
        return dp[idx][fuel] =  c % mod;;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        return f(locations,finish,fuel,start);
    }
};