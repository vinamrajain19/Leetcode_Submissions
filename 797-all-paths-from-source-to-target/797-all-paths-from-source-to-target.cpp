class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> adj[],int node,vector<int> &t,int n){
        t.push_back(node);
        
        if(node == n-1){
            ans.push_back(t);
        }
        
        for(auto it : adj[node]){
           dfs(adj,it,t,n);
        }
        
        t.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[graph.size()];
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<graph[i].size();j++)
                adj[i].push_back(graph[i][j]);
        }
        
        
        vector<int> t;
        dfs(adj,0,t,n);
        
        return ans;
    }
};