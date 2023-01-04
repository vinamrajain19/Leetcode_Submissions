//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    
    int dp[1001][1001];
     bool allstars(string s,int j){
        for(int k = 1;k<=j;k++){
            if(s[k-1] != '*') return false;
        }
        return true;
    } 
    
    
    bool f(string s,string p,int i1,int i2){
        
        // base case 
        if(i1 < 0 and i2 <0) return true;
        if(i1 < 0 and i2 >= 0) return false;
        if(i2 < 0 and i1 >=0 ) return dp[i1][i2] = allstars(s,i1);
        
        if(dp[i1][i2] != -1) return dp[i1][i2];
        
        if(s[i1] == p[i2] or s[i1] == '?'){
            return dp[i1][i2]  = f(s,p,i1-1,i2-1);
        }
        if(s[i1] == '*'){
            return dp[i1][i2] = f(s,p,i1-1,i2) or f(s,p,i1,i2-1);
        }
        return dp[i1][i2] = false;
    }
    bool match(string wild, string pattern)
    {
        memset(dp,-1,sizeof(dp));
        return f(wild,pattern,wild.size()-1,pattern.size()-1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends