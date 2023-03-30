class Solution {
public:
    
    int dp[201][20003];
    bool f(vector<int> &nums,int idx,int sum){
        if(sum == 0) return true;
        
        if(idx == nums.size()){
            if(sum == 0) return true;
            return false;
        }
        
        if(dp[idx][sum]  != -1) return dp[idx][sum];
        
        
        bool a = false;
        if(nums[idx] <= sum){
            a = f(nums,idx+1,sum-nums[idx]);
        }
        bool b = f(nums,idx+1,sum);
        
        return dp[idx][sum] =  a or b;
    }
    
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum % 2 == 1) return false;
        
        memset(dp,-1,sizeof(dp));
        
        return f(nums,0,sum/2);
    }
};