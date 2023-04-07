class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        
        vector<int> color(g.size(),-1);
        
        for(int i = 0;i<g.size();i++){
            if(color[i] == -1){
                
                color[i] = 1;
                
                queue<int> q;
                
                q.push(i);

                while(q.size()){
                    int t = q.front();
                    q.pop();

                    for(auto it : g[t]){
                        if(color[it] == -1){
                            color[it] = 1- color[t];
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