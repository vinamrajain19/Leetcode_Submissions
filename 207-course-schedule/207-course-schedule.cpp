class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create adj list
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> indeg(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it : adj[i]){
                indeg[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        int res = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res++;
            
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        
        return res == numCourses;
    }
};