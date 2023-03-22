class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int maxc = 0;
        int ans = 0;
        
        unordered_map<int,int> m;
        
        while(j < s.size()){
            m[s[j]]++;
            maxc = max(maxc,m[s[j]]);
            
            while(j-i+1 - maxc > k and i < s.size()){
                m[s[i]]--;
                i++;
            }
            
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};