class Solution {
public:
    
    vector<vector<int>> ans;
    
    void f(int node,vector<int> t,vector<int> adj[],int n){
        
        t.push_back(node);
        
        if(node == n-1){
            ans.push_back(t);
            return;
        }
        
        
        for(auto it : adj[node]){
            
            f(it,t,adj,n);
        }
        
        t.pop_back();
        
       
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> adj[graph.size()];
        int n = graph.size();
        for(int i = 0;i<graph.size();i++){
            for(int j = 0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        
        
        f(0,{},adj,n);
        return ans;   
    }
};