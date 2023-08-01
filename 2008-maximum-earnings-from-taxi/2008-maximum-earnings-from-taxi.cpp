class Solution {
public:

    long long dp[(int)1e5];
    
    int bs(vector<vector<int>> &e,int i){
        int s = i+1;
        int ed = e.size()-1;
        
        int ans = -1;
        
        while(s <= ed){
            int m = (s+ed)/2;
            if(e[m][0] >= e[i][1]){
                ed = m-1;
                ans = m;
            }
            else s =  m +1;
        }
        
        return ans;
    }
    
    long long  f(vector<vector<int>> &e,int idx){
        
        if(idx >= e.size()) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int j = bs(e,idx);
        
        long long no = f(e,idx+1);
        long long t = e[idx][2] + e[idx][1] - e[idx][0] + f(e,j);
        
        return dp[idx] = max(no,t);
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& e) {
        sort(e.begin(),e.end());
        memset(dp,-1,sizeof(dp));
        return f(e,0);
    }
};