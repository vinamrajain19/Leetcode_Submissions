class Solution {
public:
    
    vector<vector<int>> ans;
    
    void dfs(int node,vector<int> &vis,vector<int> adj[],vector<int> &tin,vector<int> &low,int parent,int &timer){
        vis[node] = 1;
        low[node] = tin[node] = ++timer;
        
        for(auto it: adj[node]){
            if(it == parent) continue;
            
            if(vis[it] == 0){
                dfs(it,vis,adj,tin,low,node,timer);
                low[node] =  min(low[node],low[it]);
                if(low[it] > tin[node]){
                    ans.push_back({it,node});
                }
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        
        vector<int> adj[n];
        for(int i = 0;i<c.size();i++){
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }
        
        vector<int> tin(n,-1);
        vector<int> low(n,-1);
        vector<int> vis(n,0);
        
        
        int timer = 0;
        for(int i =0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj,tin,low,-1,timer);
            }
        }
        
        return ans;
    }
};