class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int cr = 0;
        int cl = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'L') cl++;
            if(s[i] == 'R') cr++;
            if(cl == cr) {
                ans++;
                cl = 0;
                cr = 0;
            }
        }
        return ans;
    }
};