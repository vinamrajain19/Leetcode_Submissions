//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesrotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        
        queue<pair<int,int>> q;
        
        
        int fresh = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 1) fresh++;
            }
        }
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        if(fresh == 0) return 0;
        
        
        int ans = 0;
        
        while(q.size()){
            
            int t = q.size();
            
           // ans++;
            if(fresh == 0) return ans;
            
            while(t--){
                int x = q.front().first;
                int y = q.front().second;
        
            
            q.pop();
            
            for(int i = 0;i<=3;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 or ny < 0 or  nx >= m or ny >= n or grid[nx][ny] == 2 or grid[nx][ny] == 0) continue;
                
                if(grid[nx][ny] == 1){
                    fresh--;
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
            
            }
            
            ans++;
            
        }
        
        return -1;
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        return orangesrotting(grid);
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends