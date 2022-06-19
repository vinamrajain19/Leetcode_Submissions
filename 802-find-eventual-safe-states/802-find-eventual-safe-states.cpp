// Cycle Detection Algo of Directed Graph -> Vis and DFSVis vector -> so after dfs -> Dfsvis vector -> has 0 value -> is our ans
class Solution {
public:
    bool dfs(vector<vector<int>> &graph,int node,vector<int> &vis,vector<int> &dfsvis){
        vis[node] = 1;
        dfsvis[node] = 1;
        
        for(auto it : graph[node]){
            if(vis[it] == 0){
                if(dfs(graph,it,vis,dfsvis)) return true;
            }
            else if(dfsvis[it] and vis[it]){
                return true;
            }
        }
        dfsvis[node] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
          
        
        vector<int> vis(graph.size(),0);
        vector<int> dfsvis(graph.size(),0);
        //disconected grpah
        for(int i = 0;i< graph.size();i++){
            if(vis[i] == 0){
                dfs(graph,i,vis,dfsvis);
            }
        }
        vector<int> safe;
        for(int i = 0 ;i<graph.size();i++){
            if(dfsvis[i] == 0 and vis[i] == 1){
                safe.push_back(i);
            }
        }
        return safe;
    }
};