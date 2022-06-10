class Solution {
public:
    int myAtoi(string s) {
        stringstream ss;
        int ans = 0;
        ss << s;
        ss >> ans;
        return ans;
    }
};