class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        
        vector<int> ans;
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            count++;
            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
             
        }
        if(count != numCourses){
            return {};
        }
        return ans;
    }
};