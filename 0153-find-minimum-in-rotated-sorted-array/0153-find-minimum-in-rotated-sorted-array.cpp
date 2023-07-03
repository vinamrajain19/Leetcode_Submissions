class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        
        while(s < e){
            int m = (s+e)/2;
            
            if(nums[m] > nums[e]){
                s = m + 1;
            }
            else e = m;
        }
        
        return nums[s];
    }
};