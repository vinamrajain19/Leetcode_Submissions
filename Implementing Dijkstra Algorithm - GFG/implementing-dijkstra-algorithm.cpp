// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
      
      // priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	
	vector<int> distTo(V+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	queue<int> pq;
	distTo[S] = 0;
	pq.push(S);	// (dist,from)
	
	while( !pq.empty() ){
		int node = pq.front();
		pq.pop();
		
		
		for(auto it : adj[node]){
			int next = it[0];
			int nextDist = it[1];
			if( distTo[next] > distTo[node] + nextDist){
				distTo[next] = distTo[node] + nextDist;
				pq.push(it[0]);
			}
		}
		
	}
	return distTo;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends