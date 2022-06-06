class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        //sort to get the min and max
        sort(nums.begin(),nums.end());
        
        int ans = 1;
        int mn = nums[0];
        int mx = nums[0];
        
        for(int i = 0;i<nums.size();i++){
            mx = nums[i];
            if(mx - mn > k) {
                ans++;
                mn = nums[i];
            }
        }
        return ans;
    }
};