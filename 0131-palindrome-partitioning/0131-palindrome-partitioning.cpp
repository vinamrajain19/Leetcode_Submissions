class Solution {
public:
    
    vector<vector<string>> ans;
    
    bool is(string t){
        string x =t;
        reverse(x.begin(),x.end());
        return x == t;
    }
    
    void f(string s,int idx,vector<string> &path){
        if(idx >= s.size()){
            ans.push_back(path);
            return;
        }
        
        string t = "";
        
        for(int i = idx;i<s.size();i++){
            t = s.substr(idx,i-idx+1);
            if(is(t)){
                path.push_back(t);
                f(s,i+1,path);
                path.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<string> v;
        f(s,0,v);
        return ans;
    }
};