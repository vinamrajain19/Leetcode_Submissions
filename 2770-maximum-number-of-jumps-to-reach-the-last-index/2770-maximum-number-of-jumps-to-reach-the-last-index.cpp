class Solution {
public:
    int helper(vector<int>& nums, int target,int index,vector<int>&dp){
        if(index>=nums.size()-1) return 0;
        int maxi=INT_MIN;
        if(dp[index]!=-1) return dp[index];
        for(int i=index+1;i<nums.size();i++){
            if(abs(nums[index]-nums[i])<=target){
                    maxi=max(maxi,1+helper(nums,target,i,dp));
            }
        }
        return dp[index]=maxi;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        int ans=helper(nums,target,0,dp);
        return ans<=0?-1:ans;
    }
};