class Solution {
public:
    
    // T.C = O(V+E)
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n,-1);
        
        for(int i = 0;i<n;i++){
            if(color[i] == -1){
                color[i] = 1;
                queue<int> q;
                q.push(i);
                
                while(q.size()){
                    int t = q.front();
                    q.pop();
                    
                    for(auto it : graph[t]){
                        if(color[it] == -1){
                            color[it] = 1-color[t];
                            q.push(it);
                        }
                        else if(color[it] == color[t]) return false;
                    }
                }
            }
        }
        
        return true;
    }
};