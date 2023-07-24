class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
       int ans=0;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0) ans=max(ans,solve(grid,i,j,vis));
            }
        }
        return ans;
    }
    
    int solve(vector<vector<int>>& grid,int row,int col,vector<vector<bool>>& vis){
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || vis[row][col] == true)
        {
            return 0;
        }
        if(grid[row][col] == 0)
        {
            return 0;
        }
            
        vis[row][col] = true;
        
        int up = solve(grid,row-1,col,vis);
        int down = solve(grid,row+1,col,vis);
        int left = solve(grid,row,col-1,vis);
        int right = solve(grid,row,col+1,vis);
        
        vis[row][col] = false;
        return grid[row][col] + max(up,max(down,max(left,right)));
    }
};