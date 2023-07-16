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
        
        if(u == v) return ;
        
        par[v] = u;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int n = e.size();
        par.resize(n+1);
        for(int i = 0;i<=n;i++) par[i] = i;
        
        
        for(auto it : e){
            if(find(it[0]) != find(it[1])){
                unnion(it[0],it[1]);
            }
            else return it;
        }
        
        return {-1,-1};
    }
};