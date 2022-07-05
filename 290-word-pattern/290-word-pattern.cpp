class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        vector<string> v;
        int i = 0;
		string temp = "";
		while(i < s.size()){
			if(s[i] == ' '){
				v.push_back(temp);
				temp = "";
			}
			else{
				temp += s[i];
			}
			i++;
		}
		v.push_back(temp);
        
        if(v.size() != pattern.size()) return false;
        
        set<string> st;
        for(int i = 0;i<pattern.size();i++){
            if(m.find(pattern[i]) != m.end()){
                if(m[pattern[i]] != v[i]) return false;
            }
            else{
                if(st.count(v[i])) return false;
                st.insert(v[i]);
                m[pattern[i]] = v[i];
            }
         
        }
        return true;
    }
};