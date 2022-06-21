class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n+1];
        for(int i = 0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        vector<int> dis(n+1,1e9);
        dis[k] = 0;
        queue<int> q;
        q.push(k);
        while(q.size() != 0){
            int x = q.front();
            q.pop();
            for(auto it : adj[x]){
                if(dis[it.first] > dis[x] + it.second){
                    dis[it.first] = dis[x] + it.second;
                    q.push(it.first);
                }
            }
        }
        
        int ans = 0;
        for(int i = 1;i<dis.size();i++){
            if(dis[i] == 1e9){
                return -1;
            }
            ans = max(ans,dis[i]);
        }
        return ans;
    }
};