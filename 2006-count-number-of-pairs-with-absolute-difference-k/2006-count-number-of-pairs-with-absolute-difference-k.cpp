class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
         unordered_map<int,int> m;
         int ans = 0;
        
        for(int i=0;i<nums.size();i++){
             ans = ans + m[k+nums[i]] + m[nums[i] - k];
             m[nums[i]]++;
        }
        
        return ans;
    }
};