typedef tuple<int,int,int> ti;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> dis(n,1e9);
        
        dis[src] = 0;
        
        queue<ti> pq;
        pq.push({0,src,0});
        
        while(pq.size()){
            auto [d,node,steps] = pq.front();
            pq.pop();
            
            
            for(auto it : adj[node]){
                if(dis[it.first] > d + it.second and steps <= k){
                    dis[it.first] = d + it.second;
                    pq.push({dis[it.first],it.first,steps+1});
                }
            }
        }
        
        if(dis[dst] >= 1e9) return -1;
        return dis[dst];
    }
};