class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        
        int i = 0;
        int j = 0;
        
        int x = 0;
        while(j < nums.size()){
            
            while((nums[j] & x) != 0){
                x = x ^ nums[i];
                i++;
            }
               
            x = x | nums[j];
            
            ans = max(ans,j-i+1);
            
            j++;
        }
        
        return ans;
        
    }
};