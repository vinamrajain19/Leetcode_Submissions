class Solution {
public:
    //do simple no of island dfs on grid2 -> and if there is any cell on grid1 which has water but grd2 has land -> then we will check this case in dfs -> if this is true -> then do not cnt this island -> return;
    bool flag;
    void dfs(vector<vector<int>>& g1, vector<vector<int>>& g2,int i,int j){
        if(i<0 or j<0 or i>=g1.size() or j>=g1[0].size() or g2[i][j] == 0){
            return;
        }
        
        // if g1 has water and g2 has land ignore that island
        if(g1[i][j] == 0 and g2[i][j] == 1){
            flag = false;
            return;
        } 
        
        g2[i][j] = 0;
        dfs(g1,g2,i-1,j);
        dfs(g1,g2,i,j-1);
        dfs(g1,g2,i+1,j);
        dfs(g1,g2,i,j+1);
    }
    
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        int ans = 0;
        for(int  i = 0;i<g1.size();i++){
            for(int j = 0;j<g1[0].size();j++){
                if(g2[i][j] == 1){
                    flag = true;
                    dfs(g1,g2,i,j);
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
};