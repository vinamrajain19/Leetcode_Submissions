class Solution {
public:
    // t.c = O(n^2 logn) -> logn for dsu
    // Union Find
    
    vector<int> par;
    int find(int num){
        if(par[num] == num) return par[num];
        return par[num] = find(par[num]);
    }
    
    void unnion(int u,int v){
        u = find(u);
        v = find(v);
        
        if(u == v){
            return;
        }
        
        par[v] = u;
    }
    
    int removeStones(vector<vector<int>>& s) {
        
        int n = s.size();
        par.resize(n,0);
        for(int i = 0;i<n;i++){
            par[i] = i;
        }
        
        
        for(int i = 0;i<s.size();i++){
            for(int j = i+1;j<s.size();j++){
                if(s[i][0] == s[j][0] or s[i][1] == s[j][1]){
                    unnion(i,j);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(i == find(i)){
                ans++;
            }
        }
        
        return n-ans;
    }
};