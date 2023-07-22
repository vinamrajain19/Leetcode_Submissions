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
    bool equationsPossible(vector<string>& e) {
        par.resize(26);
        for(int i = 0;i<26;i++){
            par[i] = i;
        }
        for(int i = 0;i<e.size();i++){
            if(e[i][1] == '='){
                unnion(e[i][0] - 'a',e[i][3]-'a');
            }
        }
        
        for(int i = 0;i<e.size();i++){
            if(e[i][1] == '!' and find(e[i][0]-'a') == find(e[i][3]-'a')){
                return false;
            }
        }
        return true;
    }
};