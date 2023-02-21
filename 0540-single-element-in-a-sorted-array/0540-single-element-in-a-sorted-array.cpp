class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
       if(nums.size()==1) return nums[0];
        //  two pointer 
        while(s<=e){
            if(nums[s] == nums[s+1]){
                s = s+2;
            }
            else{
                return nums[s];
            }
            
            if(nums[e] == nums[e-1]){
                 e = e-2;
            }
            else{
                return nums[e];
            }
        }
        
        return -1;
    }
};