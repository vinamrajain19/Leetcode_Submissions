class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<int> c(nums.size(),1);
        int mx = -1e9;
        
        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<i;j++){
                if(nums[i] > nums[j] and dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    c[i] = c[j];
                }
                else if(nums[i] > nums[j] and dp[i] == 1 + dp[j]){
                    c[i] += c[j];
                }
            }
            
            mx = max(mx,dp[i]);
        }
        
        int ans = 0;
        
        
        for(int i = 0;i<nums.size();i++){
            if(dp[i] == mx){
                ans += c[i];
            }
        }
        
        return ans;
        
    }
};