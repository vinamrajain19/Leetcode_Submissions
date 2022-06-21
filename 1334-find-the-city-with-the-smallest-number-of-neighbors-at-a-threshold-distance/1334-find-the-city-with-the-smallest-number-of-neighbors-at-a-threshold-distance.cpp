typedef pair<int,int> pll;

class Solution {
public:
    
    int dij(int src,int n,int th,vector<pll> adj[]){
        
        priority_queue<pll,vector<pll>,greater<pll>> pq;
        vector<int> dis(n,1e9);
        dis[src]= 0;
        pq.push({0,src});
        
        while(pq.size()!=0){
            auto [d,node] = pq.top();
            pq.pop();
            
            for(auto [x,y] : adj[node]){
                if(dis[x] > y + dis[node]){
                    dis[x] = y + dis[node];
                    pq.push({dis[x],x});
                }
            }
        }
        
        int c = 0;
        for(int i =0;i<n;i++){
            if(th >= dis[i] and i != src){
                c++;
            }
        }
        cout<<c<<endl;
        return c;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int th) {
        vector<pair<int,int>> adj[n];
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});    
        }
        
        
        vector<int> res(n,0);
        for(int  i = 0;i<n;i++){
           res[i] =  dij(i,n,th,adj);
        }
        
        int ans = 1e9;
        int idx = -1;
        for(int i = 0;i<n;i++){
           if(ans >= res[i]){
               idx = i;
               ans = res[i];
           }
        }
        
        return idx;
        
    }
};

     /*   int prev = pq.top().second;
        int prevDist = pq.top().first;
        pq.pop();
        
        for(auto it : adj[prev])
        {
            int next = it.first;
            int nextDist = it.second;
            if(distance[next] > distance[prev] + nextDist)
            {
                distance[next] = distance[prev] + nextDist;
                pq.push({distance[next], next});
            }
        }*/