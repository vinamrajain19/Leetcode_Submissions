//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
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
    
    int minimumDifference(vector<int>& nums) {
        
        int tot = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int>(tot+1,-1));
        return f(nums,0,tot,0,dp);
    }
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    vector<int> nums;
	    for(int i = 0;i<n;i++) nums.push_back(arr[i]);
	    
	    return minimumDifference(nums);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends