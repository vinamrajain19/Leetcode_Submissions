class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int,set<int>> m;
        for(auto it : logs){
            m[it[0]].insert(it[1]);
        }
        
        vector<int> ans(k,0);
        for(auto it : m){
            int x = it.second.size();
            ans[x-1]++;
        }
        
        return ans;
    }
};

