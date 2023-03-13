//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool f(int N,int arr[],int idx,int sum ,vector<vector<int>> &dp){
        if(idx >= N or sum < 0) return 0;
        if(sum == 0) return 1;
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        // take  it
        int x = 0;
        if(arr[idx] <= sum){
            x = f(N,arr,idx+1,sum - arr[idx],dp);
        }
        int y = f(N,arr,idx+1,sum,dp);
        
        return dp[idx][sum] = x || y;
    }
    
    
    
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i = 0;i<N;i++) sum += arr[i];
        
        vector<vector<int>> dp(N+1, vector<int> ((sum/2)+1 , -1));
        
        if(sum % 2 == 1) return 0;
        
        return f(N,arr,0,sum/2,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends