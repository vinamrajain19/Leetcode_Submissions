class Solution {
public:
    bool ispalind(string &s,int i,int j){
        while(i<j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    void f(string s,vector<vector<string>> &ans,vector<string> &path,int i){
        
        if(i == s.size()){
            ans.push_back(path);
            return;
        }
            
        for(int k = i;k<s.size();k++){
            
            if(ispalind(s,i,k)){
                path.push_back(s.substr(i,k-i+1));
                f(s,ans,path,k+1);
                path.pop_back();
            }
        }        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        f(s,ans,path,0);
        return ans;
    }
};