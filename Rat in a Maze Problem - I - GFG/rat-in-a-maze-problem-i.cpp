//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
   vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        if(m[0][0] == 1){
            helper("",0,0,n,m,ans,vis);
        }
        return ans;
    }
    
    void helper(string p,int r,int c,int n,vector<vector<int>> &m,vector<string> &ans,vector<vector<int>> &vis){
        if(r == n-1 and c == n-1){
            ans.push_back(p);
            return;
        }
        
        if(r+1<n and m[r+1][c] == 1 and vis[r+1][c] == 0){
            vis[r][c] = 1;
            helper(p+'D',r+1,c,n,m,ans,vis);
            vis[r][c] = 0;
        }
        
        if(c-1>=0 and m[r][c-1] == 1 and vis[r][c-1] == 0){
            vis[r][c] = 1;
            helper(p+'L',r,c-1,n,m,ans,vis);
            vis[r][c] = 0;
        }
        
        if(c+1<n and m[r][c+1] == 1 and vis[r][c+1] == 0){
            vis[r][c] = 1;
            helper(p+'R',r,c+1,n,m,ans,vis);
            vis[r][c] = 0;
        }
        
        if(r-1>=0 and m[r-1][c] == 1 and vis[r-1][c] == 0){
            vis[r][c] = 1;
            helper(p+'U',r-1,c,n,m,ans,vis);
            vis[r][c] = 0;
        }
        
       

    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends