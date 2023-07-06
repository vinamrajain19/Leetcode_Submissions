class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1e9;
        
        int i = 0;
        int j = 0;
        int sum = 0;
        
        while(j < nums.size()){
            sum += nums[j];
            
            while(sum >= target and i < nums.size()){
                sum -= nums[i];
                ans = min(ans,j-i+1);
                i++;
            }

            j++;

        }
        return ans == 1e9 ? 0 : ans;
    }
};