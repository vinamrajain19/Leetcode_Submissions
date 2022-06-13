class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char,int> m;
        for(int i = 0;i<s.size();i++){
            m[s[i]]++;
        }
        
        int ans = 0;
        bool odd = false;
        for(auto &it:m){
            if(it.second % 2 == 0){
                ans += it.second;
            }
            else{
                ans += it.second - 1;
                odd = true;
            }
        }
        if(odd) return ans+1;
        return ans;
        
    }
};