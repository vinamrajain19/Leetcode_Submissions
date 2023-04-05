//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void solve(vector<vector<int>>& board) {
       
        if(board.size()==0||board[0].size()==0)return;
       
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]==1){dfs(board,0,i);}
            if(board[board.size()-1][i]==1){dfs(board,board.size()-1,i);}
        }
       
        for(int i=1;i<board.size()-1;i++){
            if(board[i][0]==1)dfs(board,i,0);
            if(board[i][board[0].size()-1]==1){dfs(board,i,board[0].size()-1);}
        }
       
    }
    
    
    void dfs(vector<vector<int>>& board, int i, int j){
        if(i<0||i>=board.size()||j<0||j>=board[0].size())return;
        
        if(board[i][j]!=1)return;
        
        board[i][j]= 0;
        
        dfs(board,i+1,j);
        dfs(board,i,j+1);
        dfs(board,i-1,j);
        dfs(board,i,j-1);
        return;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        solve(grid);
        int ans = 0;
        for(int i= 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1) ans++;
            }
        }
        
        return ans;
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        return numEnclaves(grid);
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends