class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    
    void f(vector<int> &nums,vector<int> temp,int idx,int prev){
        if(idx >= nums.size()){
            if(temp.size() >= 2) s.insert(temp);
            return;
        }
        
        if(temp.size() >= 2){
            s.insert(temp);
        }
        
        if(prev == -1 or nums[prev] <= nums[idx]){
            temp.push_back(nums[idx]);
            f(nums,temp,idx+1,idx);
            temp.pop_back();
            f(nums,temp,idx+1,prev);
        }
        else f(nums,temp,idx+1,prev);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        f(nums,{},0,-1);
        for(auto it: s) ans.push_back(it);
        return ans;
    }
};