class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> in(n,0);
        vector<int> adj[n];
        
        for(auto it : p){
            adj[it[1]].push_back(it[0]);
            in[it[0]]++;
        }
        
        
        queue<int> q;
        for(int i = 0;i<n;i++){
            if(in[i] == 0) q.push(i);
        }
        
        int cnt = 0;
        while(q.size()){
            int t = q.front();
            q.pop();
            
            cnt++;
            
            for(auto it : adj[t]){
                in[it]--;
                if(in[it] == 0) q.push(it);
            }
        }
        
        return cnt == n;
        
    }
};