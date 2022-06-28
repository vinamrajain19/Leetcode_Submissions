class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<unordered_set<int>> s(n+1,unordered_set<int>());
        
        for(int i = 0;i < trust.size();i++){
            s[trust[i][0]].insert(trust[i][1]);
        }
        
        int ans = -1;
        for(int i = 1;i<=n;++i){
            if(s[i].size() == 0){
                ans  = i;
                break;
            } 
        }
        
        if(ans == -1) return -1;
        
        for(int i = 1;i<=n;++i){
            if(i == ans) continue;
            if(s[i].count(ans) == 0) return -1;
        }
        return ans;
              
    }
};

