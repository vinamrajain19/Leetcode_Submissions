class Solution {
public:
    vector<int> v;
    void dfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        v.push_back(node);
        for(auto x: adj[node]){
            if(!vis[x]){
                dfs(x,adj,vis);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edge) {
        vector<int> adj[n];
        for(auto edges: edge){
            adj[edges[0]].push_back(edges[1]);
            adj[edges[1]].push_back(edges[0]);
        }
        
        vector<int> vis(n,0);
        vector<vector<int>>connected;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                connected.push_back(v);
                v.clear();
            }
        }
        int cnt=0;
        vector<int> degree(n,0);
        for(int i=0;i<n;i++){
            for(auto x: adj[i]){
                degree[x]++;
            }
        }
        for(auto x: connected){
            
            bool f=0;
            for(auto p: x){
                if(degree[p]!=x.size()-1){
                    f=1;
                }
            }
            if(f==0){
                cnt++;
            }
        }
        
        //sabki degree n-1 honi chahiye
        return cnt;
        
        
    }
};