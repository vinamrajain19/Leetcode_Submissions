class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        while(i<nums.size()){
            int correct = nums[i];
            if(nums[i] < nums.size() && nums[i] != nums[correct]){
                swap(nums[i],nums[correct]);
            }
            else{
                i++;
            }
        }
        
        for(int k = 0;k<nums.size();k++){
            if(nums[k] != k) return k;
        }
        
        return nums.size();
    }
};