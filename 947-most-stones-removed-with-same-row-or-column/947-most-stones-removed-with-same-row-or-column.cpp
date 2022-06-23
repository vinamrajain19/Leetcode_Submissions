class Solution {
public:
    // use union find -> when we get row or col equal -> union those -> and find -> how many parents are there;
    
    vector<int> par;
    
    int find(int u){
        if(u == par[u]) return u;
        return par[u] = find(par[u]);
    }
    
    bool unnion(int u,int v){
        u = find(u);
        v = find(v);
        if(u == v){
            return false;
        }
        par[v] = u;
        return true;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        par.resize(n);
        for(int i = 0;i<n;i++){
            par[i] = i;
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]){
                    if(unnion(i,j)) ans++;  
                }
            }
        }
       
        return ans;
    }
};