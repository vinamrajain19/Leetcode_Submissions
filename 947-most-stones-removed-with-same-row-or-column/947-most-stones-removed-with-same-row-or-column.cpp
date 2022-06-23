class Solution {
public:
    // use union find -> when we get row or col equal -> union those -> and find -> how many parents are there;
    
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
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        par.resize(n,0);
        for(int i = 0;i<n;i++){
            par[i] = i;
        }
        
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]){
                    unnion(i,j); 
                }
            }
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(i == par[i]){
                ans++;
            }
        }
        return n-ans;
       
    }
};