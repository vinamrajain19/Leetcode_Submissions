class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                }
            }
        }
        
        int dis = 0;
        vector<int> dx = {-1,1,0,0};
        vector<int> dy = {0,0,-1,1};
            
        while(q.size()){
            int n = q.size();
            while(n--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int i = 0;i<4;i++){
                    int xx = x + dx[i];
                    int yy = y + dy[i];
                    
                    if(xx < 0 or yy < 0 or xx >= grid.size() or yy >= grid.size()) continue;
                    if(grid[xx][yy] == 0){
                        q.push({xx,yy});
                        grid[xx][yy] = grid[x][y]+1;
                        dis = max(dis,grid[xx][yy]);
                    }   
                    
                }
            }
           
        }
        
        if(dis == 0) return -1;
        return dis-1;
    }
};