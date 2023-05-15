class Solution {
public:
    
    int dp[71][71][71];
    
    int f(vector<vector<int>> &grid,int i1,int j1,int j2){
        if(i1 < 0 or j1 < 0 or i1 >= grid.size() or j1 >= grid[0].size()) return -1e9;
        if(j2 < 0 or j2 >= grid[0].size()) return -1e9;
        
        
        if(i1 == grid.size()-1){
            if(j1 == j2) return grid[i1][j1];
            return grid[i1][j1] + grid[i1][j2];
        }
        
        if(dp[i1][j1][j2] != -1) return dp[i1][j1][j2];
        
        int ans = 0;
        
        if(j1 == j2){
            ans += grid[i1][j1];
        }
        else{
            ans += grid[i1][j1];
            ans += grid[i1][j2];
        }
        
        int temp = 0;
        for(int i = -1;i<=1;i++){
            for(int j = -1;j<=1;j++){
                temp = max(temp,f(grid,i1+1,j1+i,j2+j));
            }
        }
        
        return dp[i1][j1][j2] =  ans+temp;
        
    }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return f(grid,0,0,grid[0].size()-1);
    }
};