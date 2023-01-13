class Solution {
public:
    
    // observation:
// a node can have at most two longest chains from child nodes
// if a node have more than two chains, take the longest two
// i.e. one parent node + longest + second longest
    
    int ans = -1e9;
    int dfs(vector<int> adj[],int node,string &s){
        
        int mx = 0;
        int secmx = 0;
        for(auto it: adj[node]){
            
            int t = dfs(adj,it,s);
            
            if(s[it] != s[node]){
                if(secmx < t) secmx = t;
                if(secmx > mx) swap(mx,secmx);
            }
        }
        
        ans = max(ans,1+mx+secmx);
        return 1 + mx;
    }
    
    
    int longestPath(vector<int>& parent, string s) {
        
        vector<int> adj[parent.size()];
        
        for(int i = 0;i<parent.size();i++){
            if(parent[i] != -1) adj[parent[i]].push_back(i);
        }
        
        dfs(adj,0,s);
        return ans;
    }
};