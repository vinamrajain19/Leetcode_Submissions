class Solution {
public:
    
    int mod = 1e9+7;
    
    int f(vector<int> &arr,int n,int sum,int idx,vector<vector<int>> &dp){
	   // if(sum == 0) return 1;
	   
	    if(idx == n-1){
	        if(sum == 0 and arr[idx] == 0) return 2;
	        if(sum == 0 or arr[idx]== sum) return 1;
	        return 0;
	    }
	    
	    if(dp[idx][sum] != -1) return dp[idx][sum];
	    
	    int a = 0;
	    if(arr[idx] <= sum){
	        a = f(arr,n,sum-arr[idx],idx+1,dp) % mod;
	    }
	    int b = f(arr,n,sum,idx+1,dp) % mod;
	    
	    return dp[idx][sum] =  (a + b) % mod;
	}
    
    
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum = accumulate(arr.begin(),arr.end(),0);
        
        int x = (sum - d)/2;
        
        if((sum-d) < 0) return 0;
        
        if((sum-d) % 2 == 1) return 0;
        
        vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
        
        return f(arr, n,x,0,dp) % mod;
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),target,nums);
    }
};