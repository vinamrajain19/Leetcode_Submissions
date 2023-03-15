class Solution {
public:
    
    // brute force -> generate all premuatation sort them and return ans[k-1] -> T.C = O(n*n!)
    
  /*  vector<string> ans;
    void f(string s,int idx){
        if(idx == s.size()){
            ans.push_back(s);
            return;
        }
        
        for(int i = idx;i<s.size();i++){
            swap(s[i],s[idx]);
            f(s,idx+1);
            swap(s[i],s[idx]);
        }
        
    } */
    /* string getPermutation(int n, int k) {
        string s = "";
        for(int i = 1;i<=n;i++){
            s += to_string(i);
        }
        f(s,0);
        sort(ans.begin(),ans.end());
        return ans[k-1];
    } */
    
    
    // optimal approach is find fact of n-1 -> 1st no is k-1/ fact -> then k = k % fact; and fact = fact / nums./size()
    // T.C = O(N^2) -> O(n) will be op of n no and O(n) will be we are erasing no in vector and then for n-1
    
    string getPermutation(int n, int k) {
        
        vector<int> nums;
        int fact = 1;
        
        for(int i = 1;i<n;i++){
            nums.push_back(i);
            fact *= i;
        }
        
        nums.push_back(n);
        
        k = k-1;
        string ans = "";
        
        while(true){
            ans += to_string(nums[k/fact]);
            
            //erase that no
            nums.erase(nums.begin() + k/fact);
            
            if(nums.size() == 0) break;
            
            k = k % fact;
            fact /= nums.size();
        }
        
        return ans;
    }
};