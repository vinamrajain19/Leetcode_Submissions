class Solution {
public:
    int dp[1001][1001][2];
    int f(int idx,int prev,int x,vector<int> &nums){
        if(idx == nums.size()) return 0;
        
        if(dp[idx][prev][x] != -1) return dp[idx][prev][x];
        
        int take = -1e9;
        int no = -1e9;
        
        if(x){
            no = f(idx+1,prev,x,nums);
            if(nums[idx] > prev){
                take = 1 + f(idx+1,nums[idx],0,nums);
            }
        }
        
        if(!x){
            no = f(idx+1,prev,x,nums);
            if(nums[idx] < prev){
                take = 1 + f(idx+1,nums[idx],1,nums);
            }
        }
        
        return dp[idx][prev][x] =  max(no,take);
    }
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return 1 + max(f(1,nums[0],1,nums) , f(1,nums[0],0,nums));
    }
};