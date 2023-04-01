class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        
        for(int i = 1;i<nums.size();i++){
            if(temp.back() >= nums[i]){
                int idx = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
            else{
                len++;
                temp.push_back(nums[i]);
            }
        }
        
        return len;
    }
};