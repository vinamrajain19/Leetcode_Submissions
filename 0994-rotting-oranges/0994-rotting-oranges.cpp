
class Solution {
public:
   
    
    int orangesRotting(vector<vector<int>>& grid) {
        
       queue<pair<int,int>> q;
       int fresh = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        
        if(fresh == 0) return 0;
        
        int ans = 0;
        while(q.size() != 0){
            int n = q.size();
            if(fresh == 0) return ans;
            while(n--){
                int x = q.front().first;
                int  y = q.front().second;
                q.pop();
                if(x > 0 and grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    q.push({x-1,y});
                    fresh--;
                }
                
                if(y > 0 and grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    q.push({x,y-1});
                    fresh--;
                }
                
                if(x < grid.size() - 1 and grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    q.push({x+1,y});
                    fresh--;
                }
                
                if(y < grid[0].size() - 1 and grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    q.push({x,y+1});
                    fresh--;
                }
            }
            if(q.size() != 0) ans++;
        }
       // if(fresh == 0) return ans;
        return -1;
    }
};