class Solution {
public:
    bool makeStringsEqual(string s, string t) {
        int s_sum = 0;
        int t_sum = 0;
        
        if(s.size() != t.size()) return false;
        
        for(int i = 0;i<s.size();i++){
            if(s[i] == '1') s_sum++;
            if(t[i] == '1') t_sum++;
        }
        
        if(s_sum == 0 and t_sum > 0) return false;
        else if(s_sum > 0 and t_sum == 0) return false;
        return true;
    }
};