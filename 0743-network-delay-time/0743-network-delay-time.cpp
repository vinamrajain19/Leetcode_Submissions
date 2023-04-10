class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> dis(n+1,1e9);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,k}); // {time,node};
        
        dis[k] = 0;
       
        while(pq.size()){
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                if(dis[it.first] > it.second + dis[node]){
                    dis[it.first] = it.second + dis[node];
                    pq.push({dis[it.first],it.first});
                }
            }
            
        }
        
        int ans = -1e9;
        for(int i =1;i<n+1;i++){
            if(dis[i] >= 1e9) return -1;
            ans = max(ans,dis[i]);
        }
        
        return ans;
        
    }
};