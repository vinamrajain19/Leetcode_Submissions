//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dp[101][101];
    int f(int arr[],int i,int j){
        if(i == j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        
        for(int k = i;k<j;k++){
            int temp = f(arr,i,k) +f(arr,k+1,j)+(arr[i-1] * arr[k] * arr[j]);
            ans = min(ans,temp);
        }
        
        return dp[i][j] = ans;
        
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return f(arr,1,N-1);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends