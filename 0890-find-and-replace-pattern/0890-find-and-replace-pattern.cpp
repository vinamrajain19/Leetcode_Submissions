class Solution {
public:
    
    bool f(vector<string>& v, string pattern,int idx){
        unordered_map<char,char> m;
        set<char> st;
        for(int i = 0;i<pattern.size();i++){
            if(m.find(pattern[i]) != m.end()){
                if(m[pattern[i]] != v[idx][i]) return false;
            }
            else{
                if(st.count(v[idx][i])) return false;
                st.insert(v[idx][i]);
                m[pattern[i]] = v[idx][i];
            }
         
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        
        for(int i = 0;i<words.size();i++){
            if(f(words,pattern,i)){
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
};