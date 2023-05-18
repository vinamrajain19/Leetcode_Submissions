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
            unnion(i+1,i);
        }
        
        int ans = 0;
        
        for(int i = 0;i<row.size();i+=2){
            if(find(row[i]) != find(row[i+1])){
                ans++;
                unnion(row[i],row[i+1]);
            }
        }
        
        cout<<par[0];
        cout<<par[1];
        cout<<par[2];
        cout<<par[3];
        
        return ans;
    }
};