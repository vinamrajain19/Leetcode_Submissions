class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0;
        while(i<nums.size()){
            int corr = nums[i] -1;
            if(nums[i] != nums[corr]){
                swap(nums[i],nums[corr]);
            }
            else i++;
        }
        
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != i + 1) ans.push_back(nums[i]);
        }
        return ans;
    }
};