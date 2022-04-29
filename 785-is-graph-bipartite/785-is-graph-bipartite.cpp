class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
         int n = graph.size();
         vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(!bfs(graph,color,i)){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool bfs(vector<vector<int>>& graph,vector<int> & color,int node){
        color[node] = 1;
        queue<int> q;
        q.push(node);
        
        while(q.size() != 0){
            int temp = q.front();
            q.pop();
            
            for(auto it : graph[temp]){
                if(color[it] == -1){
                    q.push(it);
                    color[it] = 1 - color[temp];
                }
                else if(color[it] == color[temp]){
                    return false;
                }
            }
        }
        return true;
    }
};