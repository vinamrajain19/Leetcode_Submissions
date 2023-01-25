class Solution {
public:
    void bfs(int src,vector<int> &dis,vector<int> adj[]){
        queue<int> q;
        q.push(src);
        dis[src] = 0;
        while(q.size()){
            int t = q.front();
            q.pop();
            for(auto it : adj[t]){
                if(dis[it] == 1e9){
                    dis[it] = dis[t] + 1;
                    q.push(it);
                }
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> adj[edges.size()];
        for(int i = 0;i<edges.size();i++){
            if(edges[i] !=  -1)
              adj[i].push_back(edges[i]);
        }
        
        vector<int> dis1(n,1e9);
        vector<int> dis2(n,1e9);
        bfs(node1,dis1,adj);
        bfs(node2,dis2,adj);
        
        int ans = -1;
        int mx = 1e9;
        for(int i = 0;i<n;i++){
            
            if(dis1[i] == 1e9 or dis2[i] == 1e9) continue;
            if(mx > max(dis1[i],dis2[i])){
                ans = i;
                mx = max(dis1[i],dis2[i]);
            }
        }
        if(ans == -1) return -1;
        return ans;
        
    }
};