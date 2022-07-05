class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        
        sort(nums.begin(),nums.end());
        int ans = 1;
        int c = 1;
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i+1] - nums[i] == 1){
                c++;
            }
            else if(nums[i+1] == nums[i]) continue; // dulpicate no change
            else{
                c = 1;
            }
            
            ans = max(ans,c);
        }
        return ans;
    }
};