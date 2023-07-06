class Solution {
public:
    
    void f(vector<vector<char>> &g,int i,int j){
        if(i < 0 or j < 0 or i >= g.size() or j >= g[0].size() or g[i][j] == '0') return;
        
        g[i][j] = '0';
        f(g,i+1,j);
        f(g,i-1,j);
        f(g,i,j+1);
        f(g,i,j-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    ans++;
                    f(grid,i,j);
                }
            }
        }
        
        return ans;
    }
};