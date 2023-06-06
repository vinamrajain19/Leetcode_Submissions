class Solution {
public:
    
    // This problem asks us to add string before the input so the result string will be a palindrome.
// We can convert it to an alternative problem"find the longest palindrome substring starts from index 0".
// If we can get the length of such substring, then we can easily build a palindrome string by inserting // the reverse part of substring after such substring before the original string.
    
    void makelps(string &s,vector<int> &lps){
        int i = 0;
        int j = 1;
        
        while(j < s.size()){
            if(s[i] == s[j]){
                lps[j] = i + 1;
                i++;
                j++;
            }
            else{
                if(i != 0){
                    i = lps[i-1];
                }
                else j++;
            }
        }
    }
    
    string shortestPalindrome(string s) {
        string rev = string(s.rbegin(),s.rend());
        
        string temp = s + "*" + rev;
        
        vector<int> lps(temp.size(),0);
        makelps(temp,lps);
        
        // added string + s
        string ans = rev.substr(0,s.size() - lps[lps.size()-1]) + s;
        return ans;
    }
};