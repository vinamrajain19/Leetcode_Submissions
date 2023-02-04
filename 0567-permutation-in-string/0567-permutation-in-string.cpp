class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> m;
        for(auto it: s1) m[it]++;
        int c = m.size();
        int i = 0;
        int j = 0;
 
        while(j<s2.size()){
            if(m.find(s2[j]) != m.end()){
                m[s2[j]]--;
                if(m[s2[j]] == 0) c--;
                
            }
            if(j-i+1 == s1.size()){
                if(c == 0) return true;
                if(c != 0){
                    if(m.find(s2[i]) != m.end()){
                        m[s2[i]]++;
                        if(m[s2[i]] == 1) c++;
                    }
                }
                i++;
            }
            j++;
        }
        return false;
    }
};