class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 1) return false;
        
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        if(sum%2!=0){
            return false;
        }
        
        sum=sum/2;
        
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        
        if(nums[0] <= sum)
            dp[0][nums[0]] = true;
        
       
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j){
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=nottake||take;
            }
        }


        
        return dp[n-1][sum];

        
        
    }
};