//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
      void bfs(int i,int j,vector<vector<int>>&grid, vector<vector<int>>&vis,vector<pair<int,int>>&v,int i0,int j0)
  {
       int n=grid.size();
       int m=grid[0].size();
      int d1[4]={-1,0,1,0};
      int d2[4]={0,1,0,-1};
      queue<pair<int,int>>q;
      q.push({i,j});
      vis[i][j]=1;
    //   v.push_back({i-i0,j-j0});
      while(!q.empty())
      {
          auto it=q.front();
          q.pop();
          int r=it.first;
          int c=it.second;
          v.push_back({r-i0,c-j0});
          for(int i=0;i<4;i++)
          {
             int nr=r+d1[i];
             int nc=c+d2[i];
             if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0)
             {
                 q.push({nr,nc});
                 vis[nr][nc]=1;
             }
          }
          
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(!vis[i][j] && grid[i][j]==1)
               {
                  vector<pair<int,int>>v;
                  bfs(i,j,grid,vis,v,i,j);
                  st.insert(v);
               }
            }
        }
        
        return st.size();
        // code here
    }

};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends