class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        map<int, map<int, int>> adj;
        // Making the graph //
        for(auto edge : edges){
            adj[edge[0]][edge[1]] = adj[edge[1]][edge[0]] = 1;
        }

        
        vector<int> o(n+1,0);
        
        for(auto it : edges){
            o[it[0]]++;
            o[it[1]]++;
        }
        
        vector<int> even,odd;
        for(int i =1;i<=n;i++){
            if(o[i] %2 == 0) even.push_back(i);
            else odd.push_back(i);
        }
        
        if(odd.size() == 0) return true;
        if(odd.size() > 4 or odd.size() == 1 or odd.size() == 3) return false;
        
        if(odd.size() == 2){
            // how -> 1. we can cannect both odd 
            if(adj[odd[0]][odd[1]] == 0) return true;
            
            // if both odd are already connected  -> we can add even node with both of them 
            for(auto it : even){
                if(adj[it][odd[0]] == 0 and adj[it][odd[1]] == 0) return true;
            }
        }

        //for count=4, we can have only 3 following possibilities to add edges
        // [0->1 (2->3) ... 0->2 (1->3) ... 0->3 (2->1)]
        if(odd.size() == 4){
            if(adj[odd[0]][odd[1]] == 0 and adj[odd[2]][odd[3]] == 0) return true;
            if(adj[odd[0]][odd[2]] == 0 and adj[odd[1]][odd[3]] == 0) return true;
            if(adj[odd[0]][odd[3]] == 0 and adj[odd[1]][odd[2]] == 0) return true;
        }

        return false;
                
    
    }
};