class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        
        while(s < e-1){
            int m = (s+e)/2;
            
            if(m+1 < nums.size() and nums[m] > nums[m+1] and m-1 >= 0 and nums[m] > nums[m-1]){
                return m;
            }
            
            if(nums[m] <= nums[m+1]) s = m +1;
            else e = m-1;
        }
        
        return nums[s] > nums[e] ? s : e;
    }
};