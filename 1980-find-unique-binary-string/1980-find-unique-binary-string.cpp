class Solution {
public:
    string ans;
    void f(int idx,string st,int n,unordered_set<string> &s){
        if(idx == n){
            if(s.find(st) == s.end()){
                ans = st;
                return;
            }
            return;
        }
        
        f(idx+1,st+"1",n,s);
        f(idx+1,st+"0",n,s);
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> s(nums.begin(),nums.end());
        f(0,"",nums.size(),s);
        return ans;
    }
};