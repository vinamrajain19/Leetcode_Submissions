//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int mod = 1e9+7;
	int f(int arr[],int n,int sum,int idx,vector<vector<int>> &dp){
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
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(arr,n,sum,0,dp) % mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends