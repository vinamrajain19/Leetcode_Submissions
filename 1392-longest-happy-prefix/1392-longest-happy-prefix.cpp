class Solution {
public:
    
    void makelps(string &s,vector<int> &lps){
        int i = 0;
        int j = 1;
        
        while(j < s.size()){
            if(s[i] == s[j]){
                lps[j] = i+1;
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
    
    string longestPrefix(string s) {
        vector<int> lps(s.size(),0);
        makelps(s,lps);
        return s.substr(0,lps[s.size()-1]);
    }
};