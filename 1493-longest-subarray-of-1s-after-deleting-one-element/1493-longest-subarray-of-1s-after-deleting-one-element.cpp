class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = -1e9;
        int i = 0;
        int j = 0;
        
        int cnt = 0;
        int zero = 0;
        while(j < nums.size()){
            if(nums[j] == 1){
                cnt++;
            }
            else{
                zero++;
            }
            
            if(zero == 1){
                ans = max(ans,j-i);
            }
            
            while(zero == 2){
                if(nums[i] == 0) zero--;
                i++;
            }
            
            j++;
        }
        
        return ans == -1e9 ? cnt-1 : ans;
    }
};