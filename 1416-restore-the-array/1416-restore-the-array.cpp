class Solution {
    public:
    
    
    int dfs(int i, int n, string &s, int k, vector<int> &dp, int mod) {
        if(i == n) return 1;
        
        if(dp[i] != -1) return dp[i];
        
        int cnt = 0;
        
        for(int j=i; j<n; j++) {
            long long num = stoll(s.substr(i, j - i + 1));
            if(!num || num > k) break;
            cnt = (cnt + dfs(j + 1, n, s, k, dp, mod)) % mod;
        }
        
        return dp[i] = cnt;
    }

    int numberOfArrays(string s, int k) {
        int n = s.size(), mod = 1e9 + 7;;
        vector<int> dp(n, -1);
        return dfs(0, n, s, k, dp, mod);
    }
};