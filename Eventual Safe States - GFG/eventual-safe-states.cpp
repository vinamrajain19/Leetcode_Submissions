//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
          
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
    int n = V;
	vector<vector<int>> adji(n);
	vector<int> indegree(n, 0);
	
	
	// Reverse Edges of graph
	for(int i = 0;i<n;i++) {
		for(auto it : adj[i]) {
			adji[it].push_back(i);
			indegree[i]++;
		}
		
	}

	// Topo Sort
	queue<int> q;

	for(int i=0; i<n; i++) {
		if(indegree[i] == 0) q.push(i);
	}

	vector<int> safeNodes;

	while(q.size()) {
		int node = q.front(); q.pop();

		safeNodes.push_back(node);

		for(auto& adjnode : adji[node]) {
			if(--indegree[adjnode] == 0) q.push(adjnode);
		}
	}

	sort(safeNodes.begin(), safeNodes.end());

	return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends