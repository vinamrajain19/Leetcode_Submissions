//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void solve(vector<vector<char>>& board) {
       
        if(board.size()==0||board[0].size()==0)return;
       
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O'){dfs(board,0,i);}
            if(board[board.size()-1][i]=='O'){dfs(board,board.size()-1,i);}
        }
       
        for(int i=1;i<board.size()-1;i++){
            if(board[i][0]=='O')dfs(board,i,0);
            if(board[i][board[0].size()-1]=='O'){dfs(board,i,board[0].size()-1);}
        }
       
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='1')board[i][j]='X';
                if(board[i][j]=='1')board[i][j]='O';
            }
        }
       
    }
    
    
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0||i>=board.size()||j<0||j>=board[0].size())return;
        if(board[i][j]!='O')return;
        board[i][j]='1';
        dfs(board,i+1,j);
        dfs(board,i,j+1);
        dfs(board,i-1,j);
        dfs(board,i,j-1);
        return;
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        solve(mat);
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends