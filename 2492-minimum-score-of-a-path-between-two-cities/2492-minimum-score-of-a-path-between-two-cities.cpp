class Solution {
public:
    int ans = 1e9;
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n+1];
        
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> vis(n+1,0);
        queue<pair<int,int>> q;
        q.push({1,1e9});
        
        
        while(q.size()){
            auto it = q.front();
            q.pop();
            vis[it.first] = 1;
            ans = min(ans,it.second);
            
            for(auto i : adj[it.first]){
                if(vis[i.first] == 0) q.push({i.first,i.second});
            }
        }
        
        return ans;
        
    }
};