class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 1) return nums[0] == target;
        
        int s = 0;
        int e = nums.size()-1;
        
        while(s <= e){
            
            while(s+1 < nums.size() and nums[s] == nums[s+1]) s++;
            while(e-1 >= 0 and nums[e] == nums[e-1]) e--;
            
            
            int m = (s+e)/2;
            
            if(nums[m] == target) return true;
            
            if(nums[m] >= nums[s]){
                if(nums[s] <= target and nums[m] > target) e = m-1;
                else s = m +1;
            }
            else {
                if(nums[m] < target and nums[e] >= target) s = m+1;
                else e = m-1;
            }
        }
        return false;        
    }
};