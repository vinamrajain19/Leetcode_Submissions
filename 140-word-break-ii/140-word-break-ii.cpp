class Solution {
public:
    vector<string> ans;
   
    void f(string &s,int idx,set<string> &d,string t){
        
        if(idx == s.size()){
            t.pop_back(); // to remove ending space otherwise space will come 
            ans.push_back(t);
            return;
        }
        
        for(int k = idx;k<s.size();k++){
            if(d.find(s.substr(idx,k-idx + 1)) != d.end()){
                f(s,k+1,d,t+s.substr(idx,k-idx+1)+" ");     
            }
        }
        
        //t.pop_back();
    }
    
    
    vector<string> wordBreak(string s, vector<string>& word) {
        set<string> d(word.begin(),word.end());
        f(s,0,d,"");
        return ans;
    }
};