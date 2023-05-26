class Solution {
public:
    
   

    int dp[101];

    int f(string& s, int i) {
        // base case
        if (i >= s.length()) return 1;

        if (dp[i] != -1) return dp[i];

        int ans = 0;
        // we want to check atmost 2 characters because,
        // the max value we are looking for is 26. Hence a loop is not required.
        if (s[i] == '0') {
            ans = 0;
        } else {
            // check for single digit
            ans += f(s, i + 1);
            // check for 2 digits
            if (i + 1 < s.length() && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                ans += f(s, i + 2);
            }
        }
        return dp[i] = ans;
    }


    
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return f(s,0);
    }
};