class Solution {
public:
    
    void f(vector<vector<int>> &grid,int i,int j,int &cnt,vector<vector<int>> &vis){
        if(i < 0 or j <0 or i >= grid.size() or j >= grid[0].size() or vis[i][j] or grid[i][j] == 0) return;
        
        vis[i][j] = 1;
        
         cnt += grid[i][j];
        
         f(grid,i+1,j,cnt,vis);
         f(grid,i-1,j,cnt,vis);
         f(grid,i,j+1,cnt,vis);
         f(grid,i,j-1,cnt,vis);  
        
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        
        int ans = 0;
        
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] > 0){
                    int cnt = 0;
                    vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
                    f(grid,i,j,cnt,vis);
                    ans = max(ans,cnt);
                }
            }
        }
        
        return ans;
    }
};