class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto it : nums) m[it]++;
        int ans = 0;
        
        for(auto it : m){
            if(k == 0){
                if(it.second > 1) ans += 1;
            }
            else ans += m.count(it.first-k);
        }
        
        return ans;
    }
};