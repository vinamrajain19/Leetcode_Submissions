class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& arr) {
        map<int,int> m;
        for(int i = 0;i<arr.size();i++){
            m[arr[i][0]] = i;
        }
        vector<int> ans(arr.size(),0);
        for(int i=0;i<arr.size();i++){
            auto s = m.lower_bound(arr[i][1]);
            if(s == m.end()){
                ans[i] = -1;
            }
            else{
                ans[i] = s->second;
            }
        }
        return ans;
    }
};