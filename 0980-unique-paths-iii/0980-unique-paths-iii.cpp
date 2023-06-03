class Solution {
public:
    
    bool f1(vector<vector<int>> &grid,vector<vector<int>> &vis){
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 0 and vis[i][j] == 0) return false;
            }
        }
        
        return true;
    }
    
    int f(vector<vector<int>> &grid,int i,int j,vector<vector<int>> &vis){
        if(i < 0 or j < 0 or i >= grid.size() or  j>= grid[0].size() or grid[i][j] == -1 or vis[i][j]) return 0;
        
        if(grid[i][j] == 2 and f1(grid,vis)) return 1;
        
        vis[i][j] = 1;
        
        int a = f(grid,i+1,j,vis);
        int b = f(grid,i,j+1,vis);
        int c = f(grid,i-1,j,vis);
        int d = f(grid,i,j-1,vis);
        
        vis[i][j] = 0;
        
        return a+b+c+d;
        
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    int ans = f(grid,i,j,vis);
                    //if(ans == 0) return -1;
                    return ans;
                }
            }
        }
        
        return -1;
    }
};