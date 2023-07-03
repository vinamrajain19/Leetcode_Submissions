class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        unordered_set<int> s;
        
        for(auto it : nums) s.insert(it);
        
        int mx = 0;
        
        for(int i = 0;i<nums.size();i++){
            if(s.count(nums[i] - 1) == 0){
                
                int no = nums[i];
                int cnt = 0;
                
                while(s.count(no)){
                    cnt++;
                    no++;
                }
                
                 mx = max(mx,cnt);
            }
            
           
        }
        
        return mx;
    }
};