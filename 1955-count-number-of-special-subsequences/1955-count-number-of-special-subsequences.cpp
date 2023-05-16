class Solution {
public:
    
    int mod = 1e9+7;
    
    int dp[100001][5];
    
    int f(vector<int> &nums,int idx,int prev){
        if(idx == nums.size()) return prev == 2;
        
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        
        
        // not include
        if((nums[idx] < prev) or (nums[idx] != 0 and prev == -1) or (nums[idx] == 2 and prev == 0)){
            return dp[idx][prev+1] =  f(nums,idx+1,prev) % mod;
        }
        
        // include
        return dp[idx][prev+1] =  (f(nums,idx+1,prev) % mod + f(nums,idx+1,nums[idx]) % mod)%mod;
    }
    
    
    int countSpecialSubsequences(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(nums,0,-1);
    }
};