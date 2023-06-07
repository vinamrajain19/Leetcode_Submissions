class Solution {
public:
    
    vector<vector<int>> ans;
    
    void f(vector<int> &nums,int idx,vector<int> &t){
        if(idx == nums.size()){
            ans.push_back(t);
            return;
        }
        
        for(int i = idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            f(nums,idx+1,t);
            swap(nums[idx],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        f(nums,0,nums);
        return ans;
    }
};