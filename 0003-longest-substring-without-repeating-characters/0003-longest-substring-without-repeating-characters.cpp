class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int ans = 0;
        unordered_map<char,int> m;
        
        while(j < s.size()){
            
            if(m.find(s[j]) == m.end()){
                m[s[j]]++;
                ans = max(ans,j-i+1);
                j++;
            }
            else{
                m[s[i]]--;
                if(m[s[i]] == 0) m.erase(s[i]);
                i++;
            }
            
        }
        return ans;
    }
};