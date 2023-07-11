class Solution {
public:
    
    // int dp[22][2010];
    vector<vector<int>> dp;
    
    int helper(vector<int>& nums,int target,int n,int index,int sum){
        if(index==n){
            if(sum==target){
                return 1;
            }
            return 0;
        }
        if(dp[index][sum+1000]!=-1){
            return dp[index][sum+1000];
        }
        return dp[index][sum+1000]= helper(nums,target,n,index+1,sum+nums[index]) + helper(nums,target,n,index+1,sum);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if((sum-target)%2!=0){
            return 0;
        }
        int newTarget = (sum-target)/2;
        dp.resize(22,vector<int>(2010,-1));
        return helper(nums,newTarget,n,0,0);
    }
};