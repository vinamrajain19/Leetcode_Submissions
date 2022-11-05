class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        
        while(i<nums.size()){
            int c = nums[i] - 1;
            if(nums[c] != nums[i]) swap(nums[i],nums[c]);
            else i++;
        }
        
        for(int j = 0;j<nums.size();j++){
            if(nums[j] != j+1) return nums[j];
        }
        return -1;
    }
};