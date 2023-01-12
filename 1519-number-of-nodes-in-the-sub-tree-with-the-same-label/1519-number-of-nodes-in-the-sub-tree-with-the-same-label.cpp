class Solution {
public:
 
 // Intuition
 // If we think in terms of DFS, we need a running count of the character frequency in all the child nodes. //The only issue is that if we maintain a running count, our frequency map might contain the frequency of //all the node (including parent). So how do we solve this?

//Approach
//This can be achieved in DFS by maintaining a Pre Order count of the char frequency till current node and //subtracting it from the Post Order frequency as shown below.

    
    
    vector<int> ans;
    void dfs(vector<int> adj[],string &labels,vector<int> &freq,int node,int par){
        
        int pre = freq[labels[node] - 'a'];
        
        for(auto it: adj[node]){
            if(it == par) continue;
            freq[labels[it] - 'a']++;
            dfs(adj,labels,freq,it,node);
        }
        
        ans[node] = freq[labels[node]-'a']-pre+1;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n,0);
        vector<int> adj[n];
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> freq(26,0);
        freq[labels[0] - 'a']++;
        dfs(adj,labels,freq,0,-1);
        return ans;
    }
};