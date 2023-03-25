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
    
    long long countPairs(int n, vector<vector<int>>& edges) {
      
        par.resize(n);
        for(int i = 0;i<n;i++){
            par[i] = i;
        }
        
        for(int i = 0;i<edges.size();i++){
            if(find(edges[i][0]) != find(edges[i][1])){
                unnion(edges[i][0],edges[i][1]);
            }
        }
        
        unordered_map<int,int> m;
        
        for(int i = 0;i<n;i++){
            m[find(par[i])]++;
        }
        
        long long sum = 0;
        
        for(auto it: m){
            sum += 1ll * it.second * (n-it.second);
            n -= it.second;
        }
       
        return sum;
    }
};