class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int s = 0;
        int e = nums.size()-1;
        
        while(s <= e){
            int m = (s+e)/2;
            
            if(target == nums[m]) return m;
            
            if(nums[s] <= nums[m]){
                if(nums[s] <= target and nums[m] >= target) e = m-1;
                else s = m+1;
            }
            else{
                if(nums[m] <= target and nums[e] >= target) s = m+1;
                else e = m-1;
            }
        }
        
        return -1;
    }
};