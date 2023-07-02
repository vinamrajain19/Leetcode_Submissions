class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int i = 0;
        int j = 0;
        multiset<int> s;
        while(j < nums.size()){
            s.insert(nums[j]);
            
            while((*s.rbegin() - *s.begin()) > 2){
                s.erase(s.find(nums[i]));
                i++;
            }
            
            ans += j-i+1;
            j++;
        }
        
        return ans;
    }
};