class Solution {
public:
    int smallestDivisor(vector<int>& nums, int th) {
        int s = 1;
        int e = *max_element(nums.begin(),nums.end());
        
        int ans = 0;
        
        while(s <= e){
            int m = (s+e)/2;
            int cnt = 0;
            
            for(auto it : nums){
                cnt += ceil(it * 1.0 /m);
            }
            
            if(cnt <= th){
                ans = m;
                e = m-1;
            }
            else s = m+1;
            
        }
        
        return ans;
    }
};