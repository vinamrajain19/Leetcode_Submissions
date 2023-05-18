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
    
    
    int minSwapsCouples(vector<int>& row) {
        par.resize(row.size());
        
        for(int i = 0;i<row.size();i++){
            par[i] = i;
        }
        
        for(int i = 0;i<row.size();i+=2){
            unnion(row[i+1],row[i]);
        }
        
        int ans = 0;
        
        for(int i = 0;i<row.size();i+=2){
            if(find(i) != find(i+1)){
                ans++;
                unnion(i,i+1);
            }
        }
        
        return ans;
    }
};