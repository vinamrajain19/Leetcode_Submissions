class Solution {
public:
    int f(vector<int> &nums,int i,int j,vector<int> &dp){
        if(i >= j) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int ans = 1e9;
        
        for(int  k = 1;k<=nums[i];k++){
            ans = min(ans, 1 + f(nums,i+k,j,dp));
        }
        return dp[i] = ans;
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n,-1);
        
        return f(nums,0,n-1,dp);
    }
};