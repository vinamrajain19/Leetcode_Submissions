typedef tuple<int,int,int> ti;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     
        vector<pair<int,int>> adj[n];
        for(int i = 0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        
        vector<int> dis(n,1e9);
        dis[src] = 0;
        queue<ti> pq;
        pq.push({0,src,0});
        
        while(pq.size() != 0){
            auto [x,d,steps] = pq.front();
            pq.pop();
            
            
            for(auto it : adj[d]){
                if(dis[it.first] > x + it.second and steps <= k) {
                    dis[it.first] = x + it.second;
                    pq.push({dis[it.first],it.first,steps+1});
                }
            }
        }
        
        if(dis[dst] >= 1e9) return -1;      
        
        return dis[dst];
        
    }
};