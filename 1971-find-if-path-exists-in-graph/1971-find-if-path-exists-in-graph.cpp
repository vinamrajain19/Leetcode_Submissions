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
        if(u == v){
            return;
        }
        par[v] = u;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        par.resize(n);
        for(int i = 0;i<n;i++) par[i] = i;
        for(int i= 0;i<edges.size();i++){
            if(find(edges[i][0]) != find(edges[i][1])){
                unnion(edges[i][0],edges[i][1]);
            }
        }
        cout<<find(src);
        cout<<find(dest);
        if(find(src) == find(dest)) return true;
        
        return false;
    }
};