class Solution {
public:
     void dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == 1){
            return;
        }
        
        grid[i][j] = 1;
        
        dfs(grid,i-1,j); //up
        dfs(grid,i,j+1); //right
        dfs(grid,i+1,j); //down
        dfs(grid,i,j-1); //left
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
       // as we know boundary land cannot be our ans so we are making bounday land into water using dfs
        for(int i = 0;i<n;i++){
            if(grid[i][0] == 0) dfs(grid,i,0);
            if(grid[i][m-1] == 0) dfs(grid,i,m-1);
        }
        
        for(int j = 0;j<m;j++){
            if(grid[0][j] == 0) dfs(grid,0,j);
            if(grid[n-1][j] == 0) dfs(grid,n-1,j);
        }
        
        
        // after making land boundary as water only then we can say that no of closed islands is nothing but no of times dfs has been called 
        int cnt = 0;
        for(int i = 1;i<=n-2;i++){
            for(int  j = 1;j<=m-2;j++){
                if(grid[i][j] == 0){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
        
    }
};