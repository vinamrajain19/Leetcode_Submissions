class Solution {
public:
    int f(vector<int> &nums,int i,int j,vector<vector<int>> &dp){
        if(i>=j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int mx = -1e9;
        for(int k = i;k<=j-1;k++){
            int temp = f(nums,i,k,dp) + f(nums,k+1,j,dp) + (nums[k] * nums[i-1] * nums[j]);
            mx = max(mx,temp);
        }
        
        return dp[i][j] = mx;
    }
    
    int maxCoins(vector<int>& nums) {
      
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(nums,1,n-1,dp);
    }
};