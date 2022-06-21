class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int end) {
        vector<pair<int,double>> adj[n];
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
            
        }
        
        
        vector<double> prob(n,0.0);
        prob[src] = 1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,src});
        
        while(pq.size() != 0){
            auto [x,d] = pq.top();
            pq.pop();
            
            for(auto it : adj[d]){
                if(prob[it.first] < (x* it.second)) {
                    prob[it.first] = x * it.second;
                    pq.push({prob[it.first],it.first});
                }
            }
        }
        
        return prob[end];
    }
};