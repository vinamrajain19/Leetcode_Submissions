class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        
        vector<int> o1,e1;
        vector<int> o2,e2;
        
        for(auto it : nums){
            if(it % 2 == 0) e1.push_back(it);
            else o1.push_back(it);
        }
        
        for(auto it : target){
            if(it % 2 == 0) e2.push_back(it);
            else o2.push_back(it);
        }
        
        long long ans = 0;
        
        for(int i = 0;i<e1.size();i++){
            ans += (long long) abs(e1[i] - e2[i])/2;
        }
        
        for(int i = 0;i<o1.size();i++){
            ans += (long long) abs(o1[i] - o2[i])/2;
        }
        
        return ans/2;
        
    }
};