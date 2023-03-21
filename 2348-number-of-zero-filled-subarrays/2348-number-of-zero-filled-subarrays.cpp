class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long c = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                c++;
            }else{
                c = 0;
            }
            ans += c;
        }
        return ans;
    }
};