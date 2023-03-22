class Solution {
public:
    
    int f(vector<int> &nums,int k){
        unordered_map<int,int> m;
        
        int i = 0;
        int j = 0;
        int ans = 0;
        
        while( j < nums.size() ){
            m[nums[j]]++;
            
                while(m.size() > k and i < nums.size()){
                    //ans += j-i+1;
                    m[nums[i]]--;
                    if(m[nums[i]] == 0) m.erase(nums[i]);
                    i++;
                }
            
                ans += j-i+1;
                j++;
            
        }
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return f(nums,k) - f(nums,k-1);
    }
};