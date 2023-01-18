class Solution {
public:
    
    // to find circular -> sum -> max -> 1. find out min subarray sum using Kadane algo and subtract it from total sum -> return max(tota - min_sum), simple max_sum from Kadanes 
    
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0,curr_mx = 0,mx_sum = nums[0],curr_mn = 0,mn_sum=nums[0];
        
        for(auto it : nums){
            curr_mx += it;
            mx_sum = max(mx_sum,curr_mx);
            if(curr_mx < 0) curr_mx = 0;
            
            total += it;
            
            curr_mn = min(curr_mn,0) + it;
            mn_sum = min(mn_sum,curr_mn);
        }
        
        return total == mn_sum ? mx_sum: max(mx_sum,total - mn_sum);
    }
};