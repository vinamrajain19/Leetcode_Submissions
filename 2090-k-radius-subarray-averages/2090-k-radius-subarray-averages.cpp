class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(),-1);
        int i = 0;
        int j = 0;
        long long sum = 0;
        int avg = 0;
        int x = k;
        while(j<nums.size()){
            sum += nums[j];
            avg = sum / (2* k +1);
            
            if(j-i+1 < 2*k+1){
                j++;
            }
            else if(j-i+1 == 2*k+1){
                ans[x] = avg;
                sum -= nums[i];
                i++;
                j++;
                x++;
            }
        }
        
        return ans;
    }
};