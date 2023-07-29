class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> m;
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                
                int t = nums[i] * nums[j];
                
                if(m.find(t) == m.end()){
                    m[t] = 1;
                }
                else{
                    
                    ans += m[t] * 8;
                    m[t]++;
                }
            }
        }
        return ans;
    }
};