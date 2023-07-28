class Solution {
public:
    
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    bool f(int i,int j,int previ,int prevj,vector<vector<char>>& grid, vector<vector<int>>& vis,int m,int n){
        
        vis[i][j] = 1;
        
        for(auto it:dir){
            int x = it[0]+i;
            int y = it[1]+j;
            
            if(x<0 || y<0 || x >= m || y >= n || grid[i][j]!=grid[x][y]) continue;
            
            if(!vis[x][y]){
                if(f(x,y,i,j,grid,vis,m,n)) return true;
            }
            else{
               if(x!=previ && y!=prevj) return true; 
            }
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(vis[i][j] == 0){
                    if(f(i,j,-1,-1,grid,vis,m,n)) return true;
                }
            }
        }
        return false;
    }
};