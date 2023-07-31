class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        if(nums.size() == 1) return 1;
        
        sort(nums.begin(),nums.end());
        long long int i = 0;
        long long int j = 1;
        long long int diff = 0;
        
        int ans = 0;
        
        while(j<nums.size()){
            
            diff += (nums[j] - nums[j-1]) * (j-i);
            
            if(diff > k){
                diff -= (nums[j] - nums[i]);
                i++;
            }
            
          
            j++;
        }
        return j-i;
    }
};