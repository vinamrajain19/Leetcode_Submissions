//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    void solve(vector<vector<int>> matrix, int &maxi, int sum, int xs, int ys, int xd, int yd){
        if(xs<0 || ys<0 || xs>=matrix.size() || ys>=matrix[0].size() || matrix[xs][ys]==0)
            return;
        if(xs==xd && ys==yd){
            maxi=max(maxi,sum);
            return;
        }
        
        matrix[xs][ys]=0;
        
        solve(matrix,maxi,sum+1,xs+1,ys,xd,yd);
        solve(matrix,maxi,sum+1,xs,ys+1,xd,yd);
        solve(matrix,maxi,sum+1,xs-1,ys,xd,yd);
        solve(matrix,maxi,sum+1,xs,ys-1,xd,yd);
        
        matrix[xs][ys]=1;
        
    }
    
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        int maxi=-1;
        solve(matrix,maxi,0,xs,ys,xd,yd);
        return maxi==0?-1:maxi;
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