//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        vector<int> ans(N,1e9);

        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        ans[0] = 0;
        pq.push({0,0});
        
        while(pq.size()){
            int dis = pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto it : adj[node]){
                if(it.second + ans[node] < ans[it.first]){
                    ans[it.first] = it.second + ans[node];
                    pq.push({ans[it.first],it.first});
                }
            }
        }
        
        for(int i = 0;i<N;i++){
            if(ans[i] == 1e9) ans[i] = -1;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends