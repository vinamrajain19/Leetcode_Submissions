class Solution {
public:
    
    vector<vector<int>> ans;
    set<vector<int>> s;
    
    void f(int k,int n,vector<int> &t,int ind){
        if(n == 0 and t.size() == k){
            s.insert(t);
            return;
        }
        
        
        for(int i = ind;i<=9;i++){
            if(n - i >= 0){
                t.push_back(i);
                f(k,n-i,t,i+1);
                t.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> t;
        f(k,n,t,1);
        for(auto it : s){
            ans.push_back(it);
        }
        return ans;
    }
};