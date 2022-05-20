class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        //vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<int> prev(n,0);
        
        for(int i = 0;i<m;i++){
            vector<int> temp(n,0);
            for(int j = 0;j<n;j++){
                if(i == 0 && j == 0) temp[j] = grid[i][j];
                else{
                    int u = grid[i][j];
                    if(i>0){
                        u += prev[j];
                    }
                    else u = 1e9;
                    
                    int l = grid[i][j];
                    if(j>0){
                        l += temp[j-1];
                    }
                    else l = 1e9;
                    
                    temp[j] = min(u,l);
                }
            }
            prev = temp;
        }
        
        return prev[n-1];
    }
  
};