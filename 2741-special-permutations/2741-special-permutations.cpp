class Solution {
public:
    int mod = 1e9+7;
    
    int dp[15][(1<<14) +1];

    int f(vector<int>& nums, int prev, int i, int mask) {
        if (i == nums.size()) {
            return 1;
        }
        
        if (dp[prev + 1][mask] != -1) {
            return dp[prev + 1][mask];
        }
        
        int ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (mask & (1 << j)) {
                continue;
            }
            if (prev == -1 or nums[prev] % nums[j] == 0 or nums[j] % nums[prev] == 0) {
                mask |= (1<<j);
                ans += f(nums, j, i + 1, mask);
                ans %= mod;
                mask ^= (1<<j);
            }
        }
        
        return dp[prev + 1][mask] = ans;
    }

    
    int specialPerm(vector<int>& nums) {
         memset(dp,-1,sizeof(dp));
         return f(nums,-1,0,0);
    }
};