class Solution {
public:
    int dp[1001];
  int helper(vector<int>&nums,int target,int n,int sum)
  {    if(sum>target) return 0 ;
       if(sum==target){
        return 1 ;
       }
   if(dp[sum]!=-1){
       return dp[sum];
   }
      int ans=0;
       for(int i=0;i<n;i++)
       {  if(sum+nums[i]<=target)
           ans+=helper(nums,target,n,sum+nums[i]);
       }
      return dp[sum]=ans;
  }
    int combinationSum4(vector<int>& nums, int target) {
       memset(dp,-1,sizeof(dp));
        int n=nums.size();
      return  helper(nums,target,n,0);
     
    }
};