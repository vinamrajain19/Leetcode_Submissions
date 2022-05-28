class Solution {
public:
    int f(vector<int> &nums,int i,int prev,vector<vector<int>> &dp){
        if(i == nums.size()) return 0;
        
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        int no = f(nums,i+1,prev,dp);
        
        int take = 0;
        if(prev == -1 or nums[i] > nums[prev]){
            take = 1 + f(nums,i+1,i,dp);
        }
        
        return dp[i][prev+1] =  max(no,take);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size() + 1,-1));
        return f(nums,0,-1,dp);
    }
};