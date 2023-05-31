class Solution {
public:
    
    // T.C = O((2^n) * k)
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,arr,ans,0);
       
        return ans;
    }
    
    void helper(vector<int> &candidates,int target,vector<int> &arr,vector<vector<int>> &ans,int idx){
        if(target < 0){
            return;
        }
        
        if(target == 0){
            ans.push_back(arr);
            return;
        }
        
        for(int i=idx;i<candidates.size();i++){
            if(i>idx and candidates[i] == candidates[i-1]) continue;
            arr.push_back(candidates[i]);
            helper(candidates,target-candidates[i],arr,ans,i+1);
            arr.pop_back(); // backtrack
        }
    }
};