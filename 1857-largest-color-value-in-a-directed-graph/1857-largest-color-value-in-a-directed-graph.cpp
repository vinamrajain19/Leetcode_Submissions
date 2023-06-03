/* To detect cycle in directed graph use Khans Algorithm(topo sort).
Make a storage for each node that will hold Maximum count of all 26 colour till current node.
So that its neighbour will use that information to update their own maxCount of all colors. ( DP thing) */

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size(); // total nodes 
        
        unordered_map<int,vector<int>> graph; //adj. list
        vector<int> indegree(n, 0); // to count indegree of all nodes
        vector<vector<int>> maxColorCount(n, vector<int>(26, 0));
        //i.e maxColorCount[i][j] gives the max Count of color j to reach ith node
        
        //prepare the adj. list
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            graph[u].push_back(v);
            indegree[v]++;
        }
        
        
        int ans=0; //to calculate the largest color count value of a valid path
        int total=0; // to check if we can visit all nodes or not (i.e if cycle is present then we cannot) 
        queue<int> q; 
        
        //push all 0 indegree nodes
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            total++;
            
            //node=> ith node ; colors[node] -'a' => jth color
            maxColorCount[node][colors[node]-'a']++;
            ans=max(ans, maxColorCount[node][colors[node]-'a']);
            
            for(int nbr: graph[node]){
                if(--indegree[nbr]==0){
                    q.push(nbr);
                }
                
                for(int i=0;i<26;i++)
                //update the maxColorCount for each neighbour node 
                maxColorCount[nbr][i]=max(maxColorCount[node][i],  maxColorCount[nbr][i]);
            }
        }
        
        if(total!=n) return -1; // cycle detected
        
        return ans; 
    }
};