class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
       /* int cnt2 = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != 0){
                nums[cnt2] = nums[i];
                cnt2++;
            }
        }
        for(int i = cnt2;i<nums.size();i++){
            nums[i] = 0;
        } */
        
        // two pointer method
        
        int l = 0;
        int h = 0;
        while(h<nums.size()){
            if(nums[h] != 0){
                swap(nums[h],nums[l]);
                l++;
            }
            h++;
        }
    }
};