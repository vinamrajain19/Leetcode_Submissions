// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  
    int f(string s,string t,int i,int j,vector<vector<int>> &dp){
        if(i < 0 and j < 0) return 0;
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];  
        
        if(s[i] == t[j]){
            return dp[i][j] =  f(s,t,i-1,j-1,dp);       // match -> i-1,j-1
        }
        
        
        // insert -> (i,j-1) delete -> (i-1,j)  repalce -> (i-1,j-1)
        return dp[i][j] = 1 + min({f(s,t,i-1,j-1,dp) , f(s,t,i-1,j,dp) , f(s,t,i,j-1,dp)});
    }
    
    int editDistance(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return f(s,t,s.size()-1,t.size()-1,dp);
    }
    
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends