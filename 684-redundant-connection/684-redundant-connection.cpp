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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        par.resize(edges.size()+1);
        par[0] = -1;
        for(int i = 1;i<edges.size()+1;i++){
            par[i] = i;
        }
        vector<vector<int>> ans;
        for(int i = 0;i<edges.size();i++){
            if(find(edges[i][0]) == find(edges[i][1])){
                ans.push_back({edges[i][0],edges[i][1]});
            }
            else{
                unnion(edges[i][0],edges[i][1]);
            }
        }
        return ans[ans.size()-1];
    }
};