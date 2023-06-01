class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {
        sort(it.begin(),it.end());
        vector<vector<int>> ans;
        vector<int> t = it[0];
        
        for(int i = 1;i<it.size();i++){
            
            if(t[1] < it[i][0]){
                ans.push_back(t);
                t = it[i];
            }
            else{
                t[0] = min(t[0],it[i][0]);
                t[1] = max(t[1],it[i][1]);
            }
        }
        
        ans.push_back(t);
        return ans;
    }
};