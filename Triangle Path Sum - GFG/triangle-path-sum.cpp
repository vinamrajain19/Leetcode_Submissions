//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int dp[201][201];
    int f(vector<vector<int>> & t,int i,int j){
        
       // if(i >= t.size() or j >= t[0].size()) return 1e9;
        
        if(i == t.size()-1) return t[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = t[i][j] + f(t,i+1,j);
        int b = t[i][j] + f(t,i+1,j+1);
        
        return dp[i][j] =  min(a,b);
    
    }
    
    int minimumTotal(vector<vector<int>>& t) {
        memset(dp,-1,sizeof(dp));
        return f(t,0,0);
    }
    
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        return minimumTotal(triangle);
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends