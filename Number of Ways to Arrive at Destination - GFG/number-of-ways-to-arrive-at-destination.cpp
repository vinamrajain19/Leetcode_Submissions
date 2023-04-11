//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int countpaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        
        vector<vector<pair<int, int>>> graph(n);
        for(auto &road: roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }
        
        vector<long long> distance(n, LONG_MAX);
        vector<int> path(n, 0);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        distance[0] = 0;
        path[0] = 1;
        
        while(!pq.empty()) {
            pair<long long, int> t = pq.top();
            pq.pop();
            
            for(auto &nbr: graph[t.second]) {
                long long vert = nbr.first;
                long long edge = nbr.second;
                
                if(distance[vert] > distance[t.second] + edge) {
                    distance[vert] = distance[t.second] + edge;
                    pq.push({distance[vert], vert});
                    path[vert] = path[t.second] %mod;
                }
                else if(distance[vert] == t.first + edge) {
                    path[vert] += path[t.second];
                    path[vert] %= mod;
                }
            }
        }
        
        return path[n-1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        return countpaths(n,roads);
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends