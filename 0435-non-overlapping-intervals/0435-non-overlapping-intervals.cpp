class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
     return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& it) {
        int ans = 0;
        sort(it.begin(),it.end(),cmp);
        
        int last = it[0][1];
        
        for(int i =1;i<it.size();i++){
            if(it[i][0] < last){
                ans++;
            }
            else last = it[i][1];
        }
        return ans;
    }
};