class Solution {
public:
    
    void dfs(vector<vector<int>>& g,int i,int j){
        if(i<0 || i>=g.size() || j<0 || j>=g[0].size() || g[i][j] == 0){
            return;
        }
        
        g[i][j] = 0;
        
        dfs(g,i-1,j); //up
        dfs(g,i,j+1); //right
        dfs(g,i+1,j); //down
        dfs(g,i,j-1); //left
    }

    int numEnclaves(vector<vector<int>>& g){
        int m = g.size();
        int n = g[0].size();
        for(int i = 0;i<m;i++){
            if(g[i][0] == 1 ) dfs(g,i,0);
            if(g[i][n-1] == 1) dfs(g,i,n-1);
        }
        
        for(int i = 0;i<n;i++){
            if(g[0][i] == 1 ) dfs(g,0,i);
            if(g[m-1][i] == 1) dfs(g,m-1,i);
        }
        
        int cnt = 0;
        for(int i = 0;i<m;i++){
            for(int  j = 0;j<n;j++){
                if(g[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
        
    } 
};