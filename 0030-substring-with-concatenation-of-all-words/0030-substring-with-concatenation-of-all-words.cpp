class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> m;
        for(auto it : words){
            m[it]++;
        }
       
        vector<int> ans;
        int len = words.size() * words[0].size();
        int l = words[0].size();
     
        int j = 0;
        int i = 0;
        string t = "";
        for(int j = 0;j<s.size()-len+1;j++){
            
                unordered_map<string,int> tmp;
                t  = s.substr(j,len);
                for(int k = 0;k<t.size()-l+1;k+=l){
                    string a = t.substr(k,l);
                    tmp[a]++;
                }
                if(m == tmp) ans.push_back(j);
        }
        return ans;
    }
};