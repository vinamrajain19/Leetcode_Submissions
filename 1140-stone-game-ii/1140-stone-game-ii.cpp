class Solution {
public:
    int dp[101][2][101];
    
    // T.C = O(n^3)
    
    // f -> denotes no of stones alice can get
    
     int f(vector<int> &s,int i,int alice,int m){
        if(i >= s.size()) return 0;
        
        if(dp[i][alice][m] != -1) return dp[i][alice][m];
        
        int ans = alice == 1 ? 0 : 1e9;
        int sum = 0;
     
        for(int j = 1;j <= 2*m;j++){
                
            int ind = i + j- 1;
            if(ind >= s.size()) break;
            sum += s[ind];
            
            if(alice) ans = max(ans,sum + f(s,ind+1,0,max(j,m)));   // maximise what alice gets
            else ans = min(ans,f(s,ind+1,1,max(j,m)));              // minimise what alice gets
        }

        
        return dp[i][alice][m] = ans;
    }
    
    int stoneGameII(vector<int>& s) {
        memset(dp,-1,sizeof(dp));
        return f(s,0,1,1);
    }
};