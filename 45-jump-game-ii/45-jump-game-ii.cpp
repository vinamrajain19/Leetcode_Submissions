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
        
        vector<int> dp(n,1e9);
        dp[n-1] = 0;
        
        for(int i = n-2;i>=0;i--){
            
            int ans = 1e9;
            
            for(int  k = 1;k<=nums[i];k++){
                
                if(i + k >= n) break;
                ans = min(ans, 1 + dp[i+k]);
                
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};