class Solution {
public:
    
    int dp[10001];
    int f(vector<int> &nums,int idx){
        if(idx >= nums.size()-1) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int ans = 1e9;
        for(int i = 1;i<=nums[idx];i++){
            
            int t = 1 + f(nums,idx+i);
            ans = min(ans,t);
        }
        
        return dp[idx] = ans;
    }
    
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(nums,0);
    }
};