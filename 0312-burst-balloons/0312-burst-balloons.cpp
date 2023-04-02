class Solution {
public:
    
    int dp[305][305];
    
    int f(vector<int> &nums,int i,int j){
        if(i >= j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = -1e9;
        for(int k = i;k<j;k++){
            
            int temp = (nums[i-1] * nums[k] * nums[j]) + f(nums,i,k) + f(nums,k+1,j);
            ans = max(ans,temp);
        }
        
        return dp[i][j] =  ans;
    }
    
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        // int n = nums.size()-1;
        
        return f(nums,1,nums.size()-1);
    }
};