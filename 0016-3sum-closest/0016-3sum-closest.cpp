class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0;
        int cmp = 1e9;
        
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-2;i++){
            
            int x = i + 1;
            int y = nums.size()-1;

            while(x < y){
                
                if(abs(nums[i] + nums[x] + nums[y] - target) < cmp){
                    cmp = abs(nums[i] + nums[x] + nums[y] - target);
                    ans = nums[i] + nums[x] + nums[y];
                }
                
                if(target == nums[i] + nums[x] + nums[y]){
                    return target;
                }
                else if(target > nums[i] + nums[x] + nums[y]){
                    x++;
                }
                else y--;
            }
        }
        return ans;
    }
};