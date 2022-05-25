class Solution {
public:
    void sortColors(vector<int>& nums) {
        int f =0,s=0,z=0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0) z++;
            else if(nums[i] == 1) f++;
            else s++;
        }
        nums.clear();
        for(int i = 0;i<z;i++){
            nums.push_back(0);
        }
        for(int i = 0;i<f;i++){
            nums.push_back(1);
        }
        for(int i = 0;i<s;i++){
            nums.push_back(2);
        }
        
    }
};