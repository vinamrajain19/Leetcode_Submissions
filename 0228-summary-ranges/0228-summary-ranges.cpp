class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        
        
        for (int i = 0; i < n; i++) {
            
            int begin = nums[i];
            
            while (i +1 < n and nums[i]+1 == nums[i + 1]) i++;
            
            int end = nums[i];
            
            if (begin == end)  ans.push_back(to_string(begin));
            else ans.push_back(to_string(begin)  + "->" + to_string(nums[i])); 
        }
        
        return ans;
    }
};