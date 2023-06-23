class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 0;
        vector<vector<int>> dp(nums.size()+1,vector<int>(2001,1));
        
        for(int i = 0;i<nums.size();i++){
            for(int j= 0;j<i;j++){
                int diff = nums[i] - nums[j] + 501;
                dp[i][diff] = max(dp[i][diff],1+dp[j][diff]);
                ans = max(ans,dp[i][diff]);
            }
        }
        
        return ans;
    }
};