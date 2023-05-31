class Solution {
public:
    
    // T.C = (2^t * k) -> t == target and k == avg length of t vector
    // S.C = (x*k) x-> total comb an k -> length of comb
    
    vector<vector<int>> ans;
    
    void f(vector<int> &c,int target,int idx,vector<int> t){
        if(target == 0){
            ans.push_back(t);
            return;
        }
        if(idx >= c.size() or target < 0) return;
        
        if(c[idx] <= target){
            t.push_back(c[idx]);
            f(c,target-c[idx],idx,t);
            t.pop_back();
        }
        f(c,target,idx+1,t);
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<int> t;
        f(c,target,0,t);
        return ans;
    }
};