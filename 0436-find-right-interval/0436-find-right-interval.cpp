class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> ans(n,-1);
        map<int,int> dict;
        
        for (int i = n-1; i >= 0; i--) dict[A[i][0]] = i;
        
        for (int i = 0; i < n; i++) {
            auto iter = dict.lower_bound(A[i][1]);
            if (iter != dict.end()) ans[i] = iter->second;
        }
        return ans;
    }
};