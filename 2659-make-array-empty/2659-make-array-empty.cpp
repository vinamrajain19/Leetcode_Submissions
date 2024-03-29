class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        unordered_map<int, int> m;
        
        long long n = nums.size(), res = n;
        
        for (int i = 0; i < n; ++i) m[nums[i]] = i;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < n; ++i)
            if (m[nums[i]] < m[nums[i - 1]])
                res += n - i;
        return res;
        
    }
};