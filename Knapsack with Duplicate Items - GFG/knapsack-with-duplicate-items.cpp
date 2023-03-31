//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

   int dp[1001][1001];

    int f(int N,int W,int val[],int wt[],int idx){
       if(W < 0) return -1e9;
       
       //if(W == 0) return 0;
       
       if(idx >= N){
           //if(W >= wt[idx]) return (val[idx] * (W/wt[idx]));
           return 0;
       }
       
       if(dp[idx][W] !=  -1) return dp[idx][W];
       
       int ans = -1e9;
       
       if(W >= wt[idx]){
           ans = max(ans,val[idx] + f(N,W-wt[idx],val,wt,idx));
       }
       
       ans = max(ans,f(N,W,val,wt,idx+1));
       
       return dp[idx][W] =  ans;
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        int ans = f(N,W,val,wt,0);
        
        //if(ans <= -1e9) return 0;
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends