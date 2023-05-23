class Solution {
public:
    
    
    int ans = -1e9;
    
    void dfs(vector<pair<int,int>> adj[],int maxTime,int time,int node,int q,vector<int> &values,vector<int> &vis){
        if(time > maxTime) return;
        
        if(vis[node] == 0) q += values[node];
        
        if(node == 0) ans = max(ans,q);
        
        vis[node]++;
      
        
        for(auto it : adj[node]){
            dfs(adj,maxTime,time+it.second,it.first,q,values,vis);
        }
        
        vis[node]--;
        
    }
    
    
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        vector<pair<int,int>> adj[values.size()];
        
        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        vector<int> vis(values.size(),0);
        
        dfs(adj,maxTime,0,0,0,values,vis);
        return ans;
        
        
    }
};