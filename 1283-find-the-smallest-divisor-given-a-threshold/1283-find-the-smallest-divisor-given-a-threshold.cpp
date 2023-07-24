class Solution {
public:
    int smallestDivisor(vector<int>& nums, int th) {
        sort(nums.begin(),nums.end());
        int s = 1;
        int e = (int)1e6;
        
        int ans= 0;
        while(s<=e){
            int mid = (s+e)/2;
            int sum = 0;
            
            for(auto i : nums){
                if(i % mid == 0) sum += i / mid;
                else sum += (i / mid) + 1;
            }
            
            if(sum <= th){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};