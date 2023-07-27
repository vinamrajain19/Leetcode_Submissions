class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
         deque<int> maxdq, mindq;
        int j = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!maxdq.empty() && nums[i] > maxdq.back()) maxdq.pop_back();
            while (!mindq.empty() && nums[i] < mindq.back()) mindq.pop_back();
            maxdq.push_back(nums[i]);
            mindq.push_back(nums[i]);
            while (maxdq.front() - mindq.front() > limit) {
                if (maxdq.front() == nums[j]) maxdq.pop_front();
                if (mindq.front() == nums[j]) mindq.pop_front();
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};