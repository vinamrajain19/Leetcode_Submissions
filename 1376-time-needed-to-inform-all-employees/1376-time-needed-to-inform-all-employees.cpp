class Solution {
public:
    int numOfMinutes(int n, int h, vector<int>& m, vector<int>& itt) {
        vector<int> adj[n];
        
        for(int i = 0;i<n;i++){
            if(m[i] == -1) continue;
            adj[m[i]].push_back(i);
        }
        
        int ans = 0;
        
        queue<pair<int,int>> q;
        
        q.push({h,0});
        
        while(q.size()){
            int n = q.size();
            while(n--){
                int node = q.front().first;
                int time = q.front().second;
                q.pop();
                
                for(auto it :adj[node]){
                    q.push({it,time+itt[node]});
                    ans = max(ans,time+itt[node]);
                }
            }
        }
        
        return ans;
    }
};