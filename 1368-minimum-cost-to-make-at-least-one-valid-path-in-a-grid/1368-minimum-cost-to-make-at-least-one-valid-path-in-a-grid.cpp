class Solution {
public:
   
    
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        using ti = tuple<int,int,int>;
        
        priority_queue<ti,vector<ti>,greater<>> pq;
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        pq.emplace(0,0,0);
        
        while(pq.size()){
            auto [cost,x,y] = pq.top();
            pq.pop();
            
            if(vis[x][y] == 1) continue;
            
            vis[x][y] = 1;
            
            if(x == m-1 and y == n-1) return cost;

            
            for(int i = 0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
                    if (i == grid[x][y] - 1) {
                        pq.emplace(cost, nx, ny);
                    } else {
                        pq.emplace(cost + 1, nx, ny);
                    }
                }
            }
        }
        
        
        return -1;
        
        
    }
};