class Solution {
public:
    void dfs(vector<vector<int>> &g,int i,int j,vector<pair<int,int>> &island,vector<vector<bool>> &vis){
        if(i < 0 or j< 0 or i >= g.size() or j >= g.size() or vis[i][j] == true or g[i][j] == 0) return;
        
        vis[i][j] = true;
        island.push_back({i,j});
        
        dfs(g,i-1,j,island,vis);
        dfs(g,i,j-1,island,vis);
        dfs(g,i+1,j,island,vis);
        dfs(g,i,j+1,island,vis);
        
    }
    
    int shortestBridge(vector<vector<int>>& g) {
        vector<pair<int,int>> is1;
        vector<pair<int,int>> is2;
        
        vector<vector<bool>> vis(g.size(),vector<bool>(g.size(),false));
        
        int x = 1;
        for(int  i = 0;i<g.size();i++){
            for(int j = 0;j<g.size();j++){
                
                if(g[i][j] == 1 and vis[i][j] == false){
                    if(x == 1) dfs(g,i,j,is1,vis);
                    else if(x == 2) dfs(g,i,j,is2,vis);
                    x++;
                }
            }
        }
        
        int bridge = 1e9;
        for(int i = 0;i<is1.size();i++){
            cout<<is1[i].first<<endl;
            for(int j = 0;j<is2.size();j++){
                
                int dis = abs(is1[i].first - is2[j].first) + abs(is1[i].second - is2[j].second) - 1;
                bridge = min(bridge,dis);
            }
        }
        
        return bridge;
        
    }
};