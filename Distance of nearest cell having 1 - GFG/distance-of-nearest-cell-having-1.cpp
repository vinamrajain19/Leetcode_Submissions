//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n,1e9));
        queue<pair<int,int>> q;
        
        for(int i  = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 1){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(auto it : d){
                int ii = x + it[0];
                int jj = y + it[1];
                
                if(ii < 0 or jj< 0 or ii >= m or jj >= n or ans[ii][jj] != 1e9){
                    continue;
                }
                
                 if(ans[ii][jj] > ans[x][y] + 1){
                      ans[ii][jj]  = ans[x][y] + 1;
                      q.push({ii,jj});
                 }
            }
        }
        
        
        
        return ans;
        
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    return updateMatrix(grid);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends