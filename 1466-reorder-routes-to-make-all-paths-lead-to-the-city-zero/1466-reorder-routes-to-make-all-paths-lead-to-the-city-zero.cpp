class Solution {
public:
    
    void dfs(int x,vector<int> &vis,vector<pair<int,int>> adj[],int &ans){
        vis[x] = 1;
        for(auto it : adj[x]){
            if(vis[it.first] == 0){
                if(it.second == 1) ans++;
                dfs(it.first,vis,adj,ans);
            }  
        }
    }
    
    int minReorder(int n, vector<vector<int>>& c) {
        vector<pair<int,int>> adj[n];
        
        for(auto it : c){
            adj[it[0]].push_back({it[1],1});
            adj[it[1]].push_back({it[0],-1});
        }
        
        vector<int> vis(n,0);
        int ans = 0;
        dfs(0,vis,adj,ans);
        return ans;  
    }
};