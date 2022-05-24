class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans2;
        for(int i = 0;i<n;i++){
            vector<int> ans(i+1,1);
            for(int j = 1;j<i;j++){
                ans[j] = ans2[i-1][j]+ans2[i-1][j-1];
            }
            ans2.push_back(ans);
        }
        return ans2;
    }
};