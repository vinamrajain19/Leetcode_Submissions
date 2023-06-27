class Solution {
public:
   
    int rank(vector<int>& nums, int dis) {
        int count=0, lo=0, hi=1;
        while(hi<nums.size()) {
            while(nums[hi]-nums[lo] > dis)
                lo++;
            count += hi-lo;
            hi++;
        }
        return count;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int left=0, right=nums[nums.size()-1]-nums[0];
        while(left<right) {
            int mid=left+(right-left)/2;
            if(rank(nums, mid) < k)
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
};