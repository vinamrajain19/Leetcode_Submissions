class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> sameValueIndicesMap;
        
        for (int i = 0; i < n; i++)
            sameValueIndicesMap[arr[i]].push_back(i);
        
        vector<bool> visited(n); 
        queue<int> q; 
        q.push(0);
        visited[0] = true;
        
        int stepsTaken = -1;
        
        while (!q.empty()) {
            
            int size = q.size();
            stepsTaken++;
            while (size--) {
                
                int i = q.front(); 
                q.pop();
                // Reached to last index
                if (i == n - 1) {
                    return stepsTaken;
                }
                // get all the indices with same jump length
                vector<int>& next = sameValueIndicesMap[arr[i]];
                // we can jump to i-1 or i+1
                // we don't want to go out of bound...
                if(i-1 >=0){
                    next.push_back(i - 1);
                }
                // we don't want to go out of bound...
                if(i+1 < n){
                    next.push_back(i + 1);
                }
                // iterate for all indices
                for (int j : next) {
                    // we don't want to check the already visited indices again!
                    if (!visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear();
            }
        }
        return 0;
    }
};