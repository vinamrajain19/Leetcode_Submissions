class Solution {
public:
    
    // DSU
    
    int par[26];
    
    int find(int u){
        if(par[u] == -1) return u;
        return par[u] = find(par[u]);
    }
    
    void unnion(int u,int v){
        u = find(u);
        v = find(v);
        
        if(u != v){
            par[max(u,v)] = min(u,v);
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string base) {
        memset(par,-1,sizeof(par));
        
       for(int i = 0;i<s1.size();i++){
           unnion(s1[i]-'a',s2[i]-'a');
       }
        
      for(int i = 0;i<base.size();i++){
          base[i] = find(base[i]-'a')+'a';
      }
        return base;
    }
};