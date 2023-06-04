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
    
    int findCircleNum(vector<vector<int>>& is) {
        int n = is.size();
        
        par.resize(n+1);
        
        for(int i = 1;i<=n;i++){
            par[i] = i;
        }
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i == j) continue;
                if(is[i][j] and find(i+1) != find(j+1)){
                    unnion(i+1,j+1);
                }
            }
        }
        
        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(par[i] == i) ans++;
        }
        
        return ans;
    }
};