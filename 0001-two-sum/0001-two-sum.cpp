class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            if(m.find(t-nums[i]) != m.end()) return {i,m[t-nums[i]]};
            m[nums[i]] = i;
        }
        
        return {};
    }
};