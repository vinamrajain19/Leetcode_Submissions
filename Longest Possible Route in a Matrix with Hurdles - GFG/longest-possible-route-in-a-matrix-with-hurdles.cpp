//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {   // -2147483648
public:
    
    int f(vector<vector<int>> &m,int xs,int ys,int xd,int yd,int i,int j,vector<vector<int>> &vis){
        if( i< 0 or j < 0 or  i>=m.size() or j >= m[0].size() or vis[i][j] == 1 or m[i][j] == 0) return INT_MIN;
        
        if(i == xd and j == yd) return 0;
        
        vis[i][j] = 1;
        
        int a = 1 + f(m,xs,ys,xd,yd,i+1,j,vis);
        int b = 1 + f(m,xs,ys,xd,yd,i-1,j,vis);
        int c = 1 + f(m,xs,ys,xd,yd,i,j+1,vis);
        int d = 1 + f(m,xs,ys,xd,yd,i,j-1,vis);
        
        vis[i][j] = 0;
        
        return max({a,b,c,d});
        
    }
    
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        vector<vector<int>> vis(matrix.size(),vector<int>(matrix[0].size(),0));
        if( f(matrix,xs,ys,xd,yd,xs,ys,vis) <= -1) return -1;
        return f(matrix,xs,ys,xd,yd,xs,ys,vis);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends