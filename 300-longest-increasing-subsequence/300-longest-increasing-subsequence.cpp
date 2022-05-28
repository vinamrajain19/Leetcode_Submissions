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
        vector<vector<int>> dp(nums.size() + 1,vector<int>(nums.size() + 1,0));
        
        for(int ind = nums.size()-1;ind>=0;ind--){
            for(int prev = ind-1;prev >= -1;prev--){
                
                int no = dp[ind+1][prev+1];
        
                int take = 0;
                if(prev == -1 or nums[ind] > nums[prev]){
                    take = 1 +dp[ind+1][ind+1];
                }
        
                dp[ind][prev+1] = max(no,take);
            }
        }
        return dp[0][-1+1];
    }
};