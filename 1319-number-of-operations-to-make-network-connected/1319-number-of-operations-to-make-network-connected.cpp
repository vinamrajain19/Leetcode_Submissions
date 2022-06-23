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
    
    int makeConnected(int n, vector<vector<int>>& c) {
        if(n-1 > c.size()) return -1;
        par.resize(n,0);
        for(int i = 0 ;i<n;i++){
            par[i] = i;
        }
        
        int x = 0;
        for(int i = 0;i<c.size();i++){
            if(find(c[i][0]) != find(c[i][1])){
                x++;
                unnion(c[i][0],c[i][1]);
            }
        }
        
        return n-x-1;
    }
};