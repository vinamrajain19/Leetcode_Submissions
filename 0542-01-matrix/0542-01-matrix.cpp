class Solution {
public:
    
    // BFS
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n,1e9));
        queue<pair<int,int>> q;
        
        for(int i  = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(auto it : d){
                int ii = x + it[0];
                int jj = y + it[1];
                
                if(ii < 0 or jj< 0 or ii >= m or jj >= n or ans[ii][jj] != 1e9){
                    continue;
                }
                
                 if(ans[ii][jj] > ans[x][y] + 1){
                      ans[ii][jj]  = ans[x][y] + 1;
                      q.push({ii,jj});
                 }
            }
        }
        
        
        
        return ans;
        
    }
};