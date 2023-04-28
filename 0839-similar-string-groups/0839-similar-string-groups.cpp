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
        v = find(v);
        
        if(u == v) return;
        par[v] = u;
    }
    
    bool f(string &a,string &b){
        int i = 0;
        
        int cnt = 0;
        
        while(i < a.size()){
            if(a[i] == b[i]){
                i++;
            }
            else{
                cnt++;
                i++;
            }
        }
        
        if(cnt <= 2) return true;
        return false;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        
        par.resize(n+1,0);
        
        for(int i = 0;i<n;i++) par[i] = i;
        
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(f(strs[i],strs[j])){
                    unnion(i,j);
                }
            }
        }
        
        int ans = 0;
        
        
        
        for(int i = 0;i<n;i++){
            if(par[i] == i){
                cout<<par[i]<<" ";
                ans++;
            }
        }
        
        return ans;
    }
};