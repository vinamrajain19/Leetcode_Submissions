class Solution {
public:
    bool canJump(vector<int>& nums) {
        int can =  0;
        int n = nums.size();
        if(n<=1) return true;
        for(int i = 0;i<n;i++){
            can  = max(can,i + nums[i]);
            
            if(can  == i) return false;
            else if(can >= n-1) return true;
        }
        return true;
    }
};