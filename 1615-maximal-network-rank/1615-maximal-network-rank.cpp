class Solution {
public:
    int max(int a,int b){
        return a > b ? a : b;
    }
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if(roads.size() == 0) return 0;
           
        vector<unordered_set<int>> s(n);
        for(int i = 0;i<roads.size();i++){
          int x = roads[i][0];
            int y = roads[i][1];
            
            s[x].insert(y);
            s[y].insert(x);
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++){
           for(int j = i + 1;j<n;j++){
               if(s[i].find(j) != s[i].end()){
                   ans = max(ans, s[i].size() + s[j].size() - 1);
               }
               else {
                   ans = max(ans,s[i].size() + s[j].size());
               }
           }
        }
        
        return ans;
    }
};