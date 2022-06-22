class Solution {
public:
    vector<int> par;
    int find(int u){
        if(u == par[u]){
            return u;
        }
        return par[u] = find(par[u]);
    }
    
    void unnion(int u,int v){
        u = find(u);
        v= find(v);
        if(u == v) return;
        par[v] = u;
    }
    
    int findCircleNum(vector<vector<int>>& is) {
        par.resize(is.size());
        for(int i = 0;i<is.size();i++){
            par[i] = i;
        }
        
        for(int i = 0;i<is.size();i++){
            for(int j = i+1;j<is[0].size();j++){
                if(is[i][j] == 1){
                    unnion(i,j);
                }
            }
        }
        
        int c = 0;
        for(int i = 0;i<par.size();i++){
            if(par[i] == i) c++; // no of parents
        }
        return c;
        
    }
};