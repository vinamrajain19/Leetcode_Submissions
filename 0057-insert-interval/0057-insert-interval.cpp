class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& it, vector<int>& n) {
        vector<vector<int>> ans;
        
        for(int i = 0;i<it.size();i++){
            
            if(it[i][0] > n[1]){
                ans.push_back(n);
                n = it[i];
            }
            
            else if(it[i][1] < n[0]){
               ans.push_back(it[i]); 
            }
            else if(it[i][1] >= n[0] or it[i][0] <= n[1]){
                n[0] = min(n[0],it[i][0]);
                n[1] = max(n[1],it[i][1]);
            }
        }
        
        ans.push_back(n);
        return ans;
    }
};