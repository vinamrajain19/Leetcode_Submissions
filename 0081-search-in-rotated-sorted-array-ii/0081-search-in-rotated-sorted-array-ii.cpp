class Solution {
public:
    bool search(vector<int>& nums, int t) {
        int s = 0;
        int e = nums.size()-1;
        
        
        while(s <= e){
            
             while (s < e && nums[s] == nums[s + 1])
                ++s;
             while (s < e && nums[e] == nums[e - 1])
                --e;
            
            int m = (s+e)/2;
            
            if(nums[m] == t) return true;
            
            if(nums[s] <= nums[m]){
                if(nums[s] <= t and nums[m] >= t){
                    e = m -1;
                }
                else s = m+1;
            }
            else{
                if(nums[m] <= t and nums[e] >= t) s = m +1;
                else e = m-1;
            }
        }
        
        return false;
    }
};