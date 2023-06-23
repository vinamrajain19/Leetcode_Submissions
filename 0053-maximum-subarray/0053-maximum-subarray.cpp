class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9;
        int sum = 0;
        for(auto it : nums){
            sum += it;
            ans = max(ans,sum);
            if(sum < 0) sum = 0;
        }
        return ans;
    }
};