class Solution {
public:
    vector<int> par;
    int find(int u){
        if(u == par[u]) return u;
        
        return par[u] = find(par[u]);
    }
    
    void unnion(int u,int v){
        u = find(u);
        v = find(v);
        
        if(u == v) return;
        par[v] = u;
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        par.resize(V+1,0);
        for(int i = 1;i<=V;i++) par[i] = i;
        
        for(int i = 0;i<adj.size();i++){
            for(int j = 0;j<adj[0].size();j++){
                if(adj[i][j] == 1){
                    if(find(i+1) != find(j+1)){
                        unnion(i+1,j+1);
                    }
                }
            }
        }
        
        unordered_map<int,int> m;
        for(int i = 1;i<=V;i++){
            m[find(i)]++;
        }
        
        return m.size();
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        return numProvinces(isConnected,isConnected.size());
    }
};