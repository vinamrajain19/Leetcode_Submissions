class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int mx = -1e9;
        int ans= 0;
        
        while(j < nums.size()){
            if(nums[j] == 0){
                k--;
            }
            
            while(k < 0 and  i < nums.size()){
                if(nums[i] == 0) k++;
                i++;
            }
            
            mx = max(mx,j-i+1);
            j++;
        }
        
        return mx;
    }
};