class Solution {
public:
    
    int getDistance(vector<int>& v1, vector<int>& v2) {
        return abs(abs(v1[0]-v2[0]) + abs(v1[1]-v2[1]));
    }
    
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        
        int N = points.size();
        
        vector<vector<pair<int, int>>> graph(points.size());
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                graph[i].push_back({j, getDistance(points[i], points[j])});
                graph[j].push_back({i, getDistance(points[i], points[j])});
                
            }
        }
        
      
        vector<int> key(N,INT_MAX);
        vector<bool> mstSet(N,false);
    
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

        key[0] = 0; 
        pq.push({0, 0});
        
        while(!pq.empty())
        {    
            int u = pq.top().second; 
            pq.pop(); 
        
            mstSet[u] = true; 
        
            for (auto it : graph[u]) {
                int v = it.first;
                int weight = it.second;
                if (mstSet[v] == false && weight < key[v]) {
    		        key[v] = weight; 
                    pq.push({key[v], v});    
                }
            }
            
        }
        
        int sum = 0;
        for(int i=0;i<N;i++){
            sum += key[i];
        }
        return sum;
    }
};