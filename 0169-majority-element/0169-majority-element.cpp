class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0;
        int e = -1;
        
        for(int i = 0;i<nums.size();i++){
            if(c == 0){
                e = nums[i];
            }
            
            if(e == nums[i]){
                c++;
            }
            else c--;
        }
        
        return e;
    }
};