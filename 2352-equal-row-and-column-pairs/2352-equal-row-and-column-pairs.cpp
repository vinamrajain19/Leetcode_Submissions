class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int> ,int> m;
        int n = grid.size();
        for(int i = 0;i<n;i++){  
            m[grid[i]]++;
        }
        
        int ans =0;
        for(int i = 0;i<n;i++){
            vector<int> t;
            for(int j = 0;j<n;j++){
                t.push_back(grid[j][i]);
            }
            if(m.find(t) != m.end()){
                ans += m[t];
            }
        }
        return ans;
    }
};