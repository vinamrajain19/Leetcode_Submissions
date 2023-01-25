class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
       int n = nums1.size();

            if(k == 0) return nums1 == nums2 ? 0 : -1;
            
            long long posDiff = 0;
            long long negDiff = 0;
            
            for(int idx = 0; idx < n; ++idx) {
                int diff = abs(nums1[idx] - nums2[idx]);
                if(diff % k != 0) return -1;
                if(nums1[idx] > nums2[idx]) posDiff += diff / k;
                else negDiff += diff / k;
            }

            return posDiff == negDiff ? posDiff : -1;
    }
};