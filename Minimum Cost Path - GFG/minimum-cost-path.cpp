//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        
        int n = grid.size();
        
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dis[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}});
        
        
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        
        while(pq.size()){
            int dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            
            pq.pop();
            
            for(int i = 0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                
                if(nx < 0 or ny < 0 or  nx >= n or ny >= n) continue;
                
                if(grid[nx][ny] + dist < dis[nx][ny]){
                    dis[nx][ny] = grid[nx][ny] + dist;
                    pq.push({dis[nx][ny],{nx,ny}});
                }
            }
            
        }
        
        return dis[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends