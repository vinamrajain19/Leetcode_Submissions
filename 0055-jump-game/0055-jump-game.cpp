class Solution {
public:
    bool canJump(vector<int>& nums) {
        int can = 0;
        for(int i = 0;i<nums.size();i++){
            if(i > can) return false;
            can = max(can,i+nums[i]);
            if(can >= nums.size()-1) return true;
        }
        
        return true;
    }
};