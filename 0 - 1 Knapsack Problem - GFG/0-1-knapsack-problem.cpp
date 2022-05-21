// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int help(int W,int wt[],int val[],int n,int idx,vector<vector<int>> &dp){
        if(W == 0) return 0;
        
        if(idx == 0){
            if(wt[0] <= W){
                return dp[idx][W] = val[0];
            }
            return 0;
        }
        
        if(dp[idx][W] != -1) return dp[idx][W];
        
        if(wt[idx] <= W){
            return max(val[idx] + help(W-wt[idx],wt,val,n,idx-1,dp) , help(W,wt,val,n,idx-1,dp));
        }
        return dp[idx][W] = help(W,wt,val,n,idx-1,dp);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return help(W,wt,val,n,n-1,dp);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends