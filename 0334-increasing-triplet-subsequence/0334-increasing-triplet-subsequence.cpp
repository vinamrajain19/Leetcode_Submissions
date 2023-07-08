class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = 1;
        vector<int> t;
        t.push_back(nums[0]);
        
        for(int i = 1;i<nums.size();i++){
            if(nums[i] > t.back()){
                t.push_back(nums[i]);
                len++;
            }
            else{
                int id = lower_bound(t.begin(),t.end(),nums[i]) - t.begin();
                t[id] = nums[i];
            }
        }
        return len>=3;
    }
};