class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        while(s<e){
            if(nums[s]  + nums[e] == target){
                return {s+1,e+1};
            } 
            else if(nums[s] + nums[e] < target){
                s++;
            }
            else e--;
        }
        return {-1,-1};
    }
};