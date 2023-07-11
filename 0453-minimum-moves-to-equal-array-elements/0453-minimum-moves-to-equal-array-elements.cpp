class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = *min_element(nums.begin(),nums.end());
        
        int ans = 0;
        for(auto it : nums) ans += it - mn;
        return ans;
    }
};