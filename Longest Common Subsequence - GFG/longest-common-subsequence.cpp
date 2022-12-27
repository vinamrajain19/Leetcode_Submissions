//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int dp[1001][1001];
    int f(string s1,string s2,int i1,int i2){
        
        if(i1 == 0 or i2 == 0) return 0;
        
        if(dp[i1][i2] != -1) return dp[i1][i2];
        
        if(s1[i1-1] == s2[i2-1]){
            return dp[i1][i2] =  1 + f(s1,s2,i1-1,i2-1);
        }
        return dp[i1][i2] =  max(f(s1,s2,i1-1,i2),f(s1,s2,i1,i2-1));
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        memset(dp,-1,sizeof(dp));
        return f(s1,s2,x,y);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends