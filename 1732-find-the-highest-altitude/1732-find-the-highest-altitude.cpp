class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int last = 0;
        int ans = 0;
        for(int i = 0;i<gain.size();i++){
            ans = max(ans,last + gain[i]);
            last += gain[i];
        }
        return ans;
    }
};