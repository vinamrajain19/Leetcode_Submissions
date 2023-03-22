class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            
            if(m.find(sum - goal) != m.end()){
                ans += m[sum-goal];
            }
            
            m[sum]++;
        }
        
        return ans;
    }
};