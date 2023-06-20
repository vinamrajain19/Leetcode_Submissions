class Solution {
public:
//     int dp[31][3002];
//     int f(vector<int> &stones,int i,int diff){
        
//         if(i == stones.size()) return abs(diff);
        
//         if(dp[i][abs(diff)] != -1) return dp[i][abs(diff)];
        
//         int x = f(stones,i+1,diff+stones[i]);
//         int y = f(stones,i+1,diff-stones[i]);
        
//         return dp[i][abs(diff)] = min(x,y);
        
//     }
    
    
     int f(vector<int> &nums,int idx,int tot,int sum,vector<vector<int>> &dp){
        if(idx == nums.size()){
            return abs(tot - 2 *(sum));
        }
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        int ans = 1e9;
        
        ans = min(ans,f(nums,idx+1,tot,sum+nums[idx],dp));
        ans = min(ans,f(nums,idx+1,tot,sum,dp));
        
        return dp[idx][sum] =ans;
    }
    
    int f2(vector<int>& nums) {
        
        int tot = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int>(tot+1,-1));
        return f(nums,0,tot,0,dp);
    }
    
    int lastStoneWeightII(vector<int>& stones) {
       // memset(dp,-1,sizeof(dp));
        
        return f2(stones);
    }
};