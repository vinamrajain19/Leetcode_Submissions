class Solution {
public:
    bool isFive(int num) {
        while (num > 1) {
            if (num % 5 != 0) {
                return false;
            }
            num /= 5;
        }
        return num == 1;
    }
    bool is(int i, int j, string &s)
    {
        string str = s.substr(i, j + 1 - i);
        int k = 0;
        while (k < str.size())
        {
            if (str[k] == '0')
            {
                k++;
                return false;
            }
            else
                break;
        }
        int ans = 0;
        for (int i = str.size() - 1; i >= 0; --i)
        {
            if (str[i] == '1')
                ans += (1 << (str.size() - 1 - i));
        }
        return (isFive(ans));
    }
    
    
    int func(int idx, string &s, vector<int> &dp)
    {
        if (idx == s.size())
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        
        
        int min_part = 1e9;
        for (int j = idx; j < s.size(); ++j)
        {
            if (is(idx, j, s))
            {
                int cost = 1 + func(j + 1, s, dp);
                min_part = min(cost, min_part);
            }
        }
        return dp[idx] = min_part;
    }
    int minimumBeautifulSubstrings(string s) {
        vector<int> dp(s.size() + 1, -1);
        int x = func(0, s, dp);
        return x == 1e9 ? -1: x;
    }
};